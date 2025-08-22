# STL Containers in C++
1
2
3
The Standard Template Library (STL) in C++ provides a collection of class templates and algorithms that allow programmers to easily implement common data structures like arrays, lists, queues, stacks, and more. These containers are designed to manage the storage space for their elements and provide member functions to access them, either directly or through iterators.

Types of STL Containers

Sequence Containers

Sequence containers implement data structures that can be accessed sequentially. They include:

array: A static contiguous array.

vector: A dynamic contiguous array.

deque: A double-ended queue.

forward_list: A singly-linked list.

list: A doubly-linked list
1
2
.

Associative Containers

Associative containers implement sorted data structures that can be quickly searched (O(log n) complexity). They include:

set: A collection of unique keys, sorted by keys.

map: A collection of key-value pairs, sorted by keys, where keys are unique.

multiset: A collection of keys, sorted by keys.

multimap: A collection of key-value pairs, sorted by keys
1
2
.

Unordered Associative Containers

Unordered associative containers implement unsorted (hashed) data structures that can be quickly searched (O(1) average, O(n) worst-case complexity). They include:

unordered_set: A collection of unique keys, hashed by keys.

unordered_map: A collection of key-value pairs, hashed by keys, where keys are unique.

unordered_multiset: A collection of keys, hashed by keys.

unordered_multimap: A collection of key-value pairs, hashed by keys
1
2
.

Container Adaptors

Container adaptors provide a different interface for sequential containers. They include:

stack: Adapts a container to provide a stack (LIFO data structure).

queue: Adapts a container to provide a queue (FIFO data structure).

priority_queue: Adapts a container to provide a priority queue
1
2
.

Choosing the Right Container

The choice of which container to use depends on the specific needs of the application, including the type of data, the operations to be performed, and the efficiency of those operations. For example:

Use vector for dynamic arrays where random access is needed.

Use list for frequent insertions and deletions.

Use map for key-value pairs with unique keys.

Use unordered_map for faster access with hashed keys
1
2
.

Example Usage

Here is an example of using a vector in C++:

#include <iostream>
#include <vector>

int main() {
std::vector<int> numbers = {1, 2, 3, 4, 5};

// Add an element to the vector
numbers.push_back(6);

// Iterate and print elements
for (int num : numbers) {
std::cout << num << " ";
}

return 0;
}
This code initializes a vector with some integers, adds an element to it, and then iterates through the vector to print its elements.

Conclusion

STL containers in C++ provide a powerful and flexible way to manage collections of data. By understanding the different types of containers and their use cases, you can choose the right container for your specific needs and optimize the performance of your application
1
2
.

# TODO
https://en.cppreference.com/w/cpp/container.html
https://cplusplus.com/reference/stl/
https://en.cppreference.com/w/cpp/container.html
https://www.geeksforgeeks.org/cpp/containers-cpp-stl/