Short answer: **the stack grows at *runtime*, not at build time**.

Now let’s unpack that properly (because this topic is sneaky).

---

## 1. What is decided at **build time**

At build / link time, the compiler decides:

* **Stack frame layout** for each function
  (how much stack space the function *needs per call*)
* Where **local variables live** (stack vs registers)
* Whether a function needs:

  * return address
  * saved registers
  * local buffers

Example:

```cpp
void f() {
    int a;
    double b;
}
```

The compiler knows *exactly* how big `f()`’s stack frame is.

👉 But this is **per function call**, not the whole stack.

---

## 2. What happens at **runtime**

At runtime:

* Each thread gets a **stack region** from the OS
* The stack has:

  * a **start address**
  * a **maximum size limit**
* The **stack pointer (SP)** moves as functions are called/returned

### Function call:

```
SP ↓ (grows downward on most architectures)
```

### Function return:

```
SP ↑
```

That movement happens **while the program is running**.

---

## 3. Does the stack “expand” dynamically?

Yes — but with rules.

### Typical behavior (Linux / Unix):

* The OS allocates a **virtual memory range** for the stack
* Pages are mapped **on demand**
* As the stack pointer moves into a new page:

  * OS allocates a new physical page
* This is called **demand paging**

So:

> The stack *appears* to grow dynamically at runtime
> but **only up to a fixed limit**

---

## 4. Stack size limit

The **maximum stack size** is set:

* By the OS / shell
* Or by the runtime / linker

Check on Linux:

```bash
ulimit -s
```

Typical values:

* 8 MB (Linux)
* 1 MB (Windows default per thread)

You can also change it:

```bash
ulimit -s unlimited
```

Or at link time:

```bash
-Wl,--stack,8388608   # Windows (MinGW)
```

⚠️ Even though the limit can be configured, **actual usage grows at runtime**.

---

## 5. Important distinction (this trips people up)

| Question                             | Answer           |
| ------------------------------------ | ---------------- |
| Stack size known at compile time?    | ❌ No             |
| Stack frame size per function known? | ✅ Yes            |
| Stack grows during execution?        | ✅ Yes            |
| Stack grows past limit?              | ❌ Stack overflow |

---

## 6. What causes stack overflow?

* Deep recursion
* Large local arrays
* Infinite recursion
* Too many threads (each has its own stack)

Example:

```cpp
void f() {
    int big[1'000'000];
}
```

This can blow the stack immediately.

---

## 7. Mental model 🧠

Think of the stack as:

> A **pre-reserved virtual space**
> that is **actually filled page-by-page at runtime**

Not build-time. Not fully allocated upfront.

---

## 8. Interview-ready answer ✅

If someone asks:

> “Does stack memory expand at build time or runtime?”

Say:

> “The compiler determines stack frame sizes at build time, but the stack itself grows at runtime as functions are called, up to a limit enforced by the OS.”

Perfect answer. 💯

---

If you want, I can also explain:

* Stack vs heap growth differences
* Why stacks usually grow downward
* Stack behavior per thread
* How this looks in assembly
