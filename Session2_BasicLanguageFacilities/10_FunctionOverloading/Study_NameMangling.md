This direction is **much simpler** than C → C++, but there are still a couple of sharp edges. Let’s do it cleanly and *correctly*.

---

## 1. The short answer

👉 **C++ can call C functions directly**
👉 You just need to tell the C++ compiler: *“this function has C linkage”*

You do that with:

```cpp
extern "C"
```

---

## 2. The correct, portable pattern (MOST IMPORTANT)

### 2.1 C header (written in C style)

`math.h`

```c
#ifndef MATH_H
#define MATH_H

int add(int a, int b);

#endif
```

---

### 2.2 C implementation

`math.c`

```c
#include "math.h"

int add(int a, int b) {
    return a + b;
}
```

---

### 2.3 C++ code calling C function

### Option A (❌ NOT recommended)

```cpp
extern "C" int add(int, int);

int main() {
    add(1, 2);
}
```

Works, but **bad for maintenance**.

---

### Option B (✅ BEST PRACTICE)

Wrap `extern "C"` *inside the header*:

```c
#ifndef MATH_H
#define MATH_H

#ifdef __cplusplus
extern "C" {
#endif

int add(int a, int b);

#ifdef __cplusplus
}
#endif

#endif
```

Now in C++:

```cpp
#include "math.h"

int main() {
    add(1, 2);
}
```

✔ Same header works for **both C and C++**

---

## 3. Why is `extern "C"` needed?

C++ uses **name mangling** to support:

* function overloading
* namespaces
* templates

C does not.

Without `extern "C"`:

```cpp
int add(int, int);
```

Becomes:

```
_Z3addii
```

But C produces:

```
add
```

➡️ Linker error unless linkage is forced to C.

---

## 4. Compilation & linking (common pitfall)

```bash
gcc -c math.c
g++ -c main.cpp
g++ main.o math.o -o app
```

⚠️ Always **link with `g++`**, not `gcc`, when C++ is involved.

---

## 5. What C++ can call from C (safe)

✔ Free functions
✔ Global variables
✔ Plain structs (`POD`)
✔ Enums
✔ Function pointers

Example:

```c
typedef struct {
    int x;
    int y;
} Point;

int sum(Point p);
```

Works perfectly in C++.

---

## 6. What C++ must NOT expect from C

❌ Overloading
❌ Namespaces
❌ References
❌ Classes
❌ Exceptions

C++ must adapt to C, not the other way around.

---

## 7. C standard library is already C-compatible

That’s why this works without effort:

```cpp
#include <stdio.h>
#include <string.h>
```

These headers already do:

```c
#ifdef __cplusplus
extern "C" {
#endif
```

internally.

---

## 8. Global variables example

C:

```c
int counter = 0;
```

C++:

```cpp
extern "C" int counter;
```

---

## 9. Function pointers (advanced / embedded)

C:

```c
typedef int (*func_t)(int);
int square(int x);
```

C++:

```cpp
extern "C" int square(int);
```

Works exactly the same.

---

## 10. Interview one-liner 🎯

> C++ can call C functions directly by declaring them with `extern "C"` so the C++ compiler uses C linkage instead of name mangling.

---

If you want next:

* **Mixing C and C++ in shared libraries**
* **ABI compatibility pitfalls**
* **Embedded / Linux build systems**
* **Real linker error debugging (`nm`, `ldd`)**

Just tell me 👌
