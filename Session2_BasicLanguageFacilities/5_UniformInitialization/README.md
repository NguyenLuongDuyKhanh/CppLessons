## Initialization in C++98 Standard
- Scalar types can be initialized with `=` or `()`.
- Array types have to be initialized with `{}`.

## Initialization in modern C++ (C++11)
- Uniform initialization is introduced to init both array type and scalar type.

## Advantages
### Force initialization

```C++ 98
int a1;                 // Do not call default constructor, leave a1 uninitialized
std::string s1;         // The default constructor of string is call
```
- When we use assignment sign to initialize a variable, it is called copy initialization because it copy value from the right to pass to the identifier on the left.
```C++
// Scalar types
int a1(5);              // Direct initialization
std::string("Hello");   // Direct initialization

// Array type
char d1[8];             // Uninitialized
char d2[8] = {'a', 'b'};// Aggregate initialization
```
- Uniform initialization use `{}` without `=`. See Ex1.cpp
- We should always use uniform initialization for user defined types.

### Prevent narrowing conversion