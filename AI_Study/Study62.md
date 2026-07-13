In C++, `this` is a **hidden pointer** available inside every **non-static member function** of a class. It points to the object that invoked the member function.

For example:

```cpp
class Person {
public:
    int age;

    void printAge() {
        std::cout << this->age << std::endl;
    }
};

Person p;
p.age = 20;
p.printAge();
```

When `p.printAge()` is called, `this` points to `p`.

Conceptually, the compiler transforms the member function into something like:

```cpp
void Person::printAge(Person* const this) {
    std::cout << this->age << std::endl;
}
```

The `this` parameter is hidden—you never write it yourself.

---

## Type of `this`

The type depends on the member function.

For a normal member function:

```cpp
class A {
public:
    void foo();
};
```

Inside `foo()`:

```cpp
this        // type: A*
```

For a `const` member function:

```cpp
class A {
public:
    void foo() const;
};
```

Inside `foo()`:

```cpp
this        // type: const A*
```

So you cannot modify members through `this` inside a `const` function.

---

# When do you need to use `this`?

Most of the time, **you don't need to write it** because the compiler inserts it automatically.

These two are equivalent:

```cpp
age = 20;
```

and

```cpp
this->age = 20;
```

Use `this` only when it serves a purpose.

---

## 1. Resolve name conflicts (most common)

Suppose a constructor parameter has the same name as a member.

```cpp
class Person {
    int age;

public:
    Person(int age) {
        age = age;      // Wrong!
    }
};
```

Both `age`s refer to the parameter.

The member never gets assigned.

Correct:

```cpp
Person(int age) {
    this->age = age;
}
```

Meaning:

* left side → member variable
* right side → parameter

Example:

```cpp
class Point {
    int x, y;

public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};
```

---

## 2. Return the current object

Many operators and setters return the current object.

Example:

```cpp
class Counter {
    int value;

public:
    Counter& increment() {
        value++;
        return *this;
    }
};
```

Now:

```cpp
Counter c;
c.increment().increment().increment();
```

works because

```cpp
return *this;
```

returns the current object.

Without `this`, you cannot easily refer to the whole object itself.

---

## 3. Pass the current object to another function

Suppose another function expects a pointer.

```cpp
void process(Person* p);

class Person {
public:
    void send() {
        process(this);
    }
};
```

`this` is already a pointer.

---

## 4. Compare two objects

Example:

```cpp
class Person {
public:
    bool sameAddress(Person* other) {
        return this == other;
    }
};
```

or

```cpp
bool operator==(const Person& other) const {
    return this == &other;
}
```

This checks whether they are literally the same object in memory.

---

## 5. Access members through explicit qualification

Sometimes used for readability.

```cpp
this->x = this->x + 1;
```

Although simply writing

```cpp
x++;
```

is usually preferred.

---

## 6. In templates (important)

Inside template classes, member lookup behaves differently.

```cpp
template<typename T>
class Base {
protected:
    void foo() {}
};

template<typename T>
class Derived : public Base<T> {
public:
    void bar() {
        this->foo();    // Required
    }
};
```

Without `this->`, many compilers produce an error because `foo` is in a dependent base class. This is one of the few cases where `this->` is **required**.

---

# When can't you use `this`?

## Static member functions

```cpp
class A {
public:
    static void func() {
        // this   // Error
    }
};
```

Static member functions belong to the class, not to any object, so there is no current object to point to.

---

## Outside member functions

```cpp
void foo() {
    this;      // Error
}
```

Only non-static member functions have a `this` pointer.

---

# `this` vs `*this`

`this` is a pointer.

```cpp
this
```

Type:

```cpp
Person*
```

`*this` is the object itself.

```cpp
*this
```

Type:

```cpp
Person&
```

Example:

```cpp
class Person {
public:
    Person& self() {
        return *this;
    }
};
```

---

# Memory illustration

Suppose:

```cpp
Person p;
p.age = 20;
```

Memory:

```
Address 0x1000

+----------------+
| age = 20       |
+----------------+
```

Calling

```cpp
p.printAge();
```

makes

```
this
  |
  v
0x1000
+----------------+
| age = 20       |
+----------------+
```

Then

```cpp
this->age
```

means

```
(*this).age
```

which reads the `age` field from the object at address `0x1000`.

---

# Summary

| Expression                           | Meaning                                                           |
| ------------------------------------ | ----------------------------------------------------------------- |
| `this`                               | Pointer to the current object (`Class*`)                          |
| `*this`                              | The current object itself (`Class&`)                              |
| `this->member`                       | Access a member through the current object                        |
| `return *this;`                      | Return the current object by reference (common for chaining)      |
| `this == &other`                     | Check if two references refer to the same object                  |
| `this->foo()`                        | Sometimes required in class templates with dependent base classes |
| `this` in a `static` member function | Not allowed                                                       |

In modern C++, you'll most often encounter `this` in constructors to resolve name conflicts, in fluent APIs that return `*this` for method chaining, when passing the current object to another function, and in template code where `this->` is required for dependent name lookup.
