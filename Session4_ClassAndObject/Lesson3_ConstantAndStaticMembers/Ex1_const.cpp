#include "Ex1_const.h"

int SampleClass::regularMethod(int param){
    this->sampleAttr1 *= param;
    return sampleAttr1;
}

int SampleClass::constMethod(int param) const {
    // Cannot make this change
    // error: assignment of member ‘SampleClass::sampleAttr1’ in read-only object
    // this->sampleAttr1 *= param;
    return sampleAttr1;
}

int main() {
    /*
        Normal object can call all methods
    */
    SampleClass sampleObjectA = SampleClass();
    cout << sampleObjectA.constMethod(2) << endl;
    cout << sampleObjectA.regularMethod(2) << endl;

    /*
        Const object can call only const method

    */
    SampleClass const sampleObjectB = SampleClass();
    cout << sampleObjectB.constMethod(2) << endl;
    // cout << sampleObjectB.regularMethod(2) << endl;
    return 0;
}