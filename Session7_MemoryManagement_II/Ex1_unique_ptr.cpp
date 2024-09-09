#include "Ex1_Basic.h"
#include <memory>

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
void Display(Integer*p) {
    if !p {
        return;
    }
    cout << p->GetValue() << endl;
}
Integer * GetPointer() {
    Integer *p = new Integer(2);
    return p;
}

void Operate() {
    unique_ptr<Integer*> = GetPointer()
    cout << 
}

int main() {

    Operate(5);
    return 0;
}