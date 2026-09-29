`std::make_unique` and `std::make_shared` are the preferred ways to create smart pointers in modern C++. They are safer, more efficient, and less verbose than using `new` directly.

---

# 1. `std::make_unique`

```cpp
auto ptr = std::make_unique<MyClass>(10, "hello");
```

instead of

```cpp
std::unique_ptr<MyClass> ptr(new MyClass(10, "hello"));
```

## Advantages

### 1. Exception safety

Suppose you write:

```cpp
foo(std::unique_ptr<MyClass>(new MyClass()), otherFunction());
```

Prior to C++17, if `otherFunction()` threw an exception after `new MyClass()` but before the `unique_ptr` was constructed, the allocated memory leaked.

With `make_unique`:

```cpp
foo(std::make_unique<MyClass>(), otherFunction());
```

No leak is possible because allocation and smart pointer construction happen together.

---

### 2. Less typing

Instead of

```cpp
std::unique_ptr<Person> p(new Person("Alice", 20));
```

just write

```cpp
auto p = std::make_unique<Person>("Alice", 20);
```

---

### 3. Perfect forwarding

Constructor arguments are forwarded automatically.

```cpp
class Person
{
public:
    Person(std::string name, int age);
};

auto p = std::make_unique<Person>("Bob", 25);
```

No need to specify constructor explicitly.

---

# Example

```cpp
#include <iostream>
#include <memory>

class Widget
{
public:
    Widget(int x)
    {
        std::cout << "Construct " << x << '\n';
    }

    ~Widget()
    {
        std::cout << "Destroy\n";
    }
};

int main()
{
    auto ptr = std::make_unique<Widget>(42);

    std::cout << "Using widget\n";
}
```

Output

```
Construct 42
Using widget
Destroy
```

---

# 2. `std::make_shared`

Usage is similar.

```cpp
auto ptr = std::make_shared<MyClass>(1, 2, 3);
```

instead of

```cpp
std::shared_ptr<MyClass> ptr(new MyClass(1,2,3));
```

---

# Why `make_shared` is even better

The biggest advantage is **allocation efficiency**.

Without `make_shared`

```
shared_ptr
    |
    +---- Control Block  (allocation #1)

Object
    |
    +---- MyClass        (allocation #2)
```

Two heap allocations occur.

---

With `make_shared`

```
One heap allocation

+------------------------------------+
| Control Block | MyClass object     |
+------------------------------------+
```

Only **one allocation**.

Benefits:

* Faster
* Better cache locality
* Less heap fragmentation

---

# Example

```cpp
auto p = std::make_shared<Person>("John", 30);

std::cout << p.use_count();
```

Output

```
1
```

After copying:

```cpp
auto p2 = p;

std::cout << p.use_count();
```

Output

```
2
```

---

# 3. `make_shared` vs direct `new`

```cpp
auto p = std::shared_ptr<Person>(new Person());
```

Memory layout:

```
Heap

Person

Heap

control block
```

Two allocations.

---

```cpp
auto p = std::make_shared<Person>();
```

Memory layout:

```
Heap

+---------------------------+
| control | Person object   |
+---------------------------+
```

One allocation.

---

# 4. When **not** to use `make_shared`

Suppose the object is huge.

```cpp
struct Huge
{
    char data[100000000];
};
```

Create:

```cpp
auto p = std::make_shared<Huge>();

std::weak_ptr<Huge> w = p;
```

Later

```cpp
p.reset();
```

The `Huge` object is destroyed, but the combined allocation cannot be freed until all `weak_ptr`s are gone because the control block and object share the same allocation. If many `weak_ptr`s outlive the object, this can keep a large memory block reserved longer than expected.

Using separate allocations:

```cpp
std::shared_ptr<Huge> p(new Huge);
```

allows the object's memory to be released as soon as the last `shared_ptr` disappears, even if `weak_ptr`s still exist (the control block remains allocated until the `weak_ptr`s are gone).

This is one of the few cases where direct construction of `shared_ptr` may be preferable.

---

# 5. Arrays

`make_unique` supports arrays.

```cpp
auto arr = std::make_unique<int[]>(100);
```

Access

```cpp
arr[5] = 10;
```

---

`make_shared` **does not** support dynamic arrays prior to C++20. Since C++20, `std::make_shared<T[]>` and related overloads are available if your standard library implements them, but support may vary across toolchains.

---

# 6. Custom deleters

`make_unique` cannot specify a custom deleter.

Instead

```cpp
auto file = std::unique_ptr<FILE, decltype(&fclose)>(
    fopen("a.txt", "r"),
    &fclose
);
```

Similarly, `make_shared` doesn't let you provide a custom deleter directly. If you need one, construct the smart pointer explicitly:

```cpp
auto ptr = std::shared_ptr<MyType>(
    rawPtr,
    customDeleter
);
```

---

# 7. Best practices

✅ Prefer

```cpp
auto p = std::make_unique<Foo>();
```

instead of

```cpp
std::unique_ptr<Foo> p(new Foo());
```

---

✅ Prefer

```cpp
auto p = std::make_shared<Foo>();
```

instead of

```cpp
std::shared_ptr<Foo> p(new Foo());
```

---

✅ Use `make_unique` by default for exclusive ownership.

```cpp
auto texture = std::make_unique<Texture>();
```

---

✅ Use `make_shared` only when ownership is genuinely shared.

```cpp
auto config = std::make_shared<Config>();

moduleA.setConfig(config);
moduleB.setConfig(config);
```

---

❌ Don't create a `shared_ptr` if there is only one owner.

```cpp
// Overkill
auto p = std::make_shared<Foo>();
```

Prefer

```cpp
auto p = std::make_unique<Foo>();
```

---

# Summary

| Feature                 | `make_unique`     | `make_shared`                               |
| ----------------------- | ----------------- | ------------------------------------------- |
| Ownership               | Exclusive         | Shared                                      |
| Heap allocations        | 1 (object)        | Usually 1 (object + control block together) |
| Exception safety        | Yes               | Yes                                         |
| Uses `new` internally   | Yes               | Yes                                         |
| Supports arrays         | Yes (since C++14) | Yes (since C++20, implementation-dependent) |
| Supports custom deleter | No                | No                                          |
| Recommended default     | ✔️ Yes            | ✔️ Only when shared ownership is required   |

A practical guideline in modern C++ is:

* **Start with `std::make_unique`** because exclusive ownership is simpler, cheaper, and easier to reason about.
* **Switch to `std::make_shared`** only when multiple parts of your program truly need to share ownership of the same object.
