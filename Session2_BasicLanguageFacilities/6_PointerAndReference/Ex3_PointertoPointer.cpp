#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int sampleFunction(int**);
int main() {
    int var = 10;
    
    // Store the address of 
    // var variable
    int* ptr1 = &var;
    int** ptr2 = &ptr1;
    
    // Access values using (*)
    // operator
    cout << *ptr1 << endl;
    cout << **ptr2 << endl;

    sampleFunction(ptr2);
    return 0;
}

int sampleFunction(int** aPointertoPointer) {
    cout << aPointertoPointer << endl; 
    cout << *aPointertoPointer << endl;     // Dereference one
    cout << **aPointertoPointer << endl;    // Dereference twice
    return 0;
}