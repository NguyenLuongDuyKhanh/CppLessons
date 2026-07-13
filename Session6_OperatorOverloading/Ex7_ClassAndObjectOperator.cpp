/*  Dereference *
    Pointer member access ->
    Address of
*/

#include <iostream>
#include "Integer.h"
using namespace std;


/* Dereference operator */
int& Integer::operator*(){
    cout << "Deference operator is called";
    return *m_pInt;
};

int Integer::operator->(){
    cout << "Pointer member access operator is called" << endl;
    return *m_pInt;
};

int* Integer::operator&() {
    cout << "Address of operator is called" << endl;
    return m_pInt;
};

int main() {
    Integer a(10);
    cout << *a << endl;
    cout << &a << endl;

    Integer* b= new Integer(5);
    cout << b->m_pInt << endl;

    return 0;
}