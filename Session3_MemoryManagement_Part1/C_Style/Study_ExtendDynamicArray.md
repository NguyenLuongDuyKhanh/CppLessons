Great question — this gets right to the **why C++ containers exist** 😄
There are **three main ways** to “extend” a dynamic array in C++, depending on *how low-level* you want to go.

I’ll go from **modern & safe → low-level & manual**, and explain what’s really happening.

---

# 1. The RIGHT way (modern C++): `std::vector` ⭐

If you want an array that can grow, **`std::vector` is the answer**.

```cpp
std::vector<int> v;

v.push_back(1);
v.push_back(2);
v.push_back(3);
```

### What happens internally

* Vector allocates some capacity
* When capacity is full:

  * allocates a bigger block
  * moves/copies old elements
  * frees old block

All automatically.

---

### Pre-allocate to avoid reallocation

```cpp
v.reserve(100);
```

Very important in performance-sensitive code.

---

### Resize explicitly

```cpp
v.resize(10);  // adds default-initialized elements
```

---

## Why vector is almost always correct

✔ Safe
✔ Fast
✔ Cache-friendly
✔ Exception-safe
✔ RAII-managed

---

# 2. Using smart pointers (manual but safer)

If you *really* want raw arrays but safer ownership:

```cpp
auto p = std::make_unique<int[]>(5);
```

To “extend” it:

```cpp
size_t oldSize = 5;
size_t newSize = 10;

auto new_p = std::make_unique<int[]>(newSize);
std::copy(p.get(), p.get() + oldSize, new_p.get());
p = std::move(new_p);
```

⚠️ You must:

* allocate new memory
* copy elements
* free old memory

Exactly what `std::vector` already does.

---

# 3. C-style reallocation (NOT for C++ objects)

### Using `realloc` ❌

```c
int* p = (int*)malloc(5 * sizeof(int));
p = (int*)realloc(p, 10 * sizeof(int));
```

This is **dangerous in C++** because:

* constructors are NOT called
* destructors are NOT called
* object invariants break

🚫 **Never use `realloc` for C++ objects**

---

# 4. Manual `new[]` reallocation (educational)

```cpp
int* p = new int[5];
```

To extend:

```cpp
int* new_p = new int[10];
std::copy(p, p + 5, new_p);
delete[] p;
p = new_p;
```

This is correct **but fragile**:

* easy to leak memory
* no exception safety
* no automatic resizing

---

# 5. Why you can’t “extend in place”

```cpp
int* p = new int[5];
```

You **cannot** do:

```cpp
p.resize(10); // ❌ impossible
```

Because:

* `new[]` returns a fixed-size block
* Adjacent memory may belong to someone else

---

# 6. Performance reality (important)

| Method              | Complexity      |
| ------------------- | --------------- |
| push_back (vector)  | Amortized O(1)  |
| Reallocation        | O(n)            |
| Manual reallocation | O(n) every time |

This is why vector grows **geometrically**.

---

# 7. Choosing the right tool

| Need             | Use                    |
| ---------------- | ---------------------- |
| Resizable array  | `std::vector`          |
| Shared ownership | `std::shared_ptr<T[]>` |
| Fixed-size array | `std::array`           |
| C API interop    | raw pointer            |
| Low-level memory | allocator              |

---

# 8. Interview one-liner 🎯

> In C++, a dynamically allocated array cannot be extended in place; instead, you allocate a larger block, copy elements, and free the old one—`std::vector` automates this safely and efficiently.

---

# 9. Golden rule 🧠

> **If you think you need to “extend” a dynamic array, you probably want `std::vector`.**

---

If you want next:

* Implement a **mini vector from scratch**
* Compare **vector vs deque**
* Show **reallocation cost in assembly**
* Explain **small-buffer optimization**

Just tell me where to go next 👌
