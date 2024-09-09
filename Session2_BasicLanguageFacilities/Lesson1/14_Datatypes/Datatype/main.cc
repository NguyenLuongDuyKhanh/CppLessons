#include <iostream>
#include <climits>
int main()
{
    using namespace std;
    cout << "Computing the size of some C++ inbuilt variable types" << endl;
    cout << "Size of bool: " << sizeof(bool) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of unsigned short int: " << sizeof(unsigned short) << endl;
    cout << "Size of short int: " << sizeof(short) << endl;
    cout << "Size of unsigned long int: " << sizeof(unsigned long) << endl;
    cout << "Size of long: " << sizeof(long) << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of unsigned long long: "<< sizeof(unsigned long long)<<endl;
    cout << "Size of long long: " << sizeof(long long) << endl;
    cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;    
    cout << "The output changes with compiler, hardware and OS" << endl; 
    int a;
    cout << a; // Junk values, better to be initialized first

    int arr[5];
    cout << "Type of arr5 before initializing"<<sizeof(arr);

    int arr1[] = {1,2,3,4,5};
    cout << "Size of arr5 after initializing"<<sizeof(arr1);
    
    return 0;
}
/*
    The output on raspberry pi
pi@raspberrypi:~/workspace/CppLessons/Session2_BasicLanguageFacilities/Lesson1/14_Datatypes/Datatype $ ~/bin/main.o 
Computing the size of some C++ inbuilt variable types
Size of bool: 1
Size of char: 1
Size of unsigned short int: 2
Size of short int: 2
Size of unsigned long int: 4
Size of long: 4
Size of int: 4
Size of unsigned long long: 8
Size of long long: 8
Size of unsigned int: 4
Size of float: 4
Size of double: 8
The output changes with compiler, hardware and OS
0Type of arr5 before initializing20Size of arr5 after initializing20

    The output on wsl
(base) khanh@DESKTOP-C4P51A8:~$ ./test.o 
Computing the size of some C++ inbuilt variable types
Size of bool: 1
Size of char: 1
Size of unsigned short int: 2
Size of short int: 2
Size of unsigned long int: 8
Size of long: 8
Size of int: 4
Size of unsigned long long: 8
Size of long long: 8
Size of unsigned int: 4
Size of float: 4
Size of double: 8
The output changes with compiler, hardware and OS

*/