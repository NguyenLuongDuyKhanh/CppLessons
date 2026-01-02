Short answer: you mark a constructor `= delete` when you want to **forbid certain ways of creating objects**—on purpose and at compile time.

Long answer (with real-world patterns 👇):

---

## 1. Make a class **non-instantiable**

If a class is only meant to be used via **static methods** or as a **utility/helper**, you don’t want anyone to create objects.

```cpp
class MathUtils {
public:
    MathUtils() = delete;

    static int add(int a, int b) {
        return a + b;
    }
};
```

✅ Prevents:

```cpp
MathUtils m;   // ❌ compile-time error
```

---

## 2. Prevent copying (copy constructor deleted)

This is *extremely common*.

Use this when:

* The class manages a **resource** (file, mutex, socket, memory)
* Copying would cause **double free** or **undefined behavior**

```cpp
class File {
public:
    File(const char* path);
    ~File();

    File(const File&) = delete;            // no copy
    File& operator=(const File&) = delete; // no copy assign
};
```

Typical examples:

* `std::mutex`
* `std::unique_ptr`
* File handles, sockets

---

## 3. Prevent moving (move constructor deleted)

Sometimes moving also doesn’t make sense or isn’t safe.

```cpp
class Logger {
public:
    Logger() = default;

    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;
};
```

Used when:

* Object must stay at a fixed address
* External system stores its pointer

---

## 4. Enforce **factory-only creation**

You want objects created only through a factory function.

```cpp
class Database {
public:
    static Database create() {
        return Database(42);
    }

    Database(const Database&) = delete;

private:
    explicit Database(int id) : id_(id) {}

    int id_;
};
```

Here:

* Constructor is private
* Copying is forbidden
* Creation path is controlled

---

## 5. Disallow certain constructor overloads

You may want to allow **some ways** to construct but forbid others.

```cpp
class Buffer {
public:
    Buffer(size_t size);      // OK
    Buffer(int) = delete;     // forbid accidental int usage
};
```

This prevents bugs like:

```cpp
Buffer b(-1);   // ❌ caught at compile time
```

---

## 6. Make a class **non-default-constructible**

Sometimes a class *must* have parameters.

```cpp
class Config {
public:
    Config() = delete;
    explicit Config(std::string path);
};
```

Prevents:

```cpp
Config c;   // ❌ must provide config file
```

---

## 7. Why `= delete` is better than `private` (old C++ way)

Before C++11, people did:

```cpp
class A {
private:
    A();
};
```

Problems:

* Errors show up **later**
* Friends could still call it
* Less expressive

`= delete`:

* Fails **immediately at compile time**
* Error messages are clearer
* Works for any function, not just constructors

---

## Mental model 🧠

Use `= delete` when you want to say:

> “This operation is **logically invalid**, not just inconvenient.”

If it should **never** be used → `= delete`
If it’s just hidden from users → `private`

---

If you want, I can also show:

* `= delete` vs `= default`
* Common interview trick questions
* How this interacts with inheritance and rule of 5

Just tell me 👍
