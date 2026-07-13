# Default constructor
A constructor without any arguments or with the default value for every argument is said to be the Default constructor.
If default constructor is not defined in the source code by the programmer, then the compiler defined the default constructor implicitly during compilation.

## Static
A static member of a class is a variable or function that belongs to the class itself, rather than to any specific instance (object) of that class. This means that only one copy of a static member exists, and it is shared by all objects of the class. 

Key Characteristics
-   Shared across instances: All instances of a class share a single copy of a static data member. Changing its value through one object or the class name affects all others.
-   Lifetime: Static members are created when the program starts (or the class is loaded) and persist until the program ends, independent of whether any objects of the class have been created.
-   Access: Static members can be accessed directly using the class name and the scope resolution operator (:: in C++) or dot operator (in other languages like Java/C#), without needing an instance of the class.
-   No this pointer: Static member functions do not have access to the this pointer, which points to the current object instance. Therefore, they can only access other static members (data or functions) of the class.
-   Access control: Like non-static members, static members obey access rules (public, private, protected). 

## Rule of three


## References 
https://www.geeksforgeeks.org/default-constructors-in-cpp/
https://www.geeksforgeeks.org/static-member-function-in-cpp/
Nếu pass bằng giá trị thì có gọi copy constructor không?