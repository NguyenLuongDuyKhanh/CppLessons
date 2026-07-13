In C++, the “best practice” for separating **header (.h)** and **source (.cpp)** files follows a long-established pattern—mainly for compilation speed, dependency clarity, and avoiding ODR (One Definition Rule) issues.
Below is the clear rule set.

---

# ✅ **Where each part of code should live**

## **1. Header files (.h)**

Typically contain **declarations**, not implementations:

### **Put in header files:**

* Class declarations
* Struct declarations
* Function *prototypes*
* Template class/function *definitions* (special rule!)
* `enum`, `typedef`, `using`
* `constexpr`/`const` integral values
* Inline functions
* Small one-liner methods marked `inline`
* Public API of a module

### Example:

```cpp
// math_utils.h
#pragma once

class Math {
public:
    int add(int a, int b);   // declaration
};
```

---

## **2. Source files (.cpp)**

Contain **definitions** and **implementations**.

### Put in .cpp:

* Function bodies / method implementations (non-template)
* Internal helper functions (private to that translation unit)
* Non-const global variables
* Large inline-unfriendly code
* Code that should not be exposed to users or other compilation units

### Example:

```cpp
// math_utils.cpp
#include "math_utils.h"

int Math::add(int a, int b) {   // implementation
    return a + b;
}
```

---

# ⚠️ **Is it okay to put implementation inside the header file?**

**Yes, but only in some cases.**

### ✔️ Allowed and common:

* **Templates** (must be in header so compiler can instantiate them)
* **Inline functions**
* **Very small methods (1–3 lines)**
* **Header-only libraries** (e.g., Eigen, Catch2)

### ❌ Not recommended for non-template, non-inline functions:

Because:

## ⚠️ Problems when putting full implementations in headers

### **1. Code bloat (larger binary)**

Every `.cpp` including the header may generate its own copy of the function unless it's `inline`.

### **2. Slower compilation**

Headers are recompiled for each translation unit.

### **3. Violation of One Definition Rule (ODR)**

If you define a normal function in a header:

```cpp
void foo() { }
```

And 5 `.cpp` files include the header → linker error: *multiple definitions of `foo`*.

Unless you mark it `inline`:

```cpp
inline void foo() { }
```

### **4. Unnecessary exposure of internal code**

Putting logic into headers forces all modules to re-compile when you change implementation details.

---

# ⭐ **Best Practice Summary**

| Type of code                      | Header (.h)             | Source (.cpp) |
| --------------------------------- | ----------------------- | ------------- |
| Class declarations                | ✔️                      | ❌             |
| Method definitions                | ❌ (except small inline) | ✔️            |
| Templates                         | ✔️                      | ❌             |
| Inline functions                  | ✔️                      | ❌             |
| Non-inline implementations        | ❌                       | ✔️            |
| Internal/private helper functions | ❌                       | ✔️            |
| Global variables                  | ❌ (unless `extern`)     | ✔️            |

---

# ⭐ When should you intentionally put implementation in header?

* If you are writing **header-only library**
* If your functions are **template-based**
* If they are **one-liner inline** functions
* If the code is **performance-critical** and inlining helps

Otherwise, the normal `.h/.cpp` split is cleaner and avoids many issues.

---

If you want, I can show a full **example project structure**, including namespaces, header guards, and examples of what exactly goes where.

Below is a clean, modern, **professional C++ project structure example**, showing exactly what goes into `.h` and `.cpp` files and why.
This follows widely accepted practices in real projects (Qt, LLVM, Unreal Engine, etc.).

---

# 📁 **Recommended project directory layout**

```
project/
├── include/
│   └── project/
│       ├── math_utils.h
│       └── vector2.h
└── src/
    ├── math_utils.cpp
    └── vector2.cpp
```

* `include/` contains all public headers (`.h` or `.hpp`)
* `src/` contains internal implementation files (`.cpp`)
* `project/` is a subfolder used as a namespace boundary, helps avoid name conflicts

---

# Example: `math_utils` module

## **math_utils.h (header)**

