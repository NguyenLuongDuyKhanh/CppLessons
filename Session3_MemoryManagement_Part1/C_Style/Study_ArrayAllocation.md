This is a **fantastic question**, because it gets to the heart of **undefined behavior** — one of the most misunderstood parts of C++.

Short answer first 👇
👉 **The code “works” by accident. It is undefined behavior.**

Now let’s really understand *why*.

---

## The code in question

```cpp
int *p = new int;
for (int i = 0; i < 5; ++i) {
    p[i] = i;
}
```

---

## What you *think* this does ❌

You might think:

> “`p` points to memory, and I’m just writing 5 ints there.”

But that’s **not what you allocated**.

---

## What actually happens in memory

### Step 1: Allocation

```cpp
int* p = new int;
```

This allocates **exactly ONE `int`**.

Memory layout:

```
[p]
```

That’s it. No more.

---

### Step 2: The loop

```cpp
p[0] = 0; // OK
p[1] = 1; // ❌
p[2] = 2; // ❌
p[3] = 3; // ❌
p[4] = 4; // ❌
```

Remember:

```cpp
p[i] == *(p + i)
```

So:

* `p + 1` → memory **you do NOT own**
* Writing there is **out-of-bounds access**

👉 This is **undefined behavior (UB)**.

---

## So why does it *appear* to work? 😈

Because of **how heap allocators work**.

### Typical heap behavior (simplified)

When you do:

```cpp
new int;
```

The allocator often gives you **more memory than requested** due to:

* alignment
* internal bookkeeping
* free-list chunk sizes

So the actual memory block might look like:

```
[p][ ][ ][ ][ ][ ][ ][ ]
```

Your writes:

```cpp
p[1], p[2], p[3], p[4]
```

happen to land inside that extra space.

👉 **But this space is NOT yours.**

---

## Why this is extremely dangerous ⚠️

### 1. It may crash tomorrow

Change *anything*:

* compiler
* optimization level
* OS
* build type (Debug vs Release)

And suddenly:

```text
Segmentation fault
Heap corruption
Malloc(): invalid next size
```

---

### 2. It may corrupt other data

You might overwrite:

* heap metadata
* another object
* allocator bookkeeping

Crash happens **later**, far from the bug.

---

### 3. Sanitizers WILL catch it

Compile with:

```bash
g++ -fsanitize=address -O1 -g test.cpp
```

You’ll get:

```
heap-buffer-overflow
```

---

## Why C++ allows this at all?

Because:

* C++ gives **raw memory access**
* For performance and low-level control
* The language does **not** do bounds checking

This is a **design tradeoff**, not a bug.

---

## Correct versions of the code ✅

### Option 1: Allocate what you use

```cpp
int* p = new int[5];
for (int i = 0; i < 5; ++i) {
    p[i] = i;
}
delete[] p;
```

---

### Option 2: Modern C++ (recommended)

```cpp
std::vector<int> p(5);
for (int i = 0; i < 5; ++i) {
    p[i] = i;
}
```

Or:

```cpp
auto p = std::make_unique<int[]>(5);
```

---

## Key rule to remember 🧠

> **If your code “works” while doing out-of-bounds access, it’s lying to you.**

Undefined behavior means:

* The compiler is allowed to do *anything*
* Including making your program seem correct

---

## Interview-quality answer 🎯

> The code compiles and may appear to work because the heap allocator often provides extra memory, but writing past the single allocated `int` is undefined behavior and may crash or corrupt memory unpredictably.

---

If you want next, we can:

* Visualize **heap layout**
* Run this with **AddressSanitizer**
* Compare **debug vs release behavior**
* Show **real-world production crashes caused by UB**

Just tell me — this is exactly the kind of question strong C++ engineers ask 👌
