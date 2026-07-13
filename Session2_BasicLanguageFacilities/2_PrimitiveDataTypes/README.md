## Primitive types
Void 
    Specially use with pointer and function

Arithmetic 
    Integral: bool, char, wchar_t, char16_t, char32_t (designed to handle characters that require more storage than a standard 8-bit char, to work with character sets like Unicode), short, int 
    Floating point: float, double

## Modifiers: signed, unsigned, short, long
Used to modify meaning of a type
Not all types can be modified: signed and unsigned only used on integral not floating point
    
## Qualifiers: const, volatile, static
All types can be qualified with qualifiers

## Variable
A variable is also called a indentifier.
The value used to initialize a variable is call initializer.
Should be initialized during declaration to avoid bugs.

## Initializer
### Copy Initialization 
- This uses the assignment operator (=) to assign an initial value.

```C++
int x = 10;
std::string s = "hello";
```
### Parenthesized Initialization
- It looks similar to initialize an object of a class.
- This uses parentheses () to pass arguments to a constructor for direct initialization.

```C++
int x(10);
std::string s("hello");
```

### Aggregate Initialization 
- A C++ technique for initializing a data structure (an aggregate) like an array or a struct with a list of values using curly braces {}.
- Used for a class, struct, or union that meets specific criteria, such as:
    * Having no private or protected non-static members.
    * Having no user-provided, inherited, or explicit constructors (explicitly defaulted or deleted constructors are allowed).
    * Having no virtual functions or private/protected base classes. 

### Uniform Initialization 
    - aka Brace Initialization or List Initialization
    - Introduced in C++11. A uniform for primitive types as well as class objects.
    - Offer safety benefits, preventing narrowing conversions.

# optional exact-width types stdint.h 
uint8_t
int8_t
...
They are called exact-width type used in embedded programming.
It helps to maintain the size of a variable when we switch that peice of code to a different system