# What happens in memory when you run a C++ program — step-by-step, with an example

Short version: when you run a C++ program the OS creates a process with a virtual address space made of several logical segments. Code, read-only constants, initialized globals, uninitialized globals, the heap, and the stack are laid out in that address space. The loader maps the executable + shared libraries and sets up the stack (argc/argv/envp). At runtime the program uses the stack for function frames, the heap for dynamic allocations, and globals/static storage for program-lifetime variables. When the process exits the kernel reclaims all those pages.

Below I’ll show a compact example program and then show exactly where each variable ends up (with plausible example addresses and contents) and step-by-step runtime events.

---

# Example program

```cpp
#include <iostream>

int global_init = 42;          // initialized global -> data segment
int global_uninit;             // uninitialized global -> bss segment
static int static_init = 100;  // initialized static -> data segment
const char* greeting = "hi";   // pointer in data/rodata; string literal in RO data

int main(int argc, char** argv) {
    int local = 5;             // stack
    static int local_static = 7; // static lifetime -> data segment
    int* p = new int(11);      // heap
    std::cout << local << " " << *p << " " << greeting << "\n";
    delete p;
    return 0;
}
```

---

# Memory segments (conceptual)

* **Text (code)** — executable instructions (usually read+execute). Example base: `0x00400000`.
* **Read-Only data (rodata)** — string literals and const data. Example base: `0x00600000`.
* **Data (initialized data)** — initialized globals & statics (writable). Example base: `0x00601000`.
* **BSS (uninitialized data)** — zero-initialized globals/statics. Example base: `0x00602000`.
* **Heap** — dynamic allocations (malloc/new). Grows **upwards** (toward higher addresses). Initial brk near end of data/bss. Example start: `0x00603000`.
* **Shared libraries / mmap region** — many mapped pages for libc, etc.
* **Stack** — grows **downwards** from a high address (e.g. `0x7fffffffe000` downwards). Contains function frames, return addresses, local variables, argc/argv/envp laid out by the loader.

> Note: these exact addresses are example numbers typical for 64-bit Linux user processes. Real addresses vary (ASLR, loader, architecture).

---

# Step-by-step runtime with addresses and where things land

I'll show the process at **4 key moments**: (A) after loader maps executable but before `main`; (B) at entry of `main` (locals allocated); (C) after `new int(11)` returns; (D) after `delete p` before exit.

I'll use these example base addresses (all hex):

* TEXT (code) starts at `0x00400000`
* RODATA at `0x00600000`
* DATA at `0x00601000`
* BSS at `0x00602000`
* HEAP starts (brk) at `0x00603000` and grows up
* STACK top starts at `0x7fffffffe000` and grows down

## A. After loader maps program (before `main`)

Memory snapshot (only important pieces):

```
0x00400000  ───────── Text (code)
   ... contains machine code for main, iostream, startup

0x00600000  ───────── RODATA
   0x00600000: "hi\0"          <-- string literal for greeting

0x00601000  ───────── Data (initialized globals/statics)
   0x00601000: int global_init = 42
   0x00601004: pointer greeting -> 0x00600000  (address of "hi")
   0x00601008: int static_init = 100
   0x0060100C: int local_static = 7  (static inside main, same segment)

0x00602000  ───────── BSS (zeroed)
   0x00602000: int global_uninit = 0  (zero-initialized)

0x00603000  ───────── Heap (brk)
   (no allocations yet) -- next free at 0x00603000

... (mmap for shared libs)

0x7fffffffe000 ───────── Stack (initial top; loader pushes argc/argv/env)
```

Notes:

* `greeting` is a pointer stored in the data segment; the string `"hi"` bytes are in rodata at `0x00600000`.
* `global_uninit` lives in BSS and the loader zeroes that memory before transferring control.

## B. On entry to `main` — stack frame for main created

When `main` runs, the stack has the `main` frame. Suppose `main` frame starts at `0x7fffffffdff0` and the local `int local` is allocated in that frame.

```
Stack (grows down):
0x7fffffffe000  ── top
   ...
0x7fffffffdff0  ── saved return addresses, saved registers
0x7fffffffdfe8  ── int local  = 5         (4 bytes at 0x7fffffffdfe8)
0x7fffffffdfe4  ── pointer p (uninitialized)  (8 bytes at 0x7fffffffdfe0 on x86_64)
...
```

Memory values:

* `local` (stack) at `0x7fffffffdfe8` contains `0x00000005`.
* `p` (local pointer) resides on stack (size 8 bytes on 64-bit), initial value unspecified until `new`.

## C. After `int* p = new int(11);` — heap allocated

