Short answer: **Both are valid**, but **the recommended style is `int sampleFunction(int);`** for *function declarations* (prototypes), and `int sampleFunction(int a_name)` for the *function definition*.

---

## ✅ **Why declarations usually omit parameter names**

A **function declaration** only needs to specify:

* return type
* function name
* parameter **types**

The compiler does not need parameter names at this stage. So this is perfectly fine:

```cpp
int sampleFunction(int);
```

Omitting parameter names keeps declarations clean, especially in headers.
This is the style used in standard libraries and most headers.

---

## ✅ **Why definitions should include parameter names**

When you **define** the function, you actually need parameter names:

```cpp
int sampleFunction(int a_name) {
    return a_name + 1;
}
```

Because you will use `a_name` inside the function body.

---

## 🤔 When to include names in a declaration?

You *may* include them in a declaration if:

### ✔ It improves readability

For example in an API header:

```cpp
int connect(const char* hostname, int port);
```

Here the names help users understand what the parameters mean.

### ✔ You want documentation-like clarity

Modern C++ codebases with Doxygen/span comments often name parameters in headers.

---

## ❌ But avoid mismatched names

If you declare parameters with names, the names don’t need to match the definition:

```cpp
// header
int f(int count);

// source
int f(int x) { return x + 1; }
```

This is allowed, but can be confusing — one more reason to omit names in declarations unless needed.

---

## ⭐ Recommendation

**Most common modern C++ practice:**

### In header (.hpp/.h):

```cpp
int sampleFunction(int);
```

(or include names only if they add clarity)

### In implementation (.cpp):

```cpp
int sampleFunction(int a_name) {
    ...
}
```

---

If you'd like, I can also explain:

* how default arguments work in declarations
* why C++ allows unnamed parameters
* how function overloading interacts with declarations

Just ask!
