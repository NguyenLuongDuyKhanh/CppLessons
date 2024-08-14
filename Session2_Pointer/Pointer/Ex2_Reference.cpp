#include <iostream>

int main(){
    unsigned int x{10};

    //Reference
    unsigned int &ref = x;
    int y{20};

    std::cout<< "x" << &x << " " << x << std::endl;         // x0x7eb632f4 10
    std::cout<< "ref" << &ref << " " << ref << std::endl;   // ref0x7eb632f4 10

    ref = 6;

    std::cout<< "x" << &x << " " << x << std::endl;         // x0x7eb632f4 6
    std::cout<< "ref" << &ref << " " << ref << std::endl;   // ref0x7eb632f4 6
    return 0;
}