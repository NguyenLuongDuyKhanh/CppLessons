Great question—this hits a *very* core C++ concept: **references, temporaries, and const**. Let’s unpack it cleanly and intuitively.

---

## 1. What’s really happening in `int &arg = 10;`

```cpp
int &arg = 10;   // ❌ not allowed
```

### Key rule

> A **non-const lvalue reference** (`int&`) **must bind to a modifiable lvalue**.

But `10` is:

* a **temporary**
* an **rvalue**
* **not modifiable**

So this would be dangerous:

```cpp
arg = 20;  // where would this write to?
```

There is **no actual `int` object** behind `10`. Letting a non-const reference bind to it would allow modifying a temporary value that doesn’t really “live” anywhere meaningful.

👉 **C++ forbids this**.

---

## 2. Why `const int &ref = 5;` *is* allowed

```cpp
const int &ref = 5;   // ✅ allowed
```

This works because of a **special lifetime-extension rule**.

### What the compiler does

1. It creates a **temporary int** behind the scenes:

   ```cpp
   int __tmp = 5;
   ```
2. It binds `ref` to that temporary
3. Because the reference is `const`, you **cannot modify it**
4. The lifetime of the temporary is **extended to match the reference**

So this is safe:

```cpp
const int &ref = 5;
// temporary lives as long as ref
```

And this is **not allowed**:

```cpp
ref = 6;  // ❌ const prevents modification
```

---

## 3. Why `const` makes all the difference

Think of it like this:

| Case                  | Allowed? | Why                       |
| --------------------- | -------- | ------------------------- |
| `int& r = 10;`        | ❌        | Could modify a temporary  |
| `const int& r = 10;`  | ✅        | Read-only → safe          |
| `int&& r = 10;`       | ✅        | Rvalue reference (C++11+) |
| `const int&& r = 10;` | ✅        | Also fine                 |

---

## 4. The design philosophy (important for interviews)

C++ enforces this to:

* Prevent **dangling references**
* Prevent **modifying temporary values**
* Enable **efficient pass-by-reference** without copies when safe

This is why you often see:

```cpp
void foo(const std::string& s);
```

Instead of:

```cpp
void foo(std::string s);  // copy
```

You can pass:

```cpp
foo("hello");  // temporary std::string → lifetime extended
```

---

## 5. Mental model to remember 💡

> **Non-const references are aliases to real, mutable objects**
> **Const references may bind to temporaries and extend their lifetime**

If you remember *just that*, this rule will always make sense.

---

If you want, next we can:

* Compare this with **rvalue references (`&&`)**
* Show **real-world bugs** this rule prevents
* Or walk through **compiler-generated code** step by step

Just say the word 👀
