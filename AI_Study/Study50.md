Cool question. This is one of those “every C dev should peek under the hood at least once” topics 🙂

Below is a **minimal, educational implementation** of `malloc`, `calloc`, and `realloc`.
⚠️ **Important upfront**: this is **NOT production-quality**. Real `malloc` (glibc, jemalloc, musl) is *far* more complex (thread safety, arenas, mmap, coalescing, security, performance).

---

## Big picture (how it works)

We’ll build a **very simple heap allocator** using:

* `sbrk()` to request memory from the OS
* A **linked list of blocks**
* Each block has:

  * size
  * free / used flag
  * pointer to next block

Memory layout in RAM:

```
+-----------+--------------------+
| header    | user data           |
+-----------+--------------------+
```

---

## Block metadata

```c
#include <unistd.h>
#include <string.h>
#include <stddef.h>

typedef struct block {
    size_t size;
    int free;
    struct block *next;
} block_t;

#define BLOCK_SIZE sizeof(block_t)

static block_t *free_list = NULL;
```

---

## Helper: find a free block

```c
static block_t *find_free_block(size_t size) {
    block_t *curr = free_list;
    while (curr) {
        if (curr->free && curr->size >= size)
            return curr;
        curr = curr->next;
    }
    return NULL;
}
```

---

## Helper: request memory from OS

```c
static block_t *request_space(block_t *last, size_t size) {
    block_t *block = sbrk(0);
    void *request = sbrk(size + BLOCK_SIZE);
    if (request == (void *) -1)
        return NULL;

    if (last)
        last->next = block;

    block->size = size;
    block->free = 0;
    block->next = NULL;
    return block;
}
```

---

## `malloc` implementation

```c
void *malloc(size_t size) {
    if (size == 0)
        return NULL;

    block_t *block;

    if (!free_list) {
        // first call
        block = request_space(NULL, size);
        if (!block)
            return NULL;
        free_list = block;
    } else {
        block_t *last = free_list;
        block = find_free_block(size);
        if (!block) {
            // no free block found, extend heap
            while (last->next)
                last = last->next;
            block = request_space(last, size);
            if (!block)
                return NULL;
        } else {
            block->free = 0;
        }
    }

    // return pointer to user data
    return (block + 1);
}
```

---

## `free` implementation

```c
void free(void *ptr) {
    if (!ptr)
        return;

    block_t *block = (block_t *)ptr - 1;
    block->free = 1;

    // No coalescing in this simple version
}
```

---

## `calloc` implementation

`calloc = malloc + memset(0)`

```c
void *calloc(size_t nmemb, size_t size) {
    size_t total = nmemb * size;
    void *ptr = malloc(total);
    if (!ptr)
        return NULL;

    memset(ptr, 0, total);
    return ptr;
}
```

---

## `realloc` implementation

```c
void *realloc(void *ptr, size_t size) {
    if (!ptr)
        return malloc(size);

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    block_t *block = (block_t *)ptr - 1;

    if (block->size >= size) {
        // old block is big enough
        return ptr;
    }

    // allocate new block
    void *new_ptr = malloc(size);
    if (!new_ptr)
        return NULL;

    memcpy(new_ptr, ptr, block->size);
    free(ptr);
    return new_ptr;
}
```

---

## What this implementation is missing (important!)

Real allocators also do:

* 🔒 Thread safety (locks / per-thread arenas)
* 🧩 Block splitting & coalescing
* 📏 Alignment (8 / 16 bytes)
* 🧠 `mmap()` for large allocations
* 🚀 Fast bins / size classes
* 🛡️ Security hardening (ASLR, canaries)

---

## Interview gold nuggets 💡

* `malloc` **does NOT zero memory**
* `calloc` **must zero memory**
* `realloc(ptr, 0)` ≈ `free(ptr)`
* `realloc(NULL, size)` ≈ `malloc(size)`
* Heap metadata lives **before** user pointer

---

If you want, next we can:

* add **block splitting**
* implement **coalescing**
* compare this with **glibc malloc**
* or walk through `malloc` using `gdb`

Just say the word 👀
