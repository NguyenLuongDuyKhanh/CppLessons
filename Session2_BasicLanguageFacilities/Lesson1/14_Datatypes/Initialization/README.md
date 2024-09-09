Value initialization => T obj{};
Direct initialization => T obj{v};
Copy initialization => t obj = v;
    should be avoid in user defined objects


For premiter types, using assignment would be more natural
For user defined types, we should always use uniform initiallization

# Uniform initialization
Before C++:
    Scalar types init by using = or ()
    Array type init by using {}
Now -> use uniform initialization
    One syntax for all types, prevent bug when initializing incompatible
    It forces initializaing, prevent bug from random value in ininitializined variable
    Prevent narrowing conversation
    
## Initializer list

# References
https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/
https://www.geeksforgeeks.org/uniform-initialization-in-c/