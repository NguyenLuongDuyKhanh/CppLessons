#include <iostream>
using namespace std;

class SampleClass {
private:
    int sampleAttr1{5};
public:
    int regularMethod(int);
    int constMethod(int) const;
};