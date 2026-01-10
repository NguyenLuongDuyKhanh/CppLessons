## const function
    It means that *this is const inside that member function, i.e. it doesn't alter the object.


<detail>

    Ex1.cpp: In member function ‘int SampleClass::sampleConstFunction() const’:
    Ex1.cpp:9:26: error: passing ‘const SampleClass’ as ‘this’ argument discards    qualifiers [-fpermissive]
        9 |             privateSetter();
          |             ~~~~~~~~~~~~~^~
    Ex1.cpp:13:14: note:   in call to ‘void SampleClass::privateSetter()’
       13 |         void privateSetter() {
          |              ^~~~~~~~~~~~~
</detail>

## const can be on either side of the type 

<detail>

    Read it backwards (as driven by Clockwise/Spiral Rule):

    int* - pointer to int
    int const * - pointer to const int
    int * const - const pointer to int
    int const * const - const pointer to const int
    Now the first const can be on either side of the type so:

    const int * == int const *
    const int * const == int const * const
    If you want to go really crazy you can do things like this:

    int ** - pointer to pointer to int
    int ** const - a const pointer to a pointer to an int
    int * const * - a pointer to a const pointer to an int
    int const ** - a pointer to a pointer to a const int
    int * const * const - a const pointer to a const pointer to an int

</detail>
## References
https://www.geeksforgeeks.org/const-member-functions-c/
https://www.geeksforgeeks.org/understanding-constexper-specifier-in-cpp/
https://www.geeksforgeeks.org/difference-between-constant-pointer-pointers-to-constant-and-constant-pointers-to-constants/
https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const
https://stackoverflow.com/questions/4059932/what-is-the-meaning-of-a-const-at-end-of-a-member-function
https://www.geeksforgeeks.org/const-keyword-in-cpp/