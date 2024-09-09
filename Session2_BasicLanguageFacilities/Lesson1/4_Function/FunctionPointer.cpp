#include <iostream>
using namespace std;

void sampleFunction(int a=0, int b=0) {
    cout << "Some feature in sampleFunction " << a+b << endl; 
}

void sampleFunction2() {
    cout << "Some feature in sampleFunction2 " << endl; 
}


void samplePointerFunction() {
    cout << "Some feature in samplePointerFunction" << endl;
}

void someActions(void (*callback)())
{
    cout << "The value of the product is: " << endl;
    callback();
}

int main() {

    // 1 1
    cout << sampleFunction << endl;
    cout << samplePointerFunction << endl;

    auto sampleA = sampleFunction;
    auto sampleB = samplePointerFunction;
    // 1 1
    cout << sampleA << endl;
    cout << sampleB << endl;

    sampleA(1,2);
    sampleB();

    void (*func)(int, int);
    func = sampleFunction;
    func(2,6);


    // Passing a function pointer as a parameter
    void (*funcPointer)();
    funcPointer = sampleFunction2;
    someActions((funcPointer));
    return 0;
}