// C++ program to demonstrate constexpr function for product
// of two numbers. By specifying constexpr, we suggest
// compiler to evaluate value at compile time
#include <iostream>

constexpr int product(int x, int y) { return (x * y); }

int main()
{
    constexpr int x = product(10, 20);
    std::cout << x;

    const int sampleVar1 = 10;
    // std::cout << sampleVar1++;
    int const sampleVar2 = 20;
    // std::cout << sampleVar2++;
    /*
        pi@raspberrypi:~/workspace/CppLessons/Session2_BasicLanguageFacilities/Lesson1/21_constVSconstexpr $ g++ -o ~/bin/main Ex2.cpp 
        Ex2.cpp: In function ‘int main()’:
        Ex2.cpp:14:18: error: increment of read-only variable ‘sampleVar1’
           14 |     std::cout << sampleVar1++;
              |                  ^~~~~~~~~~
        Ex2.cpp:16:18: error: increment of read-only variable ‘sampleVar2’
           16 |     std::cout << sampleVar2++;
              |                  ^~~~~~~~~~
    */
    return 0;
}