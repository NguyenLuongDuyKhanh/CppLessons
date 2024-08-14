## Overal
Pure abstract class = Interface
In C++ programming there is no built-in concept of interfaces. In order to create an interface, we need to create an abstract class which is having only pure virtual methods. In C++, Interfaces are also called pure abstract classes.

A pure virtual function is a function where we only declare the function but not the function definition, it is specified by placing "= 0" in its declaration as follows.
    virtual double getVolume() = 0;
A class is made abstract by declaring at least one of its functions as pure virtual function
Abstract classes cannot be used to instantiate objects and serves only as an interface

 In order to create an interface, we need to create an abstract class which is having only pure virtual methods. In C++, Interfaces are also called pure abstract classes.