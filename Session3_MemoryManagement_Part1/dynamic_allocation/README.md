## Dynamic allocation
The most important difference is, that normal arrays are deallocated by the compiler (If the array is local, then deallocated when the function returns or completes). However, dynamically allocated arrays always remain there until either they are deallocated by the programmer or the program terminates.

C - Use malloc(), calloc() and free() to allocating/deallocating
C++ - Further than those, 'new' and 'delete' operations are provided

## delete and free()
Note that 'delete' call destructor before deallocating, free() does not do that

## new and malloc()/calloc
Note that 'new' call the constructor of a class whereas malloc() does not.

## References
https://www.geeksforgeeks.org/delete-and-free-in-cpp/
https://www.geeksforgeeks.org/new-vs-malloc-and-free-vs-delete-in-c/
https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/