`new int(11)` requests memory from the heap allocator (e.g., `malloc`). Suppose allocator returns address `0x00603010`.

```
Heap:
0x00603000  ── allocator metadata (small header)
0x00603010  ── int value (4 bytes) : 11   <-- *p lives here
0x00603014  ── (padding / allocator bookkeeping)
next free brk/region > 0x00603020
```

Stack now:

* `p` (stack slot) at `0x7fffffffdfe0` contains `0x00603010` (pointer to heap allocation).
* Dereferencing `p` reads 4 bytes at `0x00603010` which are `0x0000000B` (11).

So each variable’s location:

* `global_init` → Data segment `0x00601000`
* `global_uninit` → BSS `0x00602000`
* `static_init` & `local_static` → Data `0x00601008`, `0x0060100C`
* `greeting` (pointer) → Data `0x00601004`; string bytes `"hi\0"` → rodata `0x00600000`
* `local` → stack `0x7fffffffdfe8`
* `p` → stack `0x7fffffffdfe0` (contains `0x00603010`)
* `*p` → heap `0x00603010` (contains `11`)

## D. After `delete p` and return from main

* `delete p` calls the allocator to free the block at `0x00603010`. The heap allocator will mark that block free (coalesce / place in free lists). The virtual mapping usually remains valid until brk/mmap changes; pointer `p` is now a dangling pointer but stack still contains the old address.
* Returning from `main` unwinds stack frames; CPU jumps back to startup code which calls `exit`.
* `exit` causes the kernel to tear down the process: all virtual memory mappings (text, rodata, data, bss, heap, mmaps, stack) are released. File descriptors closed, kernel frees resources. From the program’s point of view, all memory is reclaimed by the OS (no OS-level leak after process exit).

---

# Extra details & common questions

**Why string literal is RO and `greeting` pointer is in data?**

* The bytes `"hi\0"` are constant so the linker puts them in a read-only region (rodata). The pointer variable `greeting` is a writable object (it could be reassigned) so it lives in the data segment.

**What’s the difference between DATA and BSS?**

* DATA holds *initialized* global/static variables (values stored in the executable). BSS holds *uninitialized* (or zero-initialized) globals/statics; loader sets BSS to zeros, and it doesn’t occupy space in the file (only in memory).

**How does the heap allocator manage memory?**

* `new` uses the C allocator (`malloc`) normally. Allocators manage free lists, split/coalesce blocks and may request more memory from the kernel via `brk`/`sbrk` or `mmap`. Allocator metadata (headers) are stored next to allocated blocks (implementation detail — varies by allocator).

**What about stack vs heap growth?**

* Stack grows downward (toward smaller addresses) so each new function call allocates a lower address. Heap grows upward (toward larger addresses) as `brk` increases. On 64-bit systems there’s a very large gap between typical heap and stack addresses.

**Address Space Layout Randomization (ASLR)**

* Modern OSes randomize base addresses (text, heap, stack) each process start to harden security. The example addresses above are deterministic-looking for clarity; real addresses will vary.

---

# Quick table summary (where each variable from the example lives)

| Variable              | Segment |  Example address | Lifetime               |
| --------------------- | ------: | ---------------: | ---------------------- |
| `main` code           |    Text |     `0x00400000` | program                |
| `"hi"` (string bytes) | RO data |     `0x00600000` | program                |
| `greeting` (pointer)  |    Data |     `0x00601004` | program                |
| `global_init`         |    Data |     `0x00601000` | program                |
| `static_init`         |    Data |     `0x00601008` | program                |
| `local_static`        |    Data |     `0x0060100C` | program                |
| `global_uninit`       |     BSS |     `0x00602000` | program                |
| `p` (local pointer)   |   Stack | `0x7fffffffdfe0` | until function returns |
| `local`               |   Stack | `0x7fffffffdfe8` | until function returns |
| `*p` (new int)        |    Heap |     `0x00603010` | until delete/free      |

---

If you want, I can:

* Show the exact memory bytes (hex) for each location for this example,
* Produce a small diagram PNG,
* Or compile & run a similar program on your machine and show actual addresses (note: ASLR must be off for deterministic addresses).

Which of those would you like next?

---
Show the exact memory bytes (hex) for each location for this example
---

Below is a *realistic-but-fabricated* **byte-accurate hex dump** of all memory regions involved in the example.
(You cannot get exact real addresses without running the binary & disabling ASLR, but the layout, alignment, and byte representations below are accurate for a 64-bit Linux + GCC/Clang ABI.)

I will annotate every variable with:

* **Address** (example realistic)
* **Hex bytes in memory**
* **Explanation of byte order (little-endian)**

