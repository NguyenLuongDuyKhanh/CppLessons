Great question! Let’s carefully break this down in C++ terms:

### 1. Pass by Reference

In C++, a function parameter is passed **by reference** when the parameter type is declared with an ampersand (`&`) **in the function definition**.
Example:

```cpp
void func(int& x) {
    x = x * 2;
}
```

Here, `x` is a **reference** to the original variable passed in. If you call:

```cpp
int a = 5;
func(a);   // modifies a directly
```

`a` will become `10`.

➡️ **Important:** You call the function with `func(a)`, **not** `func(&a)`.

---

### 2. Pass by Pointer

If the function expects a **pointer**, you need to use `&` in the call to pass the address:

```cpp
void func(int* x) {
    *x = *x * 2;
}
```

Usage:

```cpp
int a = 5;
func(&a);  // pass address of a
```

Now, `a` also becomes `10`.

---

### 3. The Difference Between `func(a)` and `func(&a)`

* `func(a)` → Used when `func` takes either:

  * A **value parameter** (`int x`) → copy passed, original not modified.
  * A **reference parameter** (`int& x`) → original is modified.
* `func(&a)` → Used when `func` takes a **pointer parameter** (`int* x`).

So the distinction comes from **how the function is declared**, not how you call it.

---

✅ **Answer to your question:**
`func(a)` is pass by reference **if and only if** the function is declared with a reference parameter (`int&`).
`func(&a)` is **not pass by reference** — it’s passing the **address** (pointer).

---

Would you like me to also show you what happens at the **assembly/memory level**, so you can see *exactly* how `a` is treated differently in each case?
