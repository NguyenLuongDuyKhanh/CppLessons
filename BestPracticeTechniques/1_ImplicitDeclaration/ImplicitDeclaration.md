# Implicit declaration
'''
warning: implicit declaration of function
'''
Ex1 demonstrate an implicit declaration of a function
'''
    @NguyenLuongDuyKhanh ➜ .../CppLessons/BestPracticeTechniques/1_ImplicitDeclaration/Ex1 (main) $ gcc -std=c99 Ex1.c 
    Ex1.c: In function ‘main’:
    Ex1.c:4:18: warning: implicit declaration of function ‘add’ [-Wimplicit-function-declaration]
        4 |     int result = add(2, 3);  // call before declaration
          |                  ^~~
'''
while Ex2 demonstrate the error of undeclare identiifier of a variable
'''
    @NguyenLuongDuyKhanh ➜ .../CppLessons/BestPracticeTechniques/1_ImplicitDeclaration/Ex2 (main) $ gcc -std=c99 Ex2.c 
    Ex2.c: In function ‘main’:
    Ex2.c:4:18: error: ‘c’ undeclared (first use in this function)
        4 |     printf("%d", c);
          |                  ^
    Ex2.c:4:18: note: each undeclared identifier is reported only once for each function it appears in
'''

Sure — let’s go step by step.

---

### 🧩 Example: Implicit Function Declaration in C

Here’s a simple C program that **causes an implicit declaration**:

```c
#include <stdio.h>

int main() {
    int result = add(2, 3);  // call before declaration
    printf("Result: %d\n", result);
    return 0;
}

int add(int a, int b) {
    return a + b;
}
```

---

### ⚠️ What Happens Here

When the compiler sees this line:

```c
int result = add(2, 3);
```

…it hasn’t yet seen a **declaration** or **definition** of the function `add`.

So in **old C standards (C89)**, the compiler **implicitly assumes**:

```c
int add();
```

That’s called an **implicit function declaration** — the compiler guesses the function returns `int`, and takes an unspecified number of parameters.

---

### 🧠 Why It’s a Problem

1. **No type checking** – the compiler doesn’t know the parameter types.
   → If `add()` actually took `double` arguments, you’d get wrong results or crashes.

2. **Undefined behavior** – implicit declarations are *not allowed* in modern C (C99 and later).
   → Compilers like GCC or Clang will throw an **error** (not just a warning):

   ```
   error: implicit declaration of function 'add' [-Werror=implicit-function-declaration]
   ```

3. **Linker issues** – if the real function has a different signature, linking or runtime behavior may fail.

---

### ✅ Correct Version

You fix it by adding a **prototype** before the call:

```c
#include <stdio.h>

int add(int a, int b);  // function declaration (prototype)

int main() {
    int result = add(2, 3);
    printf("Result: %d\n", result);
    return 0;
}

int add(int a, int b) {
    return a + b;
}
```

Now the compiler knows the correct signature of `add` before it’s called.

---

### 💬 Summary

| Concept                  | Description                                                                                |
| ------------------------ | ------------------------------------------------------------------------------------------ |
| **Implicit declaration** | Occurs when a function is called before the compiler has seen its prototype or definition. |
| **Assumed type**         | Returns `int` and accepts unknown parameters (in old C).                                   |
| **Modern rule**          | Forbidden in C99 and later — must declare all functions before use.                        |
| **Fix**                  | Add a function prototype above `main()` or include a header file.                          |

---

Would you like me to show an example where implicit declaration actually causes **wrong runtime behavior** (e.g. mismatched parameter types)?
