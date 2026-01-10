#include <iostream>
#include <stdio.h>
#include <string.h> 
using namespace std;

int main() {
    char *p = new char[4]; // One extra byte for the null character at the end
    strcpy(p, "C++");
    cout << p << endl;
    delete[] p;

    return 0;
}