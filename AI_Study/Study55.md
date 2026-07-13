These are two related but separate questions. Let's look at them one by one.

---

# 1. Why does dereferencing a null pointer cause a segmentation fault?

## What is a null pointer?

A null pointer is a pointer that intentionally points to **no valid object**.

```cpp
int* p = nullptr;
```

or in older code:

```cpp
int* p = NULL;
```

The pointer does **not** point to an integer in memory.

---

## What happens when you dereference it?

```cpp
int* p = nullptr;
*p = 10;
```

The CPU must perform a memory write.

Conceptually, the generated assembly looks like

```asm
MOV [address], 10
```

where

```
address = 0
```

because the pointer contains the null address.

The CPU tries to write to memory address 0.

---

## Why is address 0 invalid?

Modern operating systems use **virtual memory**.

Each process gets its own virtual address space.

```
+--------------------+
| High memory        |
|                    |
| Program            |
| Heap               |
|                    |
|                    |
| Stack              |
+--------------------+
| Address 0          |  <-- intentionally left unmapped
+--------------------+
```

Notice that page 0 is deliberately **not mapped**.

When the CPU accesses it,

```
Memory Management Unit (MMU)
        ↓
No valid page found
        ↓
Page Fault Exception
        ↓
Operating System
        ↓
SIGSEGV (Segmentation Fault)
```

The operating system terminates the program because it attempted to access memory it doesn't own.

---

## Is it guaranteed to be a segmentation fault?

No.

According to the C++ standard:

Dereferencing a null pointer is **undefined behavior (UB)**.

That means **anything may happen**.

Examples:

* segmentation fault (most common)
* access violation (Windows)
* silent corruption
* strange output
* optimizer removes code
* program appears to work

The standard intentionally doesn't specify the result.

The operating system usually turns it into a segmentation fault because address 0 is protected.

---

## Example

```cpp
#include <iostream>

int main()
{
    int* p = nullptr;
    std::cout << *p;
}
```

Typical output

```
Segmentation fault (core dumped)
```

---

# 2. Why is `nullptr` preferred over `NULL`?

Because `NULL` is **not actually a pointer**.

Historically, in C,

```cpp
#define NULL 0
```

or

```cpp
#define NULL ((void*)0)
```

depending on the implementation.

In C++, it is almost always

```cpp
#define NULL 0
```

So

```cpp
int* p = NULL;
```

is really

```cpp
int* p = 0;
```

The compiler treats integer literal `0` specially as a null pointer constant.

---

## The problem with `NULL`

Consider overloaded functions.

```cpp
void f(int);
void f(char*);
```

Now call

```cpp
f(NULL);
```

If

```cpp
NULL == 0
```

then the compiler sees

```cpp
f(0);
```

It chooses

```cpp
f(int)
```

which is probably **not what you intended**.

---

### Example

```cpp
void print(int)
{
    std::cout << "int\n";
}

void print(char*)
{
    std::cout << "pointer\n";
}

print(NULL);
```

Output

```
int
```

The pointer overload isn't selected.

---

# `nullptr` fixes this

C++11 introduced

```cpp
nullptr
```

whose type is

```cpp
std::nullptr_t
```

It is **not an integer**.

Now

```cpp
print(nullptr);
```

Output

```
pointer
```

Exactly what we wanted.

---

# More examples

## Example 1

```cpp
int* p = nullptr;
```

Clear.

---

## Example 2

```cpp
if (p == nullptr)
```

Very readable.

---

## Example 3

```cpp
foo(nullptr);
```

The compiler knows you mean

> "I am passing a null pointer."

Not

> "I am passing integer zero."

---

# Type safety

```cpp
auto x = NULL;
```

Usually

```cpp
int
```

But

```cpp
auto y = nullptr;
```

becomes

```cpp
std::nullptr_t
```

Much safer.

---

# Implicit conversions

`nullptr` can convert to **any pointer type**:

```cpp
int* p = nullptr;
double* q = nullptr;
char* r = nullptr;
```

but **not** to arbitrary integers.

```cpp
int x = nullptr;   // Error
```

This prevents accidental misuse.

---

# Comparison

| Feature                                  | `NULL`            | `nullptr`        |
| ---------------------------------------- | ----------------- | ---------------- |
| Introduced                               | C                 | C++11            |
| Usually defined as                       | `0`               | Keyword          |
| Type                                     | `int` (typically) | `std::nullptr_t` |
| Represents null pointer                  | Yes               | Yes              |
| Type-safe                                | No                | Yes              |
| Works correctly with overload resolution | No                | Yes              |
| Preferred in modern C++                  | ❌                 | ✅                |

---

## Best practice

In modern C++ (C++11 and later), prefer `nullptr` whenever you need a null pointer:

```cpp
int* p = nullptr;

if (p == nullptr) {
    // handle empty pointer
}
```

Reserve `NULL` only when maintaining legacy C or pre-C++11 code. `nullptr` provides stronger type safety, avoids overload ambiguities, and makes your intent explicit.
