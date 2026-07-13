The GCC/G++ command line consists of many categories of options. Understanding them will help you read Makefiles, CMake-generated commands, and build logs.

A typical compile command looks like:

```bash
g++ -std=c++20 -O2 -Wall -Wextra -Iinclude \
    -DDEBUG \
    -c main.cpp \
    -o main.o
```

And linking:

```bash
g++ main.o utils.o \
    -L/usr/local/lib \
    -lmylib \
    -lpthread \
    -o app
```

Let's go through the most common options.

---

# 1. `-D` : Define a preprocessor macro

Equivalent to writing `#define`.

```bash
g++ -DDEBUG main.cpp
```

is the same as:

```cpp
#define DEBUG
```

before the compiler reads your source.

You can also define values.

```bash
g++ -DVERSION=3
```

becomes

```cpp
#define VERSION 3
```

Example:

```cpp
#include <iostream>

int main() {
#ifdef DEBUG
    std::cout << "Debug build\n";
#endif

    std::cout << VERSION << '\n';
}
```

Compile

```bash
g++ main.cpp -DDEBUG -DVERSION=5
```

Output

```
Debug build
5
```

---

# 2. `-I` : Add include directory

Suppose

```
project/
    include/
        math.hpp
    src/
        main.cpp
```

Compile

```bash
g++ src/main.cpp -Iinclude
```

Now

```cpp
#include "math.hpp"
```

works.

Without `-I`, GCC only searches standard include paths and the current source directory.

You can specify multiple directories.

```bash
-Iinclude
-Ithird_party/json
```

---

# 3. `-L` : Add library search path

Used during linking.

Suppose

```
/opt/mylib/lib/libabc.a
```

Compile

```bash
g++ main.o -L/opt/mylib/lib
```

Now GCC knows where to search for libraries.

---

# 4. `-l` : Link a library

This is one of the most common options.

Suppose the directory contains

```
libmath.a
```

or

```
libmath.so
```

You write

```bash
-lmath
```

NOT

```bash
-llibmath
```

The linker automatically adds

```
lib
```

prefix and

```
.a
```

or

```
.so
```

suffix.

Example

```
-lpthread
```

searches

```
libpthread.so
```

or

```
libpthread.a
```

Example

```bash
g++ main.o -L/usr/local/lib -lfoo
```

Searches

```
/usr/local/lib/libfoo.so
```

or

```
libfoo.a
```

---

# 5. `-W` : Warning options

Warnings are compiler diagnostics.

Example

```bash
-Wall
```

Enable most common warnings.

Common ones:

```
-Wall
```

Basic warnings.

```
-Wextra
```

Additional warnings.

```
-Werror
```

Treat warnings as errors.

```
-Wshadow
```

Warn if a variable shadows another.

```
-Wconversion
```

Warn on implicit conversions.

```
-Wunused
```

Warn about unused variables/functions.

Example

```cpp
int x;
```

Compile

```bash
g++ -Wall
```

Output

```
warning: unused variable 'x'
```

---

# 6. `-O` : Optimization

Optimization level.

```
-O0
```

No optimization (best for debugging)

```
-O1
```

Light optimization

```
-O2
```

Most common production optimization

```
-O3
```

Aggressive optimization

```
-Os
```

Optimize for size

```
-Og
```

Optimize while preserving debugging quality

---

# 7. `-g` : Generate debug information

Allows GDB to understand your program.

```bash
g++ -g
```

Without it

```
(gdb) bt
```

may show

```
0x400123
```

With it

```
main() at main.cpp:45
```

---

# 8. `-c` : Compile only

Produces object files.

```bash
g++ -c main.cpp
```

Produces

```
main.o
```

No linking.

Useful for large projects.

---

# 9. `-o` : Output filename

Instead of

```
a.out
```

you specify

```bash
g++ main.cpp -o hello
```

Produces

```
hello
```

---

# 10. `-E` : Preprocessing only

Stops after preprocessing.

```bash
g++ -E main.cpp
```

Shows

* expanded headers
* expanded macros

Useful for debugging macros.

---

# 11. `-S` : Produce assembly

```bash
g++ -S main.cpp
```

Produces

```
main.s
```

---

# 12. `-std=` : Select language standard

Examples

```
-std=c11
```

```
-std=c17
```

```
-std=c++11
```

```
-std=c++17
```