---

# 🔧 Assumptions

Architecture: **x86-64**, little-endian
Compiler: g++, standard layout
Integer: 4 bytes
Pointer: 8 bytes
Address examples follow our previous layout.

---

# 1. **Text segment (code)** – example bytes

```
0x00400000: 55 48 89 e5 48 83 ec 10 ... 
```

These are machine instructions (prologue for main, etc.).
Not very meaningful for variable layouts, but included for completeness.

---

# 2. **RODATA segment** (constant objects)

## (A) String literal `"hi\0"`

**Address:** `0x00600000`

### Bytes:

```
68 69 00
```

Explanation:

* `'h'` = 0x68
* `'i'` = 0x69
* `'\0'` = 0x00

---

# 3. **DATA segment** (initialized globals & statics)

We will lay them consecutively as typical ELF `.data`:

| Variable           | Address (example) | Value      |
| ------------------ | ----------------- | ---------- |
| `global_init`      | `0x00601000`      | 42         |
| `greeting` pointer | `0x00601004`      | 0x00600000 |
| `static_init`      | `0x0060100C`      | 100        |
| `local_static`     | `0x00601010`      | 7          |

A. **global_init = 42**
Address: `0x00601000`

### Hex:

```
2A 00 00 00
```

(42 = 0x2A, little-endian)

---

B. **greeting = 0x00600000**
Address: `0x00601004` (8-byte pointer)

Pointer stored little-endian:

Target = `00 00 60 00 00 00 00 00`
(0x0000000000600000 in 64-bit)

### Hex:

```
00 00 60 00 00 00 00 00
```

---

C. **static_init = 100**
Address: `0x0060100C`

### Hex:

```
64 00 00 00
```

(0x64 = 100)

---

D. **local_static = 7**
Address: `0x00601010`

### Hex:

```
07 00 00 00
```

---

# 4. **BSS segment** (uninitialized globals)

## `global_uninit`

Address: `0x00602000`

Loader zeroes BSS:

### Hex:

```
00 00 00 00
```

---

# 5. **STACK** (inside `main`)

Suppose stack frame for main begins near:
`0x7fffffffdfe0`

Layout:

| Variable          | Address          | Value                          |
| ----------------- | ---------------- | ------------------------------ |
| `p` (pointer)     | `0x7fffffffdfe0` | heap address e.g. `0x00603010` |
| padding/alignment | —                | —                              |
| `local = 5`       | `0x7fffffffdfe8` | 5                              |

A. **local = 5**
Address: `0x7fffffffdfe8`

### Hex:

```
05 00 00 00
```

---

B. **p = 0x00603010**
Address: `0x7fffffffdfe0`

Pointer stored little-endian:

### Hex:

```
10 30 60 00 00 00 00 00
```

---

# 6. **HEAP allocation** (`new int(11)`)

Allocator returns block at:
**`0x00603010`**

## A typical heap block layout:

```
[allocator header][user data starts here]
```

But only the **user data** = our int.

### `*p = 11`  (at address 0x00603010)

11 decimal = 0x0B hex

### Hex:

```
0B 00 00 00
```

allocator metadata (before our block, approximate):

```
0x00603000: 20 00 00 00 00 00 00 00   (size field, allocator-specific)
0x00603008: 00 00 00 00 00 00 00 00
```

(Exact metadata varies between malloc implementations, but user data bytes are 100% correct.)

---

# 📦 Full memory map (everything together)

```
===================== RODATA =====================
0x00600000: 68 69 00                                   ; "hi\0"

===================== DATA ========================
0x00601000: 2A 00 00 00                                ; global_init = 42
0x00601004: 00 00 60 00 00 00 00 00                    ; greeting → 0x00600000
0x0060100C: 64 00 00 00                                ; static_init = 100
0x00601010: 07 00 00 00                                ; local_static = 7

===================== BSS ==========================
0x00602000: 00 00 00 00                                ; global_uninit = 0

===================== HEAP =========================
0x00603000: (allocator metadata)
0x00603010: 0B 00 00 00                                ; *p = 11

===================== STACK ========================
0x7fffffffdfe8: 05 00 00 00                            ; local = 5
0x7fffffffdfe0: 10 30 60 00 00 00 00 00                ; p → 0x00603010
```

---

# Want the **actual** real bytes from a real binary?

I can produce:

✔ A real compiled binary
✔ A real `objdump -s -j .data/.bss/.rodata` dump
✔ A real GDB session showing stack/heap bytes
✔ A diagram image

Just say **“show me real dumps”** or **“generate the image diagram”**.

