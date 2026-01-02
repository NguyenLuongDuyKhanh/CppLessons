In C++, **a callable** is **anything you can “call” using `()`** like a function.

If this works:

```cpp
x(args);
```

then **`x` is a callable**.

That’s the whole idea — but C++ has *many* kinds of callables.

---

## 1. Plain functions

### Free functions

```cpp
int add(int a, int b) {
    return a + b;
}

add(1, 2);   // callable
```

### Function declarations

```cpp
void foo();
foo();
```

---

## 2. Function pointers

```cpp
int add(int a, int b);

int (*fp)(int, int) = add;
fp(1, 2);   // callable
```

Callables even when:

```cpp
(*fp)(1, 2); // also valid
```

---

## 3. Member functions (with an object)

Member functions are callables **only with an object**.

```cpp
struct A {
    int f(int x) { return x + 1; }
};

A a;
a.f(10);   // callable
```

Or via pointer:

```cpp
A* p = &a;
(p->f)(10);
```

---

## 4. Lambdas (very important)

```cpp
auto lam = [](int x) {
    return x * 2;
};

lam(5);   // callable
```

Under the hood:

* A lambda is a **compiler-generated object**
* With `operator()`

---

## 5. Functors (function objects)

Any object with `operator()` defined.

```cpp
struct Mult {
    int operator()(int x) const {
        return x * 3;
    }
};

Mult m;
m(4);   // callable
```

This is how STL algorithms work.

---

## 6. `std::function`

A **type-erased wrapper** for callables.

```cpp
#include <functional>

std::function<int(int)> f;

f = add;
f = lam;
f = Mult{};

f(10);   // callable
```

Pros:

* Very flexible

Cons:

* Slower
* Heap allocation possible

---

## 7. Member function pointers

These are special.

```cpp
struct A {
    int f(int) { return 1; }
};

int (A::*pmf)(int) = &A::f;

A a;
(a.*pmf)(5);   // callable
```

Note the weird syntax — very C++.

---

## 8. `std::bind` results

```cpp
#include <functional>

auto f = std::bind(add, 1, 2);
f();   // callable
```

Mostly replaced by lambdas today.

---

## 9. Compile-time view (conceptual)

Modern C++ (C++20) defines this conceptually:

```cpp
template<typename F, typename... Args>
concept Callable = requires(F f, Args... args) {
    f(args...);
};
```

If it satisfies this → callable.

---

## 10. Why callables matter

Callables let you write **generic code**:

```cpp
template<typename Func>
void run(Func f) {
    f();
}
```

Used everywhere:

* `std::sort`
* `std::thread`
* callbacks
* event systems
* async code

---

## 11. Summary table

| Callable type    | Has `()` | State        | Typical use       |
| ---------------- | -------- | ------------ | ----------------- |
| Function         | Yes      | No           | Simple logic      |
| Function pointer | Yes      | No           | C-style callbacks |
| Lambda           | Yes      | Yes          | Inline logic      |
| Functor          | Yes      | Yes          | Reusable behavior |
| `std::function`  | Yes      | Yes          | APIs              |
| Member function  | Yes*     | Needs object | OO design         |

---

### One-line takeaway

> **Callable = anything that behaves like a function when you write `()`**

If you want, next we can go deeper into:

* how lambdas become functors
* performance differences between callables
* why `std::function` is slower
* how callables are used in threading (`std::thread`, `pthread`)

Just say where you want to zoom in 👀
