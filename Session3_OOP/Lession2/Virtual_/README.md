## Virtual and runtime polymorphism
Virtual functions cannot be static.
A class may have a virtual destructor but it cannot have a virtual constructor.
Virtual functions should be accessed using a pointer or reference of base class type to achieve runtime polymorphism.
It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used.
Runtime polymorphism is achieved only through a pointer (or reference) of the base class type.
Late binding (Runtime) is done in accordance with the content of the pointer (i.e. location pointed to by pointer) and Early binding (Compile-time) is done according to the type of pointer
If a virtual method is not defined in base class (only declared), it called pure virtual method

## References
https://www.geeksforgeeks.org/virtual-function-cpp/