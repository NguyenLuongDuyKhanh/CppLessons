The answer depends on **three main factors**:

1. **Do you know the number of objects beforehand?**
2. **Do you frequently insert/remove objects?**
3. **Do you need cache-friendly, high-performance iteration?**

Let's compare each option.

| Method                            | Memory Layout                            | Access | Insert/Delete          | Ownership                    | Typical Use                  |
| --------------------------------- | ---------------------------------------- | ------ | ---------------------- | ---------------------------- | ---------------------------- |
| Array of objects                  | Contiguous                               | O(1)   | Expensive              | Owns objects                 | Best for most cases          |
| Array of references (or pointers) | Contiguous references, scattered objects | O(1)   | Moderate               | Usually does not own objects | Polymorphism, shared objects |
| Linked list                       | Non-contiguous                           | O(n)   | O(1) if iterator known | Owns or references           | Rarely the best choice       |

---

## 1. Array of objects

```cpp
struct Person {
    std::string name;
    int age;
};

std::vector<Person> people;
```

Memory looks like

```
+---------+---------+---------+
|Person 0 |Person 1 |Person 2 |
+---------+---------+---------+
```

Advantages

* Excellent cache locality
* Fast iteration
* No extra allocation per object
* Simplest ownership model
* Recommended by the C++ Standard Library

Disadvantages

* Inserting in the middle requires moving later objects.
* Reallocation may move all objects when capacity grows.

Example

```cpp
people.push_back({"Alice", 30});
people.push_back({"Bob", 25});
```

This is the **default choice** in modern C++.

---

## 2. Array of references (actually pointers)

C++ **cannot have an array of references**.

This is illegal:

```cpp
Person& arr[10];   // ERROR
```

Instead, people use pointers or smart pointers.

```cpp
std::vector<Person*> people;
```

or

```cpp
std::vector<std::shared_ptr<Person>> people;
```

Memory

```
Vector

+-----+-----+-----+
| * | * | * |
+-----+-----+-----+
   |     |     |
   v     v     v

Person   Person   Person
```

Advantages

* Objects stay at fixed addresses.
* Cheap to reorder pointers.
* Supports polymorphism.

Example

```cpp
class Animal {
public:
    virtual void speak() = 0;
};

class Dog : public Animal {};
class Cat : public Animal {};

std::vector<std::unique_ptr<Animal>> animals;
animals.push_back(std::make_unique<Dog>());
animals.push_back(std::make_unique<Cat>());
```

If the objects have different dynamic types, storing pointers (often smart pointers) is the preferred approach.

---

## 3. Linked list

```cpp
std::list<Person> people;
```

Memory

```
+---------+     +---------+     +---------+
| Person  | --> | Person  | --> | Person  |
+---------+     +---------+     +---------+
```

Advantages

* Insertion is O(1) when you already have an iterator to the insertion point.
* Object addresses remain stable.

Disadvantages

* One heap allocation per node.
* Poor cache locality.
* Higher memory overhead.
* Much slower iteration than a vector in practice.

Although insertion is theoretically efficient, many workloads spend much more time traversing containers than inserting into them, making contiguous storage significantly faster.

---

# Performance comparison

Suppose there are one million objects.

### Iterating

```
vector<Person>

[Person][Person][Person][Person]
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
CPU reads sequentially
```

Very cache friendly.

---

```
list<Person>

[Node] -> [Node] -> [Node] -> ...
```

Every node may be on a different memory page.

The CPU continually follows pointers, causing many cache misses.

As a result, a `std::vector` often iterates several times faster than a `std::list`, even if the list avoids moving objects during insertion.

---

# Which should you choose?

### Use `std::vector<Object>` (array of objects) when

* Objects are reasonably movable.
* You mostly iterate.
* You append new objects.
* You want the best overall performance.

This is the recommended choice for the vast majority of C++ programs.

---

### Use `std::vector<std::unique_ptr<Object>>` (array of pointers)

* Objects are large or expensive to move.
* You need polymorphism.
* Objects must keep stable addresses.
* Objects are created and destroyed independently.

---

### Use `std::list<Object>`

Only if you genuinely need:

* frequent insertion/erasure at arbitrary positions **and**
* stable iterators/references **and**
* you already have iterators to those positions.

Even then, it's worth considering alternatives like `std::deque` or other specialized containers before choosing `std::list`.

---

## Rule of thumb

For modern C++:

1. ✅ **`std::vector<T>`** — the default and usually best choice.
2. ✅ **`std::vector<std::unique_ptr<T>>`** — when you need polymorphism or stable object addresses.
3. ⚠️ **`std::list<T>`** — only for specific workloads where its guarantees are truly required.

A common guideline in the C++ community is: **if you're unsure, start with `std::vector`**. Measure performance and switch to a different container only if profiling shows it's necessary.
