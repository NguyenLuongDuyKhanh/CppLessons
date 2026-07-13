#include <iostream>
using namespace std;

class SampleClass {
private:
    static int samplePrivateStatic;
    int sampleNonStaticMember;
public:
    static int samplePublicStatic;
    int getter();
    static void setter(int);
};