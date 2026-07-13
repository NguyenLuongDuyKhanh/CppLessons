#include "Ex1.h"

// Default constructor
SampleClass::SampleClass() {
    cout << "Default constructor is called" << endl;
    
}

// Parameterized constructor
// Uniform Initialization
SampleClass::SampleClass(int number1) :
    samplePrivateAttr3(7),
    samplePrivateAttr1(number1)
{
    cout << "Parameterized constructor is called" << endl;
    samplePrivateAttr2 = samplePrivateAttr1 * 10;
}

void SampleClass::getPrivateAttr() {
    cout << "samplePrivateAttr1 " 
        << samplePrivateAttr1
        << " samplePrivateAttr2 "
        << samplePrivateAttr2
        << " samplePrivateAttr3 "
        << samplePrivateAttr3;
}

SampleClass::~SampleClass() {
    cout << "Default destructor is called" << endl;
}

int main() {
    // Involke default constructor
    SampleClass  sampleInstance1; 
    // samplePrivateAttr1 1 samplePrivateAttr2 2 samplePrivateAttr3 2123526592
    sampleInstance1.getPrivateAttr();

    // Involke parameterlized constructor
    SampleClass  sampleInstance2(5); 
    // samplePrivateAttr1 5 samplePrivateAttr2 50 samplePrivateAttr3 7
    sampleInstance2.getPrivateAttr();

    return 0;
}