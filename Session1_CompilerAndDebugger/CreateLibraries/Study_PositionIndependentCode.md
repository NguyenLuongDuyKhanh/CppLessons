explain these lines of make log 
gcc -O3 -Wall -pthread -fpic    -c -o lgUtil.o lgUtil.c
gcc -shared -pthread  -Wl,-soname,liblgpio.so.1 -o liblgpio.so.1 lgCtx.o lgDbg.o lgErr.o lgGpio.o lgHdl.o lgI2C.o lgNotify.o lgPthAlerts.o lgPthTx.o lgSerial.o lgSPI.o lgThread.o lgUtil.o 
ln -fs liblgpio.so.1 liblgpio.so
strip --strip-unneeded liblgpio.so
size     liblgpio.so
   text    data     bss     dec     hex filename
  70720    1824   82296  154840   25cd8 liblgpio.so

  Sure — let’s go **line by line** and translate this make log into plain English. This is a very typical **Linux shared-library build**.

---

## 1️⃣ Compile one source file

```
gcc -O3 -Wall -pthread -fpic -c -o lgUtil.o lgUtil.c
```

### What this does

Compiles `lgUtil.c` into an **object file** (`lgUtil.o`).

### Flag breakdown

* **`gcc`** – GNU C compiler
* **`-O3`** – aggressive optimization (speed-focused)
* **`-Wall`** – enable most compiler warnings
* **`-pthread`**

  * Enables thread-safe code
  * Defines `_REENTRANT`
  * Links against pthreads later if needed
* **`-fpic`**

  * Generate **Position Independent Code**
  * Required for shared libraries (`.so`)
* **`-c`**

  * Compile only (don’t link yet)
* **`-o lgUtil.o`**

  * Output object file name
* **`lgUtil.c`**

  * Input source file

📌 Result: `lgUtil.o`

---

## 2️⃣ Link a shared library

```
gcc -shared -pthread -Wl,-soname,liblgpio.so.1 \
    -o liblgpio.so.1 \
    lgCtx.o lgDbg.o lgErr.o lgGpio.o lgHdl.o lgI2C.o \
    lgNotify.o lgPthAlerts.o lgPthTx.o lgSerial.o \
    lgSPI.o lgThread.o lgUtil.o
```

### What this does

Links all object files into a **shared library**:

```
liblgpio.so.1
```

### Flag breakdown

* **`-shared`**

  * Produce a shared library (`.so`)
* **`-pthread`**

  * Link against pthreads
* **`-Wl,`**

  * Pass options directly to the linker (`ld`)
* **`-soname,liblgpio.so.1`**

  * Sets the **SONAME**
  * This is the ABI version the loader uses
* **`-o liblgpio.so.1`**

  * Output filename
* **`*.o`**

  * All compiled object files

📌 Result:

```
liblgpio.so.1   (the real shared library file)
```

---

## 3️⃣ Create a symlink

```
ln -fs liblgpio.so.1 liblgpio.so
```

### What this does

Creates (or replaces) a symbolic link:

```
liblgpio.so → liblgpio.so.1
```

### Flags

* **`-f`** – force (overwrite existing)
* **`-s`** – symbolic link

### Why this matters

* **Build-time**: programs link against `-llgpio` → `liblgpio.so`
* **Runtime**: loader resolves to `liblgpio.so.1`

This allows **ABI versioning** without breaking apps.

---

## 4️⃣ Strip unused symbols

```
strip --strip-unneeded liblgpio.so
```

### What this does

Removes:

* debug symbols
* unused symbols

### Result

* Smaller binary
* Faster loading
* ❌ Harder to debug

📌 Common for **release builds**

---

## 5️⃣ Show binary size

```
size liblgpio.so
```

### Output

```
   text    data     bss     dec     hex filename
  70720    1824   82296  154840   25cd8 liblgpio.so
```

### What each column means

| Column       | Meaning                                   |
| ------------ | ----------------------------------------- |
| **text**     | Executable code (machine instructions)    |
| **data**     | Initialized global/static variables       |
| **bss**      | Uninitialized globals (zeroed at runtime) |
| **dec**      | Total size in decimal                     |
| **hex**      | Total size in hex                         |
| **filename** | Binary name                               |

⚠️ Note:

* **`bss` does NOT take space in the file**
* It’s allocated in memory at load time

---

## Big-picture summary

This build:

1. Compiles C code into PIC object files
2. Links them into a **thread-safe shared library**
3. Sets ABI versioning via `soname`
4. Creates standard symlinks
5. Strips unused symbols
6. Reports final binary size

This is **exactly how professional Linux shared libraries are built**.

If you want, I can also explain:

* 🔁 how `soname` affects upgrades
* 🧠 why `-fpic` matters at the CPU level
* 📦 difference between `.so`, `.so.1`, `.so.1.2.3`
* 🧵 what `-pthread` actually changes under the hood
