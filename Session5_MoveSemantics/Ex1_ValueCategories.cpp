#include <iostream>
using namespace std;

// Returns r-value
int Add(int x, int y){
    return x+y;
}

// Returns the value of x, same as Add
int Transform_value(int &x) {
    x *= x;
    return x;
}

// Returns l-value
int &Transform_reference(int &x) {
    x *= x;
    return x;
}

int main() {
    // x,y, z are l-values 
    // 5, 10, 8 are r-values
    int x=5;
    int y=10;
    int z=8;

    // Expression returns r-value
    int result=(x+y)*z;

    // Expression returns l-value
    ++x = 10; // This line returns 10

    // int a = Transform(3); // cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    cout << &Transform_reference(y) << endl;

    Transform_reference(x) = 5; // This is totally fine because an l-value can be assigned by a litteral with same type

    /* r-value reference allow us to detect temporary/expression
    */
    int &&r1 = 10;
    int &&r2 = Add(3,2);
    // int &&r3 = x; // r-value reference cannot be bind to l-value, this canbe dont if r3 is a normal reference (l-value reference).
    
    /* const l-value reference can also reference to a r-value
    */
    const int &r4 = Add(1,1);

    return 0;
}