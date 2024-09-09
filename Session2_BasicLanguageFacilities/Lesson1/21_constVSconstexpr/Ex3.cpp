#include <iostream>
using namespace std;

int main() {
    int var1 = 1;
    int var2 = 0;
    int const var3 = 3;

    int * ptr_to_int;

    //const int * const ptr_constant_pointer_to_const_int; // Constant pointer to a constant

    //const int * ptr_to_const_int; // Pointer to constant

    int const * ptr_to_int_const; // Pointer to constant, okay to init later
    ptr_to_int_const = &var1; // Okay to point to non-constant
    cout << *ptr_to_int_const << endl;
    // *ptr_to_int_const = 60; // Cannot change assignment of read-only location ‘* ptr_to_int_const’
    ptr_to_int_const = &var3; // Okay to point to constant

    int * const ptr_const_pointer_to_int = &var1; // Constant pointers, must be initialized when declare
    // ptr_const_pointer_to_int = &var2; // Error, assignment of read-only variable ‘ptr_const_pointer_to_int’, cannot point to other object
    *ptr_const_pointer_to_int = 100; // Okay to change value in which it point to
    cout << *ptr_const_pointer_to_int << endl;

    int var0 = 0;
    const int &ptr1 = var0; // Constant reference
    // ptr1 = 8; // Error error: assignment of read-only reference ‘ptr1’, cannot change value though const
    var0 = 6; // OK cho change value at the destination
    cout << ptr1 << endl;

    return 0;
}