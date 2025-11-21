#include <iostream>

int main(){
    int x(10);

    int *ptr = &x;

    std::cout << ptr << std::endl;          //0x7e8a3318
    std::cout << *ptr << std::endl;         //10

    x = 15;

    std::cout << ptr << std::endl;          //0x7e8a3318
    std::cout << *ptr << std::endl;         //15
    
    // Use dereference operator to indirectly access a variable
    *ptr = 20;

    std::cout << ptr << std::endl;          //0x7e8a3318
    std::cout << *ptr << std::endl;         //20
    std::cout << x << std::endl;            //20

    float *sampleNullPtr = nullptr;
    std::cout << sampleNullPtr << std::endl;  // 0
    //std::cout << *sampleNullPtr << std::endl; //Segmentation fault

    sampleNullPtr = new float(1.2);

    std::cout << sampleNullPtr << std::endl;  // 0x13704a0
    std::cout << *sampleNullPtr << std::endl; // 1.2

    char *sampleNull = NULL;

    std::cout << sampleNull << std::endl;  // Segmentation fault
    std::cout << *sampleNull << std::endl; // 1.2
    return 0;
}