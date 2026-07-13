#include <iostream>
using namespace std;

// This with bound to the function call that provide l-value reference
void Print(int &x) {
    cout << "Print(int &x)" << endl;
}

// Though const l-value reference can also accept r-value reference, 
// this variant often be ignore with an r-value reference is provided 
// if there is a variant that accept r-value reference like the third in this example.
void Print(const int &x) {
    cout << "Print(const int &x)" << endl;
} 

void Print(int &&x) {
    cout << "Print(int &&x)" << endl;
}

int main() {
    int x = 10;
    Print(x);
    Print(3);

    return 0;
}