```
-std=c++20
```

```
-std=c++23
```

---

# 13. `-shared`

Build shared libraries.

```bash
g++ -shared foo.o -o libfoo.so
```

---

# 14. `-fPIC`

Generate Position Independent Code.

Required for shared libraries on most Unix systems.

```bash
g++ -fPIC
```

---

# 15. `-Winvalid-pch`

Useful when using precompiled headers.

---

# 16. `-Winvalid-offsetof`

Checks invalid use of `offsetof`.

---

# 17. `-fno-exceptions`

Disable C++ exception support.

Common in embedded systems.

---

# 18. `-fno-rtti`

Disable Run-Time Type Information.

Removes support for

```cpp
dynamic_cast
typeid
```

Useful in embedded applications to reduce code size.

---

# 19. `-Winvalid-constexpr`

Warn about invalid `constexpr`.

---

# 20. `-pthread`

One of the most misunderstood options.

```bash
g++ main.cpp -pthread
```

This does **more than** `-lpthread`:

* links pthread library
* defines thread-related macros during compilation
* enables correct compiler behavior for multithreaded programs

Whenever compiling POSIX threads, use

```bash
-pthread
```

rather than manually specifying `-lpthread`.

---

# 21. `-M*` : Generate dependency files

Common with Make.

```bash
-MMD
-MP
```

Generate `.d` dependency files automatically.

---

# 22. `-march`

Target CPU architecture.

Example

```bash
-march=native
```

Optimize for the current machine.

Embedded example

```bash
-mcpu=cortex-m33
```

---

# 23. `-mthumb`

Generate Thumb instructions for ARM Cortex-M processors.

---

# 24. `-ffunction-sections` and `-fdata-sections`

Place each function and global variable into its own ELF section.

Together with the linker option

```bash
-Wl,--gc-sections
```

the linker can remove unused code and data, significantly reducing binary size in embedded projects.

---

# 25. `-Wl,`

Pass options directly to the **linker** (`ld`).

Example:

```bash
g++ main.o -Wl,--gc-sections
```

Here:

* `-Wl,` means "the following comma-separated arguments are for the linker"
* `--gc-sections` tells the linker to discard unused sections (often used with `-ffunction-sections` and `-fdata-sections`).

Similarly:

* `-Wa,` passes options to the assembler.
* `-Wp,` passes options to the preprocessor.

# A typical C++ project compile command

```bash
g++ \
    -std=c++20 \
    -O2 \
    -g \
    -Wall -Wextra \
    -Iinclude \
    -DDEBUG \
    -c main.cpp \
    -o main.o
```

Link:

```bash
g++ \
    main.o utils.o \
    -L/usr/local/lib \
    -lmylib \
    -pthread \
    -o app
```

# GCC option categories

| Prefix  | Meaning                          | Example                       |
| ------- | -------------------------------- | ----------------------------- |
| `-D`    | Define preprocessor macro        | `-DDEBUG`                     |
| `-U`    | Undefine macro                   | `-UDEBUG`                     |
| `-I`    | Add header search path           | `-Iinclude`                   |
| `-L`    | Add library search path          | `-L/usr/lib`                  |
| `-l`    | Link library                     | `-lpthread`                   |
| `-W`    | Enable/configure warnings        | `-Wall`                       |
| `-Wl,`  | Pass options to the linker       | `-Wl,--gc-sections`           |
| `-Wa,`  | Pass options to the assembler    | `-Wa,-adhln`                  |
| `-Wp,`  | Pass options to the preprocessor | `-Wp,-v`                      |
| `-f`    | Compiler feature flags           | `-fPIC`, `-fno-rtti`          |
| `-m`    | Target machine/architecture      | `-mcpu=cortex-m33`, `-mthumb` |
| `-O`    | Optimization level               | `-O2`                         |
| `-g`    | Debug information                | `-g`                          |
| `-std=` | Language standard                | `-std=c++20`                  |
| `-c`    | Compile without linking          | `-c`                          |
| `-S`    | Generate assembly                | `-S`                          |
| `-E`    | Preprocess only                  | `-E`                          |
| `-o`    | Specify output file              | `-o app`                      |

Once you're comfortable with these options, you'll be able to read almost any GCC command line, including those generated by CMake, Make, and embedded SDKs such as the Raspberry Pi Pico SDK.
