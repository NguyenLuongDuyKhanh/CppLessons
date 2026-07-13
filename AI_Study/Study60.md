There are some important distinctions here.

First, assume the class is:

```cpp
class A {
public:
    A() { std::cout << "Constructor\n"; }
    void aFunction() {}
};
```

## Case 1: `A obj;`

```cpp
A obj;
```

This creates an **actual object** of type `A`.

Execution:

1. Memory for `obj` is allocated (typically on the stack if it's a local variable).
2. `A`'s constructor is called immediately.
3. `obj` is ready to use.
4. When `obj` goes out of scope, its destructor is called automatically.

```
Memory allocated
      ↓
A::A() called
      ↓
Object usable
      ↓
A::~A() called
```

---

## Case 2: `A* obj;`

```cpp
A* obj;
```

This **does not create an `A` object**.

It only declares a pointer.

No memory for an `A` instance is allocated.
No constructor is called.

```
Pointer variable created
      ↓
Contains an indeterminate value (if local)
```

The pointer itself exists, but it doesn't point to any valid object.

If it's a local variable:

```cpp
void f() {
    A* obj;   // uninitialized
}
```

`obj` contains garbage.

If it's a static/global variable:

```cpp
A* obj;
```

then it is initialized to `nullptr`.

---

## Case 3: `A* obj = new A;`

```cpp
A* obj = new A;
```

Now an object is actually created.

Execution:

1. Allocate memory on the heap.
2. Call `A`'s constructor.
3. Store the address in `obj`.

```
Heap memory allocated
        ↓
A::A() called
        ↓
Pointer receives address
```

When finished:

```cpp
delete obj;
```

calls the destructor and frees the memory.

---

# Is there any difference in constructor order?

Suppose

```cpp
A a;
A* p = new A;
```

Execution order is exactly the order of the statements:

```
A a;          --> constructor called
A* p = new A; --> constructor called
```

The pointer declaration itself

```cpp
A* p;
```

does **not** invoke any constructor.

---

# What about

```cpp
A* obj;
obj->aFunction();
```

This is **wrong**.

`obj` does not point to a valid `A` object.

Possible outcomes:

* segmentation fault
* access violation
* seemingly "works" (still undefined behavior)
* random corruption

This is **undefined behavior**.

---

## Correct ways

### Allocate an object

```cpp
A* obj = new A;
obj->aFunction();
delete obj;
```

or, preferably in modern C++:

```cpp
auto obj = std::make_unique<A>();
obj->aFunction();
```

---

### Or point to an existing object

```cpp
A a;
A* obj = &a;

obj->aFunction();
```

Now `obj` points to a valid object.

---

# Summary

| Statement           | Object created? | Constructor called? | Safe to call `aFunction()`? |
| ------------------- | --------------- | ------------------- | --------------------------- |
| `A obj;`            | ✅ Yes           | ✅ Yes               | ✅ Yes (`obj.aFunction()`)   |
| `A* obj;`           | ❌ No            | ❌ No                | ❌ No (undefined behavior)   |
| `A* obj = new A;`   | ✅ Yes (heap)    | ✅ Yes               | ✅ Yes                       |
| `A a; A* obj = &a;` | ✅ Yes (stack)   | ✅ Yes               | ✅ Yes                       |

The key idea is that a **pointer is not an object**. Declaring `A* obj;` only creates storage for an address. An `A` object—and therefore its constructor—only comes into existence when you actually instantiate one (e.g., `A obj;`, `new A`, or by pointing to an existing `A`).
