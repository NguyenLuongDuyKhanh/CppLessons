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