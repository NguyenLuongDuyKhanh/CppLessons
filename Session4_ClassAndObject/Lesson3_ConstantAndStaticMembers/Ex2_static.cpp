#include "Ex2_static.h"

int SampleClass::samplePrivateStatic = 10;
int SampleClass::samplePublicStatic{5};
void SampleClass::setter(int var) {
    samplePrivateStatic = var;
    // Cannot access non-static member in a static function 
    // sampleNonStaticMember = 1000;
}

int SampleClass::getter() {
    return samplePrivateStatic;
}
int main() {
    SampleClass sampleObject = SampleClass();
    cout << sampleObject.samplePublicStatic << endl;
    cout << sampleObject.getter() << endl;
    // Cannot be accessed using class name
    // cout << SampleClass.samplePublicStatic;
    // SampleClass.setter(67);

    // Can access using class name
    SampleClass::setter(67);

    cout << sampleObject.getter() << endl;
    return 0;
}