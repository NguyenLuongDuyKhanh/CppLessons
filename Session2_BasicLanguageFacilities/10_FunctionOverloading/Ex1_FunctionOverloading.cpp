#include <iostream>
using namespace std;

// These are 2 variant of just 1 function. It is function overloading
// If several functions with exactly same signature, it cause error.
int Add(int a, int b) {
    return a+b;
}

double Add(double a, double b) {
    return a+b;
}

int main() {
    cout << Add(1,2) << endl;
    cout << Add(1.5, 2.4) << endl;

    return 0;
}