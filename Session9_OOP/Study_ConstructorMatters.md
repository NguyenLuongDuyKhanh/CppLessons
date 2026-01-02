Nice, this *is* classic interview territory 😄
Let’s break it into **(1) `= delete` vs `= default`**, then **(2) common trick questions interviewers love**.

---

# 1. `= delete` vs `= default`

## `= default`

Means:

> “Generate the compiler’s default implementation **explicitly**.”

Example:

```cpp
class A {
public:
    A() = default;
    ~A() = default;
};
```

Why explicitly default something?

* To **document intent**
* To **re-enable** a function suppressed by another declaration
* To control **special member generation rules**

Example (important):

```cpp
class B {
public:
    B(int x) {}
    B() = default;  // otherwise default ctor would NOT exist
};
```

---

## `= delete`

Means:

> “This function must never be used. If someone tries → hard compile error.”

Example:

```cpp
class C {
public:
    C() = delete;
};
```

---

## Side-by-side comparison

| Aspect             | `= default`                | `= delete`        |
| ------------------ | -------------------------- | ----------------- |
| Purpose            | Ask compiler to generate   | Forbid usage      |
| Callable           | Yes                        | No                |
| Compile-time check | Yes                        | Yes               |
| Expresses intent   | “This is allowed”          | “This is illegal” |
| Can apply to       | Special members, operators | Any function      |

---

## Subtle rule: **defaulted functions can be deleted**

The compiler may *still* delete a `= default` function.

```cpp
class X {
    std::mutex m;
};
```

This compiles:

```cpp
X x;
```

But this does **not**:

```cpp
X x2 = x;   // ❌ copy ctor is implicitly deleted
```

Why?

* `std::mutex` is non-copyable
* So `X`’s copy ctor is **implicitly deleted**

---

# 2. Common Interview Trick Questions

## Trick 1: “Is `= default` the same as an empty body?”

❌ **No**

```cpp
class A {
public:
    A() {}           // user-provided
};

class B {
public:
    B() = default;   // compiler-generated
};
```

Difference:

* `A` is **not trivially constructible**
* `B` **may be trivial**
* Affects performance, POD-ness, and ABI

👉 Interviewers love this.

---

## Trick 2: “Why does adding a destructor break copying?”

```cpp
class A {
public:
    ~A() {}
};
```

Now:

```cpp
A a1;
A a2 = a1;  // ❌ copy ctor deleted (C++11+)
```

Why?

* User-declared destructor suppresses implicit move
* Copy may also be deleted depending on members

Fix:

```cpp
class A {
public:
    ~A() = default;
};
```

---

## Trick 3: “Why is my class suddenly non-movable?”

```cpp
class A {
public:
    A(const A&) = delete;
};
```

Even if you write:

```cpp
A(A&&) = default;
```

It **still may not move**, because:

* Move uses copy for some members
* Or copy deletion blocks move generation

Rule:

> Declaring **any** copy operation affects move generation.

---

## Trick 4: “Why does `std::vector<T>` fail to compile?”

```cpp
class T {
public:
    T() = default;
    T(const T&) = delete;
};
```

```cpp
std::vector<T> v;
v.push_back(T{});  // ❌
```

Why?

* `std::vector` needs **move or copy**
* If neither exists → compilation fails

Fix:

```cpp
T(T&&) = default;
```

---

## Trick 5: Deleted overload beats templates

```cpp
void f(int) = delete;

template<typename T>
void f(T) {
    std::cout << "template\n";
}

f(10);   // ❌ compile error
```

Why?

* Deleted functions participate in overload resolution
* Best match wins → then error

Interview gold 🥇

---

## Trick 6: Private vs deleted

```cpp
class A {
private:
    A();
};
```

vs

```cpp
class B {
public:
    B() = delete;
};
```

Difference:

* `private`: access control
* `delete`: semantic prohibition

Deleted gives **clearer diagnostics** and works even in `public`.

---

## Trick 7: Can destructors be deleted?

Yes — and it’s evil 😈

```cpp
class A {
public:
    ~A() = delete;
};
```

Effects:

* Objects cannot be destroyed
* No automatic storage
* Only useful for very niche metaprogramming

---

## Trick 8: Rule of Zero vs Five (trap question)

Interviewer:

> “Should you always delete copy if you manage resources?”

Correct answer:

> No. Prefer **Rule of Zero** (use RAII types like `unique_ptr`).
> Delete only when ownership semantics require it.

---

## One-sentence interview summary

> Use `= default` to **explicitly allow** compiler-generated behavior, and `= delete` to **explicitly forbid** invalid operations — both are about *design intent*, not syntax.

---

If you want, next we can:

* Go through **real interview code snippets**
* Explain **why STL containers trigger deletes**
* Do a **rapid-fire quiz** like an actual interview

Just say the word 🔥
