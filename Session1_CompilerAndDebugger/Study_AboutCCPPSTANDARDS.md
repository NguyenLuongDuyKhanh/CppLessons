The **standard versions of C and C++** are defined by the ISO/IEC standards, which evolve over time. Here’s a breakdown:

---

## 🟦 C Language Standards

* **C89 / ANSI C (1989)** – The first standardized version, often referred to as ANSI C.
* **C90 (ISO C90)** – Essentially the same as ANSI C, ratified by ISO in 1990.
* **C99 (1999)** – Added features like `inline` functions, variable-length arrays, new data types (`long long`, `_Bool`), and `//` comments.
* **C11 (2011)** – Introduced multi-threading support (`<threads.h>`), atomic operations, improved Unicode support, and optional bounds-checking.
* **C17 (2017)** – Mostly a bug-fix and clarification release (sometimes called C18).
* **C23 (2023)** – The latest standard, adds modern features like improved Unicode handling, new library functions, and general modernization.

👉 Most compilers today support at least **C11**, with partial or full support for **C17** and **C23**.

---

## 🟦 C++ Language Standards

* **C++98 (1998)** – The first standardized version of C++.
* **C++03 (2003)** – Bug fixes and minor improvements.
* **C++11 (2011)** – A major update (sometimes called C++0x): introduced auto, range-based for loops, lambdas, smart pointers, move semantics, multithreading (`<thread>`).
* **C++14 (2014)** – Refinements to C++11 features (e.g., generic lambdas).
* **C++17 (2017)** – Added `std::optional`, `std::variant`, `std::filesystem`, structured bindings, and parallel algorithms.
* **C++20 (2020)** – Another huge update: concepts, ranges, coroutines, modules (experimental), three-way comparison (`<=>`), and expanded constexpr.
* **C++23 (2023)** – Incremental improvements: more constexpr, better ranges, standard `mdspan`, simplified lambdas, expanded library support.
* **C++26 (expected)** – Currently under development, may bring executors, pattern matching, and more.

👉 Most modern projects target **C++17** or **C++20**, while C++23 adoption is growing.

---

✅ **Summary:**

* Latest **C standard**: **C23 (2023)**
* Latest **C++ standard**: **C++23 (2023)**
* Commonly used in practice: **C11 / C17 for C**, **C++17 / C++20 for C++**

---

Do you want me to also show you **how to set the C/C++ standard version in GCC/Clang or MSVC** (e.g., using compiler flags)?
