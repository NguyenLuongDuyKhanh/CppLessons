#include "namespaceTopic.h"
#include <iostream>

int sampleFunction(); // Prototype 

int sample::sampleFunction(){
    std::cout << "This is sample function in sample namespace" << std::endl;
    return 0;
}

namespace sample {
    namespace childNameSpace {
        using namespace std;
        int sampleFunction(){
            cout << "This is sample function in sample/childNamespace" << endl;
            return 0;
        }
    }
}
int main(){
    sampleFunction();
    sample::sampleFunction();
    sample::childNameSpace::sampleFunction();
    return 0;
}

int sampleFunction(){
    std::cout << "This is sample function in cpp file" << std::endl;
    return 0;
}