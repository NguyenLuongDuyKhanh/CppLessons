#include "Integer.h"

Integer & Integer::operator=(const Integer &a) {
    if (this != &a) {   // Avoid self assignment
        delete m_pInt;  // Release the memory hodling by this object currently before assiging new memory, to avoid memory leak
        m_pInt = new int(*a.m_pInt);
    } 
    return *this;
}

Integer & Integer::operator=(Integer && a) {
    if (this != &a) {   // Avoid self assignment
        delete m_pInt;  // Release the memory hodling by this object currently before assiging new memory, to avoid memory leak
        m_pInt = a.m_pInt;
        a.m_pInt = nullptr;
    } 
    return *this;
}

Integer::Integer(Integer && obj) {
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

int main() {
    Integer a(1), b(2);

    a=b;
    cout << *a.m_pInt << endl;
    a=a;
    cout << *a.m_pInt << endl;

    return 0;
}
