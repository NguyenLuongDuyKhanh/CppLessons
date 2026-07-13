Great question — these two are *everyday* C++ exceptions, but people often misuse them. Let’s look at **practical, realistic examples** and **when to choose which one**.

---

## 1. Big picture: runtime_error vs logic_error

### `std::logic_error`

👉 **Bug in the program**

* Violated preconditions
* Invalid arguments
* Wrong state
* Programmer mistake

💡 “If this happens, the code is wrong.”

---

### `std::runtime_error`

👉 **External / runtime failure**

* File not found
* Network failure
* I/O error
* Resource unavailable

💡 “The code is fine, but reality failed.”

---

## 2. Practical `std::logic_error` examples

### Example 1: Invalid function arguments

```cpp
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::logic_error("divide by zero");
    }
    return a / b;
}
```

Why `logic_error`?

* Caller violated a precondition
* Should be caught during testing

✅ Often replaced by `std::invalid_argument` (derived from `logic_error`)

---

### Example 2: Using an object in the wrong state

```cpp
#include <stdexcept>

class FileWriter {
    bool opened = false;

public:
    void open() { opened = true; }

    void write(const std::string& s) {
        if (!opened) {
            throw std::logic_error("write() called before open()");
        }
    }
};
```

This is **programmer misuse**, not environment failure.

---

### Example 3: Container misuse

```cpp
#include <vector>
#include <stdexcept>

int get_last(const std::vector<int>& v) {
    if (v.empty()) {
        throw std::logic_error("vector is empty");
    }
    return v.back();
}
```

Equivalent STL exception:

* `std::out_of_range`
* `std::logic_error` base class

---

## 3. Practical `std::runtime_error` examples

### Example 4: File I/O failure

```cpp
#include <fstream>
#include <stdexcept>

void load_config(const std::string& path) {
    std::ifstream f(path);
    if (!f) {
        throw std::runtime_error("cannot open config file: " + path);
    }
}
```

Why `runtime_error`?

* File system state
* User / OS dependent
* Not a programming bug

---

### Example 5: Resource exhaustion

```cpp
#include <stdexcept>

void reserve_memory(size_t n) {
    if (n > 1'000'000'000) {
        throw std::runtime_error("requested memory too large");
    }
}
```

(STL usually throws `std::bad_alloc`, but conceptually this fits runtime failure.)

---

### Example 6: Parsing external data

```cpp
#include <stdexcept>

int parse_port(const std::string& s) {
    int port = std::stoi(s);
    if (port < 1 || port > 65535) {
        throw std::runtime_error("port out of range");
    }
    return port;
}
```

Why not logic_error?

* Input came from outside the program
* User / file / network data

---

## 4. Combining both in real code

```cpp
#include <stdexcept>

class Database {
public:
    void connect(const std::string& url) {
        if (url.empty()) {
            throw std::logic_error("empty database URL");
        }

        if (!network_available()) {
            throw std::runtime_error("network unavailable");
        }
    }
};
```

✔ Same function
✔ Different error categories
✔ Clear intent

---

## 5. How callers should handle them differently

```cpp
try {
    db.connect(url);
} catch (const std::logic_error& e) {
    // programmer bug
    std::cerr << "BUG: " << e.what() << '\n';
    std::terminate();
} catch (const std::runtime_error& e) {
    // recoverable failure
    std::cerr << "Runtime error: " << e.what() << '\n';
    retry();
}
```

💡 This is why the distinction matters.

---

## 6. Use more specific derived types (best practice)

### logic_error family

* `std::invalid_argument`
* `std::out_of_range`
* `std::length_error`
* `std::domain_error`

### runtime_error family

* `std::range_error`
* `std::overflow_error`
* `std::underflow_error`

Example:

```cpp
throw std::invalid_argument("negative size");
throw std::out_of_range("index out of bounds");
```

---

## 7. Rule of thumb (easy to remember)

> ❓ *Could correct code still hit this error?*

* **Yes** → `runtime_error`
* **No** → `logic_error`

---

## 8. One anti-pattern to avoid 🚫

```cpp
catch (std::exception& e) {
    // swallow everything
}
```

You lose:

* Bug vs runtime distinction
* Debug signal

Prefer:

```cpp
catch (const std::logic_error& e) { ... }
catch (const std::runtime_error& e) { ... }
```

---

If you want, next we can:

* Map STL exceptions to real scenarios
* Show exception-safe APIs (when *not* to throw)
* Compare exceptions vs error codes in systems programming

Just say the word 👍
