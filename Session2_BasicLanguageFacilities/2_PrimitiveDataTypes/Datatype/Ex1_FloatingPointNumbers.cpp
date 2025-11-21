#include <iostream>
using namespace std;


// The suffix 'f' (or 'F') appended to a floating-point literal explicitly designates it as a float type. 
// Without this suffix, a floating-point literal (e.g., 3.14) defaults to being a double type.
// It help to avoiding implicit conversions:

int main() {
    float myFloat = 3.14f; // '3.14f' is explicitly a float
    double myDouble = 3.14; // '3.14' is implicitly a double
}