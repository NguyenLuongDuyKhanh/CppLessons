`custom deleter` and `custom allocator` are two different customization mechanisms in C++. They solve different problems:

* **Custom deleter**: controls **how an object is destroyed**.
* **Custom allocator**: controls **where and how memory is allocated**.

These are advanced features, but they become extremely useful in systems programming, embedded software, game engines, and high-performance servers.

---

# 1. Custom Deleter

Normally, a `std::unique_ptr` destroys its object by calling

```cpp
delete ptr;
```

Sometimes that isn't correct.

For example:

* `FILE*` must be destroyed with `fclose()`
* `malloc()` memory must use `free()`
* sockets require `close()`
* OpenSSL objects require `SSL_free()`
* SQLite objects require `sqlite3_close()`

A custom deleter tells the smart pointer what function to call instead of `delete`.

---

## Example 1: FILE*

Without smart pointer

```cpp
FILE* file = fopen("test.txt", "r");

if (file)
{
    // use file

    fclose(file);
}
```

If an exception occurs, `fclose()` may never execute.

Instead:

```cpp
#include <memory>
#include <cstdio>

auto deleter = [](FILE* f)
{
    if (f)
        fclose(f);
};

std::unique_ptr<FILE, decltype(deleter)>
    file(fopen("test.txt", "r"), deleter);
```

Now

```cpp
file
```

automatically calls

```cpp
fclose(file.get());
```

when leaving scope.

---

## Example 2: malloc/free

Wrong:

```cpp
int* p = (int*)malloc(100);

std::unique_ptr<int> ptr(p);      // WRONG
```

because

```cpp
unique_ptr
```

will execute

```cpp
delete p;
```

instead of

```cpp
free(p);
```

Correct:

```cpp
auto deleter = [](int* p)
{
    free(p);
};

std::unique_ptr<int, decltype(deleter)>
    ptr((int*)malloc(100), deleter);
```

---

## Example 3: POSIX socket

```cpp
int sock = socket(...);
```

must be released with

```cpp
close(sock);
```

Since a socket is just an integer, one approach is to wrap it:

```cpp
struct Socket
{
    int fd;
};

struct SocketCloser
{
    void operator()(Socket* s) const
    {
        close(s->fd);
        delete s;
    }
};

std::unique_ptr<Socket, SocketCloser> sock(new Socket{fd});
```

When destroyed:

```
SocketCloser::operator()
        ↓
close(fd)
delete socket_object
```

---

# How unique_ptr stores the deleter

A `unique_ptr` actually looks conceptually like

```cpp
template<class T, class D>
class unique_ptr
{
    T* ptr;
    D deleter;
};
```

Notice it stores

* pointer
* deleter

Therefore

```cpp
std::unique_ptr<int>
```

and

```cpp
std::unique_ptr<int, MyDeleter>
```

are different types.

---

## Functor deleter

```cpp
struct MyDeleter
{
    void operator()(int* p) const
    {
        std::cout << "Deleting\n";
        delete p;
    }
};

std::unique_ptr<int, MyDeleter> p(new int(5));
```

Output

```
Deleting
```

---

## Function pointer deleter

```cpp
void myDelete(int* p)
{
    delete p;
}

std::unique_ptr<int, void(*)(int*)>
    ptr(new int(10), myDelete);
```

---

## Lambda deleter

Most common.

```cpp
auto d = [](int* p)
{
    delete p;
};

std::unique_ptr<int, decltype(d)>
    ptr(new int(5), d);
```

---

# shared_ptr custom deleter

Unlike `unique_ptr`, the deleter is stored inside the control block.

```cpp
auto ptr = std::shared_ptr<FILE>(
    fopen("a.txt","r"),
    [](FILE* f)
    {
        fclose(f);
    });
```

Notice:

```cpp
std::shared_ptr<FILE>
```

doesn't expose the deleter type.

---

# 2. Custom Allocator

Now let's discuss allocators.

Instead of changing destruction, allocators change **memory allocation**.

Normally

```cpp
std::vector<int> v;
```

allocates memory using

```cpp
operator new
```

internally.

Sometimes you want memory from:

* memory pool
* shared memory
* DMA buffer
* stack
* huge pages
* GPU memory

An allocator controls this.

---

## Default allocator

```cpp
std::vector<int>
```

really means

```cpp
std::vector<int, std::allocator<int>>
```

The second template parameter is the allocator.

---

## Very simple allocator

```cpp
template<typename T>
struct MyAllocator
{
    using value_type = T;

    MyAllocator() = default;

    template<typename U>
    MyAllocator(const MyAllocator<U>&) {}

    T* allocate(std::size_t n)
    {
        std::cout << "Allocating "
                  << n
                  << " objects\n";

        return static_cast<T*>(
            ::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t)
    {
        std::cout << "Freeing\n";

        ::operator delete(p);
    }
};
```

Now

```cpp
std::vector<int, MyAllocator<int>> vec;

vec.push_back(10);
vec.push_back(20);
```

Possible output

```
Allocating 1 objects
Allocating 2 objects
Freeing
```

because the vector grows.

---

# Memory Pool Allocator

Suppose you have

```cpp
1000000
```

small objects.

Doing

```
new
delete
new
delete
```

becomes expensive.

Instead:

```
Large Pool
+-----------------------------------+
| object | object | object | object |
+-----------------------------------+
```

Allocation simply advances a pointer.

```
next += sizeof(object)
```

Very fast.

Game engines use this heavily.

---

# Embedded example

Suppose dynamic memory is forbidden.

Instead:

```cpp
char buffer[4096];
```

Your allocator hands out memory from this array.

```
buffer
+-------------------------------------+
| obj | obj | obj | obj | obj | free |
+-------------------------------------+
```

No heap involved.

---

# Shared memory allocator

Processes A and B share

```
+----------------------+
| Shared Memory Region |
+----------------------+
```

An allocator returns memory inside this region so STL containers can live in shared memory.

---

# Relationship between allocator and deleter

| Feature      | Custom Deleter                             | Custom Allocator                              |
| ------------ | ------------------------------------------ | --------------------------------------------- |
| Controls     | Object destruction                         | Memory allocation                             |
| Used by      | `unique_ptr`, `shared_ptr`                 | STL containers                                |
| Replaces     | `delete`                                   | `operator new`                                |
| Typical use  | `fclose`, `free`, `close`, library cleanup | Memory pools, embedded systems, shared memory |
| Invoked when | Smart pointer is destroyed                 | Container needs more memory                   |

---

# Which one should you learn first?

For most C++ developers, the recommended order is:

1. RAII
2. `std::unique_ptr`
3. `std::shared_ptr`
4. **Custom deleters** (commonly used with C libraries and system resources)
5. `std::pmr` (Polymorphic Memory Resources, C++17) for modern memory management
6. Traditional allocator model (`std::allocator` and custom allocators), which is useful but more complex and less commonly implemented directly in modern code

Unless you're writing low-level libraries or performance-critical systems, you'll encounter custom deleters much more often than you'll need to write a custom allocator from scratch. Modern C++ code increasingly favors the `std::pmr` library over bespoke allocator implementations because it separates allocation strategy from container types and is easier to use and compose.
