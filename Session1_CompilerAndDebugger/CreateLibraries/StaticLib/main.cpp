// main.cpp

#include "myLib.h"
#include <iostream>
using namespace std;

int main()
{
    // calling sayHello() function
    sayHello();

    // calling addNumbers function and storing the result
    int result = addNumbers(5, 7);
    cout << "The result is: " << result << "\n";

    return 0;
}