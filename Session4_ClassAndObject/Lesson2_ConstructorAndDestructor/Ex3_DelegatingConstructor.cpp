#include "Ex3_DelegatingConstructor.h"

// This default constructor will delegate to parameteried constructor before executing itself
SampleClass::SampleClass() : SampleClass::SampleClass(0) {
    cout << "SampleClass()" << endl;
}

SampleClass::SampleClass(int intParam) : SampleClass::SampleClass(intParam, 0) {
    cout << "SampleClass(int intParam)" << endl;
}

// This constructor will be called first, 
// Hence the common stuff should be put here to avoid duplicated code
SampleClass::SampleClass(int intParam, float floatParam) {
    cout << "SampleClass(int intParam, float floatParam)" << endl;
}

int main() {
    /*  SampleClass(int intParam, float floatParam)
        SampleClass(int intParam)
        SampleClass()
    */
    SampleClass sampleObject = SampleClass();

    return 0;
}