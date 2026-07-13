#include <iostream>
#include "Integer.h"
using namespace std;

void Example4();
void Example3();
void Example2();
void Example1();

/* This helps to convert an Interger to primitive int, without this Example 3 will fails*/
Integer::operator int() {
    return *m_pInt;
}

int main() {
    

    Example4();
    return 0;
}

/* Casting basic -> basic type */
void Example1() {

    int a = 10;

    /*  This piece of code show how C-style casting can be problematic
        C-style allow this invalid cast while static_case rise invalic conversion error
    */
    // char* b = (char*)&a;
    // char* b = static_cast<char*>(&a);
    
    /* This is another case where C-style casting must be avoided
        We dont expect 'x' to be changed this way.
    */
    const int x =5;
    int *p = (int*)&x;
    *p = 9;
    cout << *p << endl;
}

/* Casting basic -> user-defined type */
void Example2() {
    Integer a{5};

    // Initialization
    Integer b = 5; // Implicitly call constructor

    // Assignment
    //a = 7; // Implicitly call assignment operator
}

/* Basic -> user-defined type */
void Example3() {
    Integer a1{10};

    Integer a2 = 5;

    // Assignment
    int x = a1; // Cast an integer to 
    cout << x << endl;
}

/* User defined -> user defined */
void Example4() {
    class AnotherInteger {
        private:
            Integer m_Id;
        public:
            AnotherInteger(const Integer &id) : m_Id{id} {
                cout << "AnotherInteger" << endl;
            }
            
            /* Conversion operator to convert to an Interger */
            operator Integer() {
                return m_Id;
            }

            ~AnotherInteger(){cout << "~" << endl;}
    };
    AnotherInteger a{5};
    Integer id = a; // Convert AnotherInteger -> Integer, no suitable convert

}
