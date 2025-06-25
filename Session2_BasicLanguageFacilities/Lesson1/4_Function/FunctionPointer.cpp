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

template <typename T> // To accept both void and int function pointer
void someActions(T callback)
{
    cout << "The value of the product is: ";
    callback();
}

int sampleIntFunction() {
    cout << "This function return a integer" << endl;
    return 0;
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

    // Pointer function must in the same type of the function it points to
    int (*intfuncPointer)();
    intfuncPointer = &sampleIntFunction; // Assign the address
    someActions((intfuncPointer));
    return 0;
}