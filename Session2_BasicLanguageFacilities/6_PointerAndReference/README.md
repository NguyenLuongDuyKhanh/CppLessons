## Reference &
- `&` is called 'ampersand operator' or 'address of' operator, used to get address of a variable.

## Dereference *
- To access the value at the address

## Void pointer
- A void pointer can point to any types.

## Pointer type *

    null is a macro in C and pre-C++11
    C++11 introduced nullptr
    Reading from a nullptr may causes access violation

## Reference vs Pointer

Reference                       Pointer
---
Always needs an initializer.    Could be nullptr if not initialize yet.
Initializer should be L-value.  Initializer need not to be L-value, it can also be literal.
Cannot be nullptr               Can be nullptr
Bound to it referent.           Can point to other variables.
No storage required.            A memory size of a word to store the pointer.
Dereference not required        Requires dereference operator to access the value.

## Dangling Pointers
- Is a pointer points to memory which has been freed.
- Best practice is to assign it to null after deallocating.

## Best practice
In C
- Always use pointers for output parameters
- Arrays → pointers
- Dynamic memory → pointer to pointer

In C++
- Input only → pass by value or const&
- Output / modify → pass by reference
- Raw pointers → only when necessary (low-level / C APIs)

## Example swap function