Contains *only declarations*:

```cpp
// include/project/math_utils.h
#pragma once

namespace project {

class Math {
public:
    Math() = default;

    int add(int a, int b);            // declaration
    int subtract(int a, int b);       // declaration
    static int multiply(int a, int b); // static function declaration
};

} // namespace project
```

**Why header?**
Because this is the public API: other files need to know the names, not the code.

---

## **math_utils.cpp (source)**

Contains the actual implementation.

```cpp
// src/math_utils.cpp
#include "project/math_utils.h"

namespace project {

int Math::add(int a, int b) {
    return a + b;
}

int Math::subtract(int a, int b) {
    return a - b;
}

int Math::multiply(int a, int b) {
    return a * b;
}

} // namespace project
```

---

# Example: A class with small inline methods (`Vector2`)

## **vector2.h**

This time, we inline small one-liner functions.

```cpp
// include/project/vector2.h
#pragma once
#include <cmath>

namespace project {

class Vector2 {
public:
    float x;
    float y;

    Vector2(float x = 0, float y = 0) : x(x), y(y) {}

    float length() const {            // small method → inline OK
        return std::sqrt(x * x + y * y);
    }

    Vector2 operator+(const Vector2& other) const {  // also small
        return Vector2(x + other.x, y + other.y);
    }
};

} // namespace project
```

### Why inline here?

* They are very small.
* Inline avoids function-call overhead.
* Inlining inside header is common for math libraries.
* Most vector/matrix libraries are header-only.

---

## **vector2.cpp**

This file is optional; only needed if method implementations are large.

```cpp
// src/vector2.cpp
#include "project/vector2.h"

// could place big implementations here if needed,
// but in this example, everything lives in the header.
```

---

# ✔️ **Best Practices Summary**

### **Put in header (.h):**

* Class declarations
* Member variables
* Method declarations
* Templates (must)
* Inline/very small functions
* Public APIs
* Constants, enums, typedefs, using

### **Put in source (.cpp):**

* Implementations of non-inline functions
* Private helper functions
* Anything you don’t want included by every other .cpp file
* Large code bodies
* Internal logic not part of the public API

---

# ⭐ Full Example: A main program using the library

```cpp
// src/main.cpp
#include <iostream>
#include "project/math_utils.h"
#include "project/vector2.h"

int main() {
    project::Math m;
    std::cout << m.add(1, 2) << std::endl;

    project::Vector2 v1(1, 2), v2(3, 4);
    auto v3 = v1 + v2;
    std::cout << v3.x << ", " << v3.y << std::endl;

    return 0;
}
```

---

If you'd like, I can also show you:

✔️ A CMakeLists.txt for this project
✔️ How to build a static or shared library
✔️ How to make a header-only library
✔️ How to organize very large projects

Just tell me!

Show me how to make a CMakeLists.txt for this project, how to make a header-only library from this project and how to organize very large projects when it grows.

Below is a complete, modern, **clean CMake setup** for:

1. ✔️ Building your project normally
2. ✔️ Building it as a **header-only library**
3. ✔️ Scaling to **large multi-module projects**

Everything follows modern CMake (3.15–3.27) best practices.

---

# 🧱 **1. CMakeLists.txt for the project**

Your directory structure:

```
project/
├── CMakeLists.txt
├── include/
│   └── project/
│       ├── math_utils.h
│       └── vector2.h
└── src/
    ├── math_utils.cpp
    ├── vector2.cpp
    └── main.cpp
```

