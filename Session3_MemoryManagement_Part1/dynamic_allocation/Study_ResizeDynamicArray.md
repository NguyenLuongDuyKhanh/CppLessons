Short answer: **yes in C, kind-of; in C++, not the way people often think** 😄
Long answer below — because this is one of those “looks simple, hides dragons” topics.

---

## In **C** → ✅ `realloc` (this is what it’s for)

If you allocated with `malloc` / `calloc`, you can resize with `realloc`.

### Example (safe pattern)

```c
int *arr = malloc(5 * sizeof(int));
if (!arr) return -1;

/* resize to 10 elements */
int *tmp = realloc(arr, 10 * sizeof(int));
if (!tmp) {
    /* realloc failed, arr is still valid */
    free(arr);
    return -1;
}

arr = tmp;
```

### What `realloc` actually does

* May **extend in place** (fast)
* Or **allocate new memory + copy + free old**
* Old pointer becomes **invalid** if it moves
* Existing data is preserved up to `min(old, new)` size

⚠️ Never do this:

```c
arr = realloc(arr, new_size);  // ❌ memory leak on failure
```

---

## In **C++ (raw arrays)** → 🚫 **No resizing**

```cpp
int* arr = new int[5];
arr = new int[10];   // ❌ leaks memory
```

Why?

* `new[]` has **no equivalent of `realloc`**
* C++ needs to run constructors / destructors
* Objects may not be trivially movable

So **raw dynamic arrays in C++ are fixed-size**.

---

## The **correct C++ way** → ✅ `std::vector`

This is literally why `std::vector` exists.

```cpp
#include <vector>

std::vector<int> v(5);
v.resize(10);        // grow
v.resize(3);         // shrink
```

### What happens internally

* If capacity is enough → no reallocation
* If not → allocates new memory, moves elements
* Properly calls constructors/destructors

### Even better: reserve

```cpp
v.reserve(100);  // allocate once
v.push_back(1);
```

Avoids repeated reallocations.

---

## But what if I *must* use C-style arrays in C++?

You still **cannot resize** — you must manually copy:

```cpp
int* old = new int[5];
int* resized = new int[10];

std::copy(old, old + 5, resized);

delete[] old;
old = resized;
```

This is:

* Error-prone
* Slow
* Reinventing `std::vector` badly

---

## Important edge cases

### Shrinking with `realloc` in C

```c
arr = realloc(arr, smaller_size);
```

* Memory *may* be released
* Pointer may still change

### `realloc(NULL, size)`

```c
int* p = realloc(NULL, 10 * sizeof(int));
```

✔ Equivalent to `malloc`

### `realloc(ptr, 0)`

* Implementation-defined
* May return NULL or unique pointer
* Best avoided

---

## Summary table

| Language          | Can resize? | How                    |
| ----------------- | ----------- | ---------------------- |
| C                 | ✅ Yes       | `realloc`              |
| C++ raw `new[]`   | ❌ No        | Must reallocate + copy |
| C++ `std::vector` | ✅ Yes       | `resize`, `push_back`  |

---

### Rule of thumb

* **C** → `malloc` + `realloc`
* **Modern C++** → `std::vector`
* **Never mix** `malloc` with `new`

If you want, I can:

* Explain **how `realloc` works internally**
* Show **when `realloc` is dangerous**
* Compare `vector` vs `deque` vs `list`
* Explain **capacity vs size traps**

Just tell me 👍
