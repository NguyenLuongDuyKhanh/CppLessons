#include "Integer.h"



/* This is the member operation */
Integer Integer::operator +(const Integer &arg) const {
    Integer temp;
    *temp.m_pInt = *m_pInt + *arg.m_pInt;
    return temp;
}

/* This is The global operation
    - No need to be inside the class.
    - Need 2 arguments.
*/
Integer operator *(const Integer &arg1, const Integer &arg2) {
    // This invoke the parameterized constructor
    return Integer(*arg1.m_pInt * *arg2.m_pInt);
}

/* Post increament */
Integer & Integer::operator++() {
    ++(*m_pInt);
    return *this;
}

/* Post increament return the object first then increase afterward */
Integer Integer::operator++(int) {
    Integer temp(*this);    // Invoke copy constructor
    ++(*m_pInt);

    return temp;
}


int main() {
    Integer numberA{5};
    Integer numberB{2};
    
    Integer sum = numberA + numberB;
    cout << *sum.m_pInt << endl;

    Integer product = numberA * numberB;
    cout << *product.m_pInt << endl;
    
    numberA++;
    cout << "Test the post increment operator numberA++ " << *numberA.m_pInt << endl;

    ++numberB;
    cout << "Test the pre increment operator numberB++ " << *numberB.m_pInt << endl;
    return 0;

}