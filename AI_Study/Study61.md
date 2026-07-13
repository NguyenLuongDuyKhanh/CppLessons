`static` is one of the most confusing keywords in C because it has **different meanings depending on where it is used**.

The easiest way to understand it is to separate it into two concepts:

1. **Storage duration** (how long the object exists)
2. **Linkage** (whether other source files can see the symbol)

Let's build this step by step.

---

# 1. Storage duration

A variable can have one of two lifetimes.

## Automatic storage

Created when execution enters a block and destroyed when leaving it.

```c
void func()
{
    int x = 5;
}
```

```
func()
{
    x created
    ...
}
x destroyed
```

Every call gets a new `x`.

---

## Static storage

Exists for the entire lifetime of the program.

Created before `main()` starts.

Destroyed after the program exits.

```c
int g = 10;
```

or

```c
void func()
{
    static int counter = 0;
}
```

Both variables exist from program startup until termination.

---

# 2. Linkage

Linkage determines whether a symbol is visible outside the current source file.

There are three possibilities.

* external linkage
* internal linkage
* no linkage

---

# Global variables

Suppose we have

```c
int x = 5;
```

outside every function.

By default:

* static storage
* external linkage

Meaning

* lives forever
* other source files can use it

```
file1.c

int x = 5;
```

```
file2.c

extern int x;
```

Works.

---

# static global variable

```c
static int x = 5;
```

Now

* static storage
* **internal linkage**

Meaning

* still lives forever
* invisible outside this file

Only code inside this source file can access it.

---

Imagine

```
file1.c

static int secret = 5;
```

```
file2.c

extern int secret;
```

Linker:

```
undefined reference
```

because `secret` is hidden.

---

# extern

`extern` tells the compiler

> This variable exists somewhere else.

Example

```
file1.c

int count = 0;
```

```
file2.c

extern int count;
```

No new variable is created.

Both files refer to the same memory.

Memory

```
count
+-----+
|  0  |
+-----+

file1 ----+
           |
file2 -----+
```

---

# static inside functions

This is where many beginners get confused.

Example

```c
void func()
{
    static int counter = 0;

    counter++;

    printf("%d\n", counter);
}
```

Calling

```c
func();
func();
func();
```

prints

```
1
2
3
```

because

`counter` is **not recreated** every call.

Memory

```
Program starts

counter
+------+
|  0   |
+------+

Call #1

+------+
|  1   |
+------+

Call #2

+------+
|  2   |
+------+
```

Compare with

```c
void func()
{
    int counter = 0;

    counter++;

    printf("%d\n", counter);
}
```

Output

```
1
1
1
```

because a new variable is created every call.

---

# static local variable

Characteristics

* scope = current function only
* lifetime = entire program

So

```
scope
```

is local

while

```
lifetime
```

is global.

These are different concepts.

---

# static functions

Functions normally have external linkage.

Example

```
file1.c

void helper()
{
}
```

Other files can declare

```c
extern void helper();
```

and call it.

---

If you write

```c
static void helper()
{
}
```

then

```
helper
```

is visible only inside that source file.

This is extremely common for helper functions.

Example

```
math.c

static int gcd(...)
{
}

int calculate(...)
{
    return gcd(...);
}
```

Other files can call

```
calculate()
```

but cannot call

```
gcd()
```

This hides implementation details.

---

# extern functions

Functions are already `extern` by default.

These two are equivalent.

```c
void foo();
```

```c
extern void foo();
```

Usually people don't write `extern` for functions because it's implied.

---

# extern variable declaration

Suppose

```
file1.c
```

```c
int value = 100;
```

In

```
file2.c
```

```c
extern int value;
```

This **does not allocate memory**.

It simply says

> The real variable is elsewhere.

---

If you instead write

```c
int value;
```

in another source file, that is a **tentative definition** in C (which can become a separate definition depending on the language rules and compiler options). In modern C projects, it's common practice to have **exactly one definition** of a global variable and `extern` declarations everywhere else to avoid multiple-definition problems.

A common pattern is:

```c
/* globals.h */
extern int value;
```

```c
/* globals.c */
#include "globals.h"

int value = 100;
```

Any other `.c` file includes `globals.h` and uses the same `value`.

---

# Summary table

| Declaration                       | Scope  | Lifetime                  | Linkage  |
| --------------------------------- | ------ | ------------------------- | -------- |
| `int x;` (inside function)        | Block  | Automatic                 | None     |
| `static int x;` (inside function) | Block  | Entire program            | None     |
| `int x;` (global)                 | File   | Entire program            | External |
| `static int x;` (global)          | File   | Entire program            | Internal |
| `extern int x;`                   | File   | Refers to existing object | External |
| `void f();`                       | Global | Entire program            | External |
| `static void f();`                | File   | Entire program            | Internal |

---

# Visual summary

```
                STORAGE               LINKAGE

Local variable

    int x;

    Lifetime:
        |----function call----|

    Visible:
        only this block


--------------------------------------------

Static local

    static int x;

    Lifetime:
    |----------------program----------------|

    Visible:
        only this block


--------------------------------------------

Global

    int x;

    Lifetime:
    |----------------program----------------|

    Visible:
        every source file (via extern)


--------------------------------------------

Static global

    static int x;

    Lifetime:
    |----------------program----------------|

    Visible:
        this source file only


--------------------------------------------

Extern

    extern int x;

    No storage allocated.

    Refers to an existing global variable defined
    in another translation unit.
```

## A rule of thumb

Think of the keywords this way:

* **`static`**: "Keep it around" (for local variables) or "Keep it private to this source file" (for globals and functions).
* **`extern`**: "This declaration refers to a variable or function that is defined in another translation unit."

Understanding the distinction between **scope** (where a name can be used), **storage duration** (how long an object exists), and **linkage** (whether the name can be referred to from other translation units) makes `static` and `extern` much easier to reason about.
