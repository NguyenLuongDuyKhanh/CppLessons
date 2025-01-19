## 
- Inheritance represent is-a relationship whereas composition represent has-a relartionship.

## Access Modifiers apply to class properties
- private: Can only be accessed by the class members, cannot be accessed from outside.
- protected: Can only be accessed by the class and its child classes. This means it is accessible only in the hierachy.
- public: Can be accessed even outside the class.

## Access Modifiers apply to inheritance
In public inheritance -> We always prefer public inheritance
    - Base class's private member's -> child class's private member's
    - Base class's protected member's -> child class's protected member's
    - Base class's public member's -> child class's public member's
    Child cannot access parent's private members, it can access protected and public only

In private inheritance 
    - Base class's private member's -> child class's private member's
    - Base class's protected member's -> child class's private member's
    - Base class's public member's -> child class's private member's
    Child cannot access parent's private members, it can access protected and public only

In protected inheritance 
    - Base class's protected member's -> child class's protected member's
    - Base class's public member's -> child class's protected member's

If modifier is not specified:
    Class inheritance is private by default
    Structure inheritance is public by default

## Object Construction
- Constructor execute from base to child
- Destructor execute from child to base
- If child class has defined it own constructor, the default constructor of base class will be called in its construction. If child class need to pass its params to the parameterized constructor of base class, it must do that explicitly

## Multiple Inheritance and Diamon problem
The constructors of inherited classes are called in the same order in which they are inherited. 
It is ambiguous if both 2 parents has same method name, the child class will raise an error.
    ```
        Ex2_MultipleInheritance.cpp: In function ‘int main()’:
        Ex2_MultipleInheritance.cpp:40:9: error: request for member ‘SampleOverlapMethod’ is ambiguous
           40 |     ta1.SampleOverlapMethod();
              |         ^~~~~~~~~~~~~~~~~~~
        Ex2_MultipleInheritance.cpp:26:9: note: candidates are: ‘int Student::SampleOverlapMethod()’
           26 |     int SampleOverlapMethod() {
              |         ^~~~~~~~~~~~~~~~~~~
        Ex2_MultipleInheritance.cpp:15:9: note:                 ‘int Faculty::SampleOverlapMethod()’
           15 |     int SampleOverlapMethod() {
              |         ^~~~~~~~~~~~~~~~~~~
    ```

In Ex2_MultipleInheritance.cpp :
    - Constructor of ‘Person’ is called two times. 
    - Destructor of ‘Person’ will also be called two times when object ‘ta1’ is destructed. 
    - So object ‘ta1’ has two copies of all members of ‘Person’, this causes ambiguities. 
The solution to this problem is ‘virtual’ keyword. We make the classes ‘Faculty’ and ‘Student’ as virtual base classes to avoid two copies of ‘Person’ in ‘TA’ class.