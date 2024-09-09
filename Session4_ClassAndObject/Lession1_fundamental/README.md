modifier:
    private, protected, public
    attribute are private by default if no modifier are specified

## Fundamental


## this pointer
- A hidden pointer passed to member function (methods), point to the object that invoked the function
- Meaningful only in member function
- this pointer is optional in most cases, except in cases:
    * Function argument has the same name with class's attributes, this pointer to specify those
    ```
        class A {
            int sampleVar;
            A(sampleVar) {
                this->sampleVar = sampleVar;
            }
        }
    ```
    * a function in classA which work with an object of classB. 'this' pointer will specified object belong to object A, in case classA and classB has member with same names
    * A function return the object of its class to the caller
    
##

## References
https://www.geeksforgeeks.org/this-pointer-in-c/