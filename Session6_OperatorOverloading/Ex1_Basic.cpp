#include "Ex1_Basic.h"

Integer::Integer() {
    m_pInt = new int(0);
}

Integer::Integer(int value) {
    m_pInt = new int{value};
}

Integer::Integer(const Integer &object) {
    m_pInt = new int{*object.m_pInt};
}

Integer::~Integer() {
    delete m_pInt;
}

Integer Integer::operator +(const Integer &arg) const {
    Integer temp;
    *temp.m_pInt = *m_pInt + *arg.m_pInt;
    return temp;
}

// This is not a class's member, hence it could not be const
// error: non-member function ‘Integer operator*(const Integer&, const Integer&)’ cannot have cv-qualifier
Integer operator *(const Integer &arg1, const Integer &arg2) {
    // This invoke the parameterized constructor
    return Integer(*arg1.m_pInt * *arg2.m_pInt);
}

int main() {
    Integer numberA{5};
    Integer numberB{2};
    
    Integer sum = numberA + numberB;
    cout << *sum.m_pInt << endl;

    Integer product = numberA * numberB;
    cout << *product.m_pInt << endl;
    
    return 0;

}