#include <iostream>
using namespace std;

class SampleClass {
private:
    int sampleAttr{0};
public:
    SampleClass() = default; // Use the default if an error occur
    SampleClass(int Var) {
        sampleAttr = Var;
    }
    // error: ‘int SampleClass::sampleMethod()’ cannot be defaulted
    // int sampleMethod() = default;
    
    // Compiler allows passing float var here
    int sampleMethodB(int var) {
        cout << var << endl;
        return 0;
    };
    // Prevent passing float
    // int sampleMethodB(float var) = delete;

    int sampleMethod() = delete;
    // error: use of deleted function ‘SampleClass::SampleClass(SampleClass&)’
    // SampleClass(SampleClass &sampleObject) = delete;
};

/*
    Ex4_Default.cpp:19:5: error: redefinition of ‘int SampleClass::sampleMethod()’
        19 | int SampleClass::sampleMethod() {
            |     ^~~~~~~~~~~
    Ex4_Default.cpp:14:9: note: ‘int SampleClass::sampleMethod()’ previously defined here
       14 |     int sampleMethod() = delete;
          |         ^~~~~~~~~~~~
*/
// int SampleClass::sampleMethod() {
//     cout << "some thing" << endl;
// }

int main() {
    SampleClass sampleObject = SampleClass(1);
    SampleClass sampleObjectB{sampleObject};
    sampleObject.sampleMethodB(1.2);
    return 0;
}