#include <typeinfo>
#include <iostream>
#include "main_file.h"
#include "sub_folder/sub_header.h"

using namespace std;

int global_int_var = 5;
/*
    Functions declaration
*/
void functionA();

int main()
{
    functionA();
    /*
        functions has to be declared (in header file), and defined (in source file) before use.
        Without any of thoes, function cannot be used
    */
    functionB();
    /*
        Function was declared and defined in sub_folder header file
    */
    functionC();
    int int_variable = 1;
    cout<<typeid(int_variable).name() << endl;          // i
    cout<<sizeof(int_variable) << endl;

    char char_variable = 'a';
    cout<<typeid(char_variable).name() << endl;         // c
    /*
        Pointer's size depends on architechture, regardless data type of var it points to
    */
    int* intptr_variable = &int_variable;
    cout<<typeid(intptr_variable).name() << endl;       // Pi
    cout<<sizeof(intptr_variable) << endl;
    
    float *floatptr_variable;
    cout<<typeid(floatptr_variable).name() << endl;     // Pf
    cout<<sizeof(floatptr_variable) << endl;            // 8 
}

/*
    Functions definition 
*/
void functionA()
{
    //Whenever there is a local variable defined with same name as that of a global variable then the compiler will give precedence to the local variable
    int global_int_var = 10;
    cout<<"Printed by function A"<< global_int_var<< endl;
}

void functionB()
{
    cout<<"Printed by function B" << endl;
};