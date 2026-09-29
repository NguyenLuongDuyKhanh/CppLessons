`std::pmr` (Polymorphic Memory Resources), introduced in **C++17**, solves a major usability problem with traditional allocators.

Instead of making the allocator part of a container's type:

```cpp
std::vector<int, MyAllocator<int>>
```

you write:

```cpp
std::pmr::vector<int>
```

and choose the memory resource **at runtime**.

This separation makes code much easier to write and reuse.

---

# Example 1: Allocate from a stack buffer (Embedded)

Suppose your system forbids heap allocation.

Without `std::pmr`, you'd have to implement a custom allocator.

With `std::pmr`:

```cpp
#include <memory_resource>
#include <vector>
#include <iostream>

int main()
{
    std::byte buffer[1024];

    std::pmr::monotonic_buffer_resource pool(buffer, sizeof(buffer));

    std::pmr::vector<int> numbers(&pool);

    for (int i = 0; i < 100; i++)
        numbers.push_back(i);

    std::cout << numbers.size() << '\n';
}
```

### What happens?

```
buffer (1024 bytes)

+-----------------------------------------------------+
| vector storage | more storage | more storage | free |
+-----------------------------------------------------+
```

No heap allocation occurs **as long as the buffer is large enough**.

---

# Example 2: Many temporary objects

Suppose you're parsing a JSON document.

During parsing you create thousands of temporary strings.

Normal allocation:

```
new
delete
new
delete
new
delete
...
```

Very expensive.

Instead:

```cpp
std::pmr::monotonic_buffer_resource pool;

std::pmr::string name(&pool);
std::pmr::string city(&pool);
std::pmr::vector<std::pmr::string> words(&pool);
```

Every allocation comes from the same pool.

When parsing finishes:

```cpp
pool.release();
```

Everything is freed at once.

No thousands of individual `delete`s.

---

# Example 3: One resource shared by many containers

```cpp
#include <memory_resource>

std::pmr::monotonic_buffer_resource pool;

std::pmr::vector<int> numbers(&pool);

std::pmr::string message(&pool);

std::pmr::list<double> values(&pool);
```

All three containers allocate from:

```
                pool
                  │
        ┌─────────┼─────────┐
        │         │         │
    vector     string      list
```

When the pool dies:

Everything disappears together.

---

# Example 4: Logging allocations

Suppose you want to know who is allocating memory.

Derive your own resource:

```cpp
#include <memory_resource>
#include <iostream>

class LoggingResource : public std::pmr::memory_resource
{
protected:
    void* do_allocate(size_t bytes, size_t alignment) override
    {
        std::cout << "Allocate "
                  << bytes
                  << " bytes\n";

        return std::pmr::new_delete_resource()
            ->allocate(bytes, alignment);
    }

    void do_deallocate(
        void* p,
        size_t bytes,
        size_t alignment) override
    {
        std::cout << "Free "
                  << bytes
                  << " bytes\n";

        std::pmr::new_delete_resource()
            ->deallocate(p, bytes, alignment);
    }

    bool do_is_equal(
        const memory_resource& other) const noexcept override
    {
        return this == &other;
    }
};
```

Use it:

```cpp
LoggingResource log;

std::pmr::vector<int> v(&log);

for (int i = 0; i < 100; i++)
    v.push_back(i);
```

Possible output:

```
Allocate 4 bytes
Allocate 8 bytes
Free 4 bytes
Allocate 16 bytes
Free 8 bytes
...
```

Great for profiling and debugging memory usage.

---

# Example 5: Fast request handling in a web server

Imagine a server handling one HTTP request:

```
Request arrives
```

It creates:

* URL
* Headers
* Cookies
* JSON body
* Query parameters
* Temporary strings

Instead of:

```
new
new
new
delete
delete
delete
```

Create one pool:

```cpp
std::pmr::monotonic_buffer_resource requestPool;
```

Everything for this request uses it:

```cpp
std::pmr::string url(&requestPool);

std::pmr::vector<std::pmr::string> headers(&requestPool);

std::pmr::unordered_map<
    std::pmr::string,
    std::pmr::string> cookies(&requestPool);
```

When the request ends:

```cpp
requestPool.release();
```

All memory is reclaimed in one operation.

This pattern is common in high-performance servers because it reduces allocation overhead and fragmentation.

---

# Example 6: Different resources without changing container types

This is where `std::pmr` really shines.

```cpp
std::pmr::monotonic_buffer_resource fastPool;

std::pmr::unsynchronized_pool_resource pool;

std::pmr::vector<int> a(&fastPool);

std::pmr::vector<int> b(&pool);
```

Notice:

Both variables have the **same type**:

```cpp
std::pmr::vector<int>
```

The allocation strategy changes at runtime via the supplied memory resource. With traditional allocators, different allocator types would produce different `std::vector` types, making generic code more cumbersome.

---

# The built-in memory resources

The standard library provides several useful resources:

| Resource                       | Best for                             | Behavior                                                               |
| ------------------------------ | ------------------------------------ | ---------------------------------------------------------------------- |
| `new_delete_resource()`        | Default behavior                     | Uses global `new`/`delete`                                             |
| `null_memory_resource()`       | Detect unexpected allocations        | Every allocation request throws `std::bad_alloc`                       |
| `monotonic_buffer_resource`    | Temporary objects                    | Allocates, never frees individual blocks; releases everything together |
| `unsynchronized_pool_resource` | Single-threaded frequent allocations | Reuses freed blocks; no locking                                        |
| `synchronized_pool_resource`   | Multi-threaded frequent allocations  | Like `unsynchronized_pool_resource`, but thread-safe                   |

---

# When is `std::pmr` worth using?

`std::pmr` is especially useful when:

* You create **many temporary objects** with the same lifetime (parsers, compilers, request handlers).
* You want to **avoid heap fragmentation**.
* You need **predictable allocation behavior** in embedded or real-time systems.
* You want to **profile or customize allocation** without changing container types.
* You have **multiple containers** that should all allocate from the same memory pool.

For ordinary desktop applications with relatively few allocations, the default allocator is usually sufficient. `std::pmr` becomes most valuable when allocation performance or memory behavior is a significant concern.
