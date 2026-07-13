#include <iostream>
using namespace std;


class SampleClass {
private:
    // Cannot have a private constructor
    // SampleClass();
    int samplePrivateAttr1 = 1;
    int samplePrivateAttr2 = 2;
    int samplePrivateAttr3;

    // Cannot use auto
    // Ex1.h:12:5: error: non-static data member declared with placeholder ‘auto’
    // auto sampleVar = 5; 
public:
    // Default constructor
    SampleClass();

    // Parameterized constructor
    SampleClass(int);

    // Getter
    void getPrivateAttr();

    int samplePublicAttr;
    ~SampleClass();
};