### ✔️ Main CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.15)
project(MyProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create library from src files
add_library(project_lib
    src/math_utils.cpp
    src/vector2.cpp
)

# Public include directory
target_include_directories(project_lib
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# Create main executable
add_executable(myapp src/main.cpp)

# Link library to the executable
target_link_libraries(myapp PRIVATE project_lib)
```

That's it — clean, modern, scalable.

---

# 📦 **2. How to make this project a header-only library**

A header-only library has **only headers**—no compiled sources.

To convert `project_lib` into a header-only library:

### ✔️ Replace `add_library(project_lib ...)` with INTERFACE target

```cmake
add_library(project_lib INTERFACE)

target_include_directories(project_lib
    INTERFACE
        ${PROJECT_SOURCE_DIR}/include
)
```

That’s all. Now there are **no .cpp files**, and everything must live in headers.

### If you want to keep both versions:

* `project_static` → compiled `.cpp` version
* `project_header_only` → header-only version

```cmake
add_library(project_static
    src/math_utils.cpp
    src/vector2.cpp
)

target_include_directories(project_static PUBLIC include)

add_library(project_header_only INTERFACE)
target_include_directories(project_header_only INTERFACE include)
```

You can switch between them based on user option:

```cmake
option(USE_HEADER_ONLY "Use header-only library" OFF)

if(USE_HEADER_ONLY)
    add_library(project_lib INTERFACE)
    target_include_directories(project_lib INTERFACE include)
else()
    add_library(project_lib
        src/math_utils.cpp
        src/vector2.cpp
    )
    target_include_directories(project_lib PUBLIC include)
endif()
```

---

# 🏛️ **3. How to organize very large projects**

When a project grows, you should organize by **modules**.

### ✔️ Recommended top-level layout

```
project/
├── CMakeLists.txt
├── cmake/              # custom cmake modules
├── include/
│   └── project/
│       ├── math/
│       │   └── math_utils.h
│       ├── geometry/
│       │   └── vector2.h
│       └── core/
│           └── config.h
└── src/
    ├── math/
    │   └── math_utils.cpp
    ├── geometry/
    │   └── vector2.cpp
    └── core/
        └── config.cpp
```

### ✔️ Create a sub-CMakeLists.txt in each module

**project/src/math/CMakeLists.txt**

```cmake
add_library(project_math math_utils.cpp)
target_include_directories(project_math PUBLIC ${PROJECT_SOURCE_DIR}/include)
```

**project/src/geometry/CMakeLists.txt**

```cmake
add_library(project_geometry vector2.cpp)
target_include_directories(project_geometry PUBLIC ${PROJECT_SOURCE_DIR}/include)
```

**project/src/core/CMakeLists.txt**

```cmake
add_library(project_core config.cpp)
target_include_directories(project_core PUBLIC ${PROJECT_SOURCE_DIR}/include)
```

### ✔️ Top-level CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.15)
project(MyBigProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src/math)
add_subdirectory(src/geometry)
add_subdirectory(src/core)

add_executable(myapp src/main.cpp)

target_link_libraries(myapp
    PRIVATE
        project_math
        project_geometry
        project_core
)
```

---

# 🧩 **4. Large-scale best practices**

## ✔️ Use namespaces to match your directory structure

Example:

```
namespace project::math { … }
namespace project::geometry { … }
namespace project::core { … }
```

---

## ✔️ Rule of thumb: each module = one target

Don’t create one giant library.

Good:

```
project_math
project_geometry
project_core
project_io
project_network
```

Bad:

```
project_all_the_code
```

---

## ✔️ Avoid “global” include directories

Use:

```cmake
target_include_directories(target PUBLIC ...)
```

Not:

```cmake
include_directories(...)
```

This avoids polluting dependencies.

---

## ✔️ For very large projects: split into components

```
project/
├── libs/
│   ├── core/
│   ├── math/
│   ├── geometry/
│   ├── io/
│   └── networking/
└── apps/
    ├── viewer/
    ├── cli/
    └── tools/
```

Each app links only to the modules it needs.

---

## ✔️ Use `install()` rules if you want to distribute libraries

### Example:

```cmake
install(TARGETS project_math EXPORT projectTargets)
install(DIRECTORY include/ DESTINATION include)
```

---

# 🎁 Want me to generate a full working GitHub-ready project?

I can create:

✔️ All `.h` and `.cpp` files
✔️ Full directory tree
✔️ CMakeLists for each module
✔️ A top-level CMake that builds everything
✔️ A demo `main.cpp`

Just say **“Generate the full project”**.
