`noexcept` is one of those C++ features that looks small but quietly changes how **performance, safety, and containers** behave. Let’s build it up the *right* way.

---

## 1️⃣ What `noexcept` actually means

```cpp
void f() noexcept;
```

Means:

> **“This function promises to never throw an exception.”**

If it *does* throw → **`std::terminate()` is called immediately**.

No stack unwinding. No catching. Program ends.

So `noexcept` is both:

* a **contract**
* an **optimization hint**

---

## 2️⃣ Basic usage

### Function declaration

```cpp
void log() noexcept;
```

### Function definition

```cpp
void log() noexcept {
    // must not throw
}
```

---

## 3️⃣ Why `noexcept` matters (big reason)

### 🚀 Performance & STL containers

Standard containers (like `std::vector`) behave **very differently** depending on `noexcept`.

### Example: move vs copy

```cpp
struct X {
    X() = default;
    X(const X&) { std::cout << "copy\n"; }
    X(X&&) noexcept { std::cout << "move\n"; }
};
```

Now:

```cpp
std::vector<X> v;
v.push_back(X{});
```

✔ `std::vector` uses **move**
❌ Without `noexcept`, it may fall back to **copy**

👉 STL requires `noexcept` to **safely move elements during reallocation**

---

## 4️⃣ The golden rule for move constructors

### ✅ ALWAYS mark move operations `noexcept`

```cpp
class Integer {
public:
    Integer(Integer&& other) noexcept;
    Integer& operator=(Integer&& other) noexcept;
};
```

If you don’t:

* `std::vector<Integer>` may copy instead of move
* performance tanks
* move semantics become useless

---

## 5️⃣ Conditional `noexcept` (advanced but important)

Sometimes a function is `noexcept` **only if** something else is.

```cpp
template<typename T>
void swap(T& a, T& b) noexcept(noexcept(T(std::move(a))) &&
                               noexcept(a = std::move(b))) {
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}
```

This means:

> “`swap` is noexcept **if and only if** moving `T` is noexcept.”

Used heavily in STL.

---

## 6️⃣ `noexcept` vs `throw()`

❌ Old (C++03)

```cpp
void f() throw();
```

✔ Modern

```cpp
void f() noexcept;
```

`throw()` is deprecated and removed.

---

## 7️⃣ Checking `noexcept` at compile time

```cpp
static_assert(noexcept(f()), "f must be noexcept");
```

Or:

```cpp
if constexpr (noexcept(obj.move())) {
    // safe path
}
```

---

## 8️⃣ `noexcept` on destructors (VERY important)

### Rule:

> **Destructors should never throw.**

C++ implicitly makes destructors `noexcept(true)` by default.

If you violate this → 💥 `std::terminate`

```cpp
~X() noexcept {
    // OK
}
```

---

## 9️⃣ Common mistakes ❌

### ❌ Marking functions `noexcept` when they can throw

```cpp
void f() noexcept {
    new int[1000000000]; // may throw bad_alloc → terminate
}
```

### ❌ Forgetting `noexcept` on move constructor

```cpp
X(X&&);   // BAD
```

---

## 🔟 When NOT to use `noexcept`

* Functions that:

  * allocate memory
  * call user-provided callbacks
  * rely on throwing APIs
* Public APIs where throwing is part of the contract

---

## TL;DR (interview-ready)

* `noexcept` = **promise not to throw**
* Violating it → **`std::terminate`**
* STL containers **require `noexcept` move constructors**
* Always mark:

  * move ctor
  * move assignment
  * destructors
* Use conditional `noexcept` in templates
* Don’t lie with `noexcept`

---

If you want next, I can:

* show **exact STL behavior with and without `noexcept`**
* explain **why vector reallocation demands it**
* or review your `Integer` class and mark it perfectly

Just say 👍
