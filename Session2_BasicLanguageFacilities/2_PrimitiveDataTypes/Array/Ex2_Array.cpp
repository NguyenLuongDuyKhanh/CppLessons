#include <iostream>

using namespace std;

int passArrayAsSizedArray(const char a[7])
{
    /* size in passArrayAsSizedArray 4 - size of the pointer*/
    cout << "size in passArrayAsSizedArray " << sizeof(a) << endl;  

    /*  Ex1.cpp:10:10: error: assignment of read-only location ‘*(a + 1)’
    *   10 |     a[1] = 'u';
    */
    // a[1] = 'u';
}

int passArrayAsUnsizedArray(char arr[]) {
    /* size in passArrayAsUnsizedArray 4 - size of a pointer */
    cout << "size in passArrayAsUnsizedArray " << sizeof(arr) << endl;

    /*  When you have a function parameter that is declared as an array, 
    *   it is adjusted to a pointer type.
    *   Hence, range-based for loops cannot be used
    *   Ex1.cpp:8:19: error: ‘end’ was not declared in this scope; did you mean ‘std::end’?
    *   8 |     for (char x : arr) {
    */
    // for (char x : arr) {
    //     cout << &arr << endl;
    // }

    /* There's an overload of operator<< for char*, hence (void *) is used */
    cout << "reference in passArrayAsUnsizedArray " << (void *)arr << endl;

    for (int i=0; i < sizeof(arr); i++) {
        cout << *((char *)(arr+i)) << " is " << (void *)(arr+i) << endl;
    }

    return 0;
}

int passArrayAsPointerImplicit(char *a) {
    /* passArrayAsPointerImplicit 4 - size of a pointer */
    cout << "passArrayAsPointerImplicit " << sizeof(a) << endl;

    for (int i = 0; i < 5; i++)
        cout << *(a + i) << " is " << (void*)(a + i) << endl;
    return 0;
}


int passArrayAsReference(char (&arr)[7]) {
    /* passArrayAsReference 7 - size of array */
    cout << "passArrayAsReference " << sizeof(arr) << endl;
    for (char& x : arr) {
        cout << &x << " is " << x << endl;
    }

    return 0;
}

int main() {
    char arr[] = {'a', 'q', 'k', 'w', 'f', 'j', 'l'};

    /* size in main 7 - size of the array*/
    cout << "size in main " << sizeof(arr) << endl;
    cout << "reference of each element in main "<< endl;

    for (char& x : arr) {
        cout << (void*)&x << endl;
    }
    cout << (void*)&arr << endl;

    /* Pass as an array*/
    // passArrayAsUnsizedArray(arr);

    // passArrayAsSizedArray(arr);

    // passArrayAsPointerImplicit(arr);

    // passArrayAsReference(arr);
    

    // Using range-based for loop with reference
    
      

    return 0;
}