`const` exists in both C and C++, but it is **much more powerful and pervasive in C++**. In C, `const` mainly means "read-only." In C++, it becomes part of the language's type system and is used for object-oriented programming, templates, optimization, and API design.

Here's a comprehensive comparison.

---

# 1. Const variables

## C

```c
const int x = 10;
// x = 20;    // Error
```

Simply means the variable cannot be modified through this name.

---

## C++

Exactly the same syntax.

```cpp
const int x = 10;
```

However, C++ uses `const` much more extensively.

---

# 2. Pointer constness

There are three common forms.

## Pointer to const

The object cannot be modified.

### C

```c
int x = 5;
const int *p = &x;

// *p = 10;      // Error
p = NULL;        // OK
```

---

### C++

Exactly the same.

```cpp
const int *p = &x;
```

---

## Const pointer

The pointer cannot change.

```cpp
int x = 5;
int y = 8;

int *const p = &x;

*p = 10;     // OK
// p = &y;   // Error
```

Works identically in C.

---

## Const pointer to const

```cpp
const int *const p = &x;
```

Neither pointer nor pointee can change.

---

# 3. References (C++ only)

C has no references.

```cpp
const std::string& name = getName();
```

Advantages:

* no copy
* cannot modify object
* extends temporary lifetime

Example

```cpp
void print(const std::string& s)
{
    std::cout << s;
}
```

---

# 4. Const function parameters

## C

```c
void print(const char *str);
```

Simply promises not to modify the string.

---

## C++

Exactly the same.

```cpp
void print(const std::string& s);
```

Using const reference avoids copying.

---

# 5. Const member functions (C++ only)

One of the biggest differences.

```cpp
class Point
{
public:
    int getX() const
    {
        return x;
    }

private:
    int x;
};
```

The trailing `const` means

> This function promises not to modify the object.

Inside it,

```cpp
x = 5;
```

is illegal.

---

Without const:

```cpp
int getX()
{
    return x;
}
```

cannot be called on const objects.

Example

```cpp
const Point p;

p.getX();      // OK

p.setX(5);     // Error
```

---

# 6. Const objects

C

```c
const int x = 10;
```

Nothing special.

---

C++

Objects can be const.

```cpp
const Point p;
```

Only const member functions may be called.

```cpp
p.getX();      // OK
p.move();      // Error
```

---

# 7. Const return value

## Returning const value

```cpp
const int foo();
```

Usually useless.

Modern C++ rarely uses this.

---

More useful:

```cpp
const std::string& getName();
```

Returns read-only reference.

---

# 8. Const member variables

```cpp
class Person
{
    const int id;
};
```

Must be initialized in constructor initializer list.

```cpp
Person(int i)
    : id(i)
{
}
```

Cannot assign later.

---

# 9. Const in overloaded functions (C++ only)

```cpp
class Vector
{
public:

    int& operator[](size_t i)
    {
        return data[i];
    }

    const int& operator[](size_t i) const
    {
        return data[i];
    }
};
```

Compiler chooses version depending on object constness.

```cpp
Vector v;
const Vector cv;

v[0] = 5;

int x = cv[0];
// cv[0] = 5;      // Error
```

---

# 10. Top-level vs low-level const

C++ distinguishes them.

```cpp
int x = 5;

const int *p;
```

Here

```
const
```

belongs to the pointee.

Low-level const.

---

```cpp
int *const p = &x;
```

Pointer itself is const.

Top-level const.

This distinction matters in templates and overload resolution.

---

# 11. Const with auto

```cpp
const int x = 5;

auto a = x;
```

`a` becomes

```cpp
int
```

because top-level const is dropped.

To preserve const:

```cpp
const auto a = x;
```

or

```cpp
auto const a = x;
```

---

# 12. Const with templates

```cpp
template<typename T>
void foo(T t)
{
}
```

Calling

```cpp
const int x = 5;

foo(x);
```

deduces

```
T = int
```

Top-level const disappears.

But

```cpp
template<typename T>
void foo(T& t)
```

deduces

```
T = const int
```

Const becomes important.

---

# 13. Const with move semantics

```cpp
std::string s;

std::move(s);
```

works.

But

```cpp
const std::string s;

std::move(s);
```

does **not** move.

Reason:

```
move constructor

std::string(std::string&&)
```

cannot bind to

```
const std::string&&
```

Therefore copy constructor is used.

This is a common source of unexpected performance issues.

---

# 14. Const and mutable (C++ only)

Sometimes a const function must still modify bookkeeping data.

```cpp
class Cache
{
public:

    int value() const
    {
        ++counter;
        return x;
    }

private:

    mutable int counter = 0;

    int x = 5;
};
```

`mutable` allows modification inside const member functions.

Typical use:

* caches
* mutexes
* statistics
* lazy initialization

---

# 15. Constexpr vs const (C++ only)

```cpp
const int x = 5;
```

Means

> read-only.

---

```cpp
constexpr int x = 5;
```

Means

> compile-time constant.

All `constexpr` variables are `const`, but not all `const` variables are `constexpr`.

Example:

```cpp
int n = read();

const int a = n;      // OK
// constexpr int b = n;  // Error
```

---

# 16. Internal linkage for file-scope const

This is a subtle but important language difference.

## C

At file scope:

```c
const int x = 42;
```

By default, `x` has **external linkage**, so it can be referred to from other translation units (subject to the rules of the C standard and declarations with `extern`).

## C++

At namespace/file scope:

```cpp
const int x = 42;
```

By default, `x` has **internal linkage**. Each translation unit that includes such a definition gets its own copy unless you write:

```cpp
extern const int x;
```

This difference surprises many programmers moving from C to C++.

---

# Summary comparison

| Feature                                            | C       | C++ |
| -------------------------------------------------- | ------- | --- |
| Read-only variables                                | ✅       | ✅   |
| Pointer constness                                  | ✅       | ✅   |
| References                                         | ❌       | ✅   |
| Const references                                   | ❌       | ✅   |
| Const member functions                             | ❌       | ✅   |
| Const objects                                      | Limited | ✅   |
| Member function overloading by const               | ❌       | ✅   |
| Templates and const deduction                      | ❌       | ✅   |
| Move semantics interaction                         | ❌       | ✅   |
| `mutable` keyword                                  | ❌       | ✅   |
| `constexpr`                                        | ❌       | ✅   |
| File-scope `const` has internal linkage by default | ❌       | ✅   |

## Best practices in modern C++

* Prefer `const` for values that should not change after initialization.
* Pass large objects as `const T&` when you only need to read them.
* Mark member functions `const` whenever they do not modify the observable state of the object.
* Use `constexpr` instead of `const` when a compile-time constant is required.
* Avoid returning `const` by value (e.g., `const int foo()`), as it provides little benefit and can interfere with move semantics for user-defined types.
