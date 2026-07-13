#include <iostream>
using namespace std;

int multiply(int a, int b) { return a * b; }
int add() { return 1+2; }

// Function containing function pointer
// as parameter
void print(int (*funcptr)())
{
    cout << "The value of the operation is: " << funcptr()
         << endl;
}

int main()
{
    int (*func)(int, int);

    // func is pointing to the multiplyTwoValues function

    func = multiply;

    int prod = func(15, 2);
    cout << "The value of the product is: " << prod << endl;

    print(add);
    int (*func_add)() = add; // &add also works
    cout << func_add() << endl;

    return 0;
}