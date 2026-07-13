A **hash map** (also called a **hash table** or **dictionary**) is a data structure that stores key-value pairs and allows **fast lookup, insertion, and deletion**. It uses a **hash function** to compute an index into an array of buckets, from which the desired value can be found.

The **lookup** operation works like this:

1. You have a key (e.g., `"apple"`).
2. The hash function computes a hash value and maps it to an index.
3. At that index, the value associated with the key is stored.
4. If there’s a collision (two keys map to the same index), a collision resolution strategy like chaining (linked list) or open addressing is used.

**Time complexity:**

* Average case: O(1)
* Worst case (all keys collide): O(n)

---

### **C++ Example (using `std::unordered_map`)**

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> ageMap;

    // Insert key-value pairs
    ageMap["Alice"] = 25;
    ageMap["Bob"] = 30;
    ageMap["Charlie"] = 22;

    // Lookup a key
    string name = "Bob";
    if (ageMap.find(name) != ageMap.end()) {
        cout << name << "'s age is " << ageMap[name] << endl;
    } else {
        cout << name << " not found!" << endl;
    }

    return 0;
}
```

---

### **Python Example (using `dict`)**

```python
# Create a dictionary (hash map)
age_map = {
    "Alice": 25,
    "Bob": 30,
    "Charlie": 22
}

# Lookup a key
name = "Bob"
if name in age_map:
    print(f"{name}'s age is {age_map[name]}")
else:
    print(f"{name} not found!")
```

---

### **Go Example (using `map`)**

```go
package main

import "fmt"

func main() {
    // Create a hash map
    ageMap := map[string]int{
        "Alice": 25,
        "Bob": 30,
        "Charlie": 22,
    }

    // Lookup a key
    name := "Bob"
    if age, ok := ageMap[name]; ok {
        fmt.Printf("%s's age is %d\n", name, age)
    } else {
        fmt.Printf("%s not found!\n", name)
    }
}
```

---

✅ Key points:

* The lookup is **O(1) average**.
* Different languages provide built-in hash maps (`unordered_map` in C++, `dict` in Python, `map` in Go).
* If the key is not found, you typically handle it with `find` (C++), `in` (Python), or checking `ok` (Go).

If you want, I can also **show how a hash map lookup works internally step by step with collisions** and **a diagram of buckets**. This helps you visualize what happens under the hood.

Do you want me to do that?
