#include "Ex1.h"

//! It is okay to define public method outside class
int SampleClass::publicMethod() {
    cout << "Hello publicMethod" << endl;
    privateMethod();
    return 0;
}

//! It is okay to define private method outside class
int SampleClass::privateMethod() {
    cout << "Hello privateMethod" << endl;
    return 0;
}

int SampleClass::privateAttrGetter() {
    return this->privateAttr;
}

int main() {
    cout << "Hello" << endl;

    SampleClass sampleObject;

    // An uninitialized int is 0 by default
    cout << sampleObject.publicAttr << endl;

    // An uninitialized member is random by default
    cout << sampleObject.privateAttrGetter() << endl;

    // Size of an object depends on its member data (regardless what modifiers)
    cout << "Size of object " << sizeof(sampleObject) << endl;

    sampleObject.publicMethod();

    // It is not allowed to call a private method
    // sampleObject.privateMethod(); 

    // If an instance is initialized as a pointer, its member must be access by ->
    SampleClass* ptrSampleObject = new SampleClass;

    // Size of an object pointer does not depend on its members
    cout << "Size of an object pointer " << sizeof(ptrSampleObject) << endl;

    cout << ptrSampleObject->privateAttrGetter() << endl;
    cout << ptrSampleObject->publicAttr << endl;

    return 0;
}