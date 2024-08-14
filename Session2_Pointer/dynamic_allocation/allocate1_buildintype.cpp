#include <iostream>

int main() {

    int i{5};
    std::cout << sizeof(i) << std::endl;
    // Pointer initialized with NULL
    // Then request memory for the variable
    int *ptr1 = NULL; 
    std::cout << sizeof(ptr1) << std::endl;
    std::cout << ptr1 << std::endl; // 0
    ptr1 = new int;   
    std::cout << ptr1 << std::endl; // 0xc594a0

    // Combine declaration of pointer 
    // and their assignment
    int *ptr2 = new int;            // 0xc594b0
    std::cout << ptr2 << std::endl;

    int *array1 = new int[2];
    std::cout << array1 << " Array 1" << std::endl;
    std::cout << &array1[0] << std::endl;
    std::cout << &array1[1] << std::endl;

    int *array2 = new int[2];
    std::cout << array2 << " Array 2" << std::endl;
    std::cout << &array2[0] << std::endl;
    std::cout << &array2[1] << std::endl;
}