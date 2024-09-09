#include <iostream>
using namespace std;

class SampleClass {
private:
    int privateAttr;
    // int privateAttr2;
    int privateMethod();
public:
    int publicAttr;
    int publicMethod();
    int privateAttrGetter();
};