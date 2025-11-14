Below is a **clear, practical explanation** of `malloc`, `calloc`, and `realloc` in C, with **examples** and an **under-the-hood look** at how the heap and free-list allocator typically work (glibc `ptmalloc`-style simplified).

---

# ✅ 1. Differences Between `malloc`, `calloc`, and `realloc`

## **malloc(size)**

* Allocates **size** bytes.
* **Contents are uninitialized** → whatever garbage was already in memory.
* Returns `NULL` if allocation fails.

Example:

```c
int *arr = malloc(10 * sizeof(int));   // uninitialized
```

---

## **calloc(n, size)**

* Allocates space for **n elements**, each of size **size**.
* **Initializes the entire block to zero**.
* Prevents uninitialized memory bugs.

Equivalent to:

```c
ptr = malloc(n * size);
memset(ptr, 0, n * size);
```

…but implemented more efficiently.

Example:

```c
int *arr = calloc(10, sizeof(int));  // initialized to zero
```

---

## **realloc(ptr, new_size)**

* Changes the size of an already allocated block.
* It may:
  ✔ resize in place
  ✔ move to a new block and `memcpy` data
* Returns:

  * pointer to resized block **OR**
  * `NULL` on failure (old pointer is NOT freed → must check carefully!)

Example:

```c
int *arr = malloc(5 * sizeof(int));

arr = realloc(arr, 10 * sizeof(int));  // may move to new memory
```

Safe pattern:

```c
int *tmp = realloc(arr, 10 * sizeof(int));
if (tmp != NULL) arr = tmp;
```

---

# ✅ 2. Simple Examples of Each

## **malloc example**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a = malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);   // garbage values!

    free(a);
}
```

---

## **calloc example**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a = calloc(5, sizeof(int));

    for (int i = 0; i < 5; i++)
        printf("%d ", a[i]);   // all zeros

    free(a);
}
```

---

## **realloc example**

```c
#include <stdlib.h>
#include <stdio.h>

int main() {
    int *a = malloc(3 * sizeof(int));

    a[0] = 1; a[1] = 2; a[2] = 3;

    int *tmp = realloc(a, 6 * sizeof(int));
    if (!tmp) {
        free(a);
        return 1;
    }
    a = tmp;

    for (int i = 0; i < 6; i++)
        printf("%d ", a[i]);   // last 3 are uninitialized!

    free(a);
}
```

---

# ✅ 3. How `malloc`/`free` Works Under the Hood

*(Simplified glibc ptmalloc model)*

Memory is managed in **chunks** stored in the heap.

A chunk looks like this:

```
+-------------------+
| Metadata (size...)|  ← stored before your pointer
+-------------------+
|     User data     |  ← returned pointer points here
+-------------------+
```

Example internal layout (not 100% accurate but conceptually correct):

```
struct malloc_chunk {
    size_t size;         // chunk size + flags
    struct malloc_chunk* fd;   // forward pointer (free list)
    struct malloc_chunk* bk;   // backward pointer
};
```

---

# 🔍 The Heap and Free List Visualization

Let’s imagine the heap looks like this:

```
HEAP:
+--------+--------+--------+--------+
| chunk1 | chunk2 | chunk3 | chunk4 |
+--------+--------+--------+--------+
```

Some chunks are **allocated**, others are **free**.

### Free chunks are linked into a **free list**:

```
free_list:
 chunk2 → chunk4 → NULL
```

---

## ✨ What happens during `malloc(size)`?

1. Find a free chunk in free list large enough.
2. If chunk is bigger than needed → **split it**.
3. Mark chunk as “in use”.
4. Return pointer to user data.

Example:

```
Before:
[free: 100 bytes] → [free: 30 bytes]

malloc(20):
- finds 30 bytes
- splits to 20 (used) + 10 (free)

After:
[free: 100] → [used: 20] → [free: 10]
```

---

## ✨ What happens during `free(ptr)`?

1. Convert pointer back to chunk ⇒ read metadata.
2. Mark chunk as free.
3. Insert into free list.
4. Attempt **coalescing** with adjacent free blocks.

Example (coalescing):

```
Before:
[free: 50][used: 20][free: 30]

free(used:20) →
[free: 50][free: 20][free: 30]

Coalesce →
[free: 100]
```

---

## ✨ What happens during `realloc(ptr, new_size)`?

Case 1 — new_size fits in current chunk

```
Resize in place → return same pointer
```

Case 2 — next chunk is free → merge chunks

```
Expand in place
```

Case 3 — cannot grow → allocate new block → copy → free old

```
new_ptr = malloc(new_size)
memcpy(new_ptr, old_ptr)
free(old_ptr)
```

---

# ⭐ Summary Table

| Function  | Initializes? | Moves Memory? | Common Use                       |
| --------- | ------------ | ------------- | -------------------------------- |
| `malloc`  | ❌ No         | ❌ No          | general allocation               |
| `calloc`  | ✔ Zeroed     | ❌ No          | arrays, avoid uninitialized bugs |
| `realloc` | N/A          | ✔ Sometimes   | resizing dynamic arrays          |

---

# Want deeper internals?

I can show:

✔ Glibc `ptmalloc2` bin lists (fast bins, small bins, large bins)
✔ How `sbrk()` and `mmap()` are used
✔ Detailed chunk layout diagrams
✔ Why malloc is O(1) amortized
✔ A minimal custom allocator implementation

Just tell me if you'd like the **full deep dive**.
