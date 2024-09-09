#include "Ex2_CopyConstructor.h"

Integer::Integer() {
    m_pInt = new int(0);
}

Integer::Integer(int value) {
    m_pInt = new int(value);
}

Integer::~Integer() {
    delete m_pInt;
}

Integer::Integer(Integer &object) {
    m_pInt = new int{*object.m_pInt};
}

int Integer::GetValue() const {
    return *m_pInt;
}

// Invoke copy constructor
void print(Integer i) {

}

Integer Add(int x, int y) {
    // Invoke copy constructor
    return Integer(x+y);
}

void exampleDeepCopyAndShadowCopy() {
    int* ptr1 = new int{5};
    // shadow copy
    int* ptr2 = ptr1;

    // deep copy
    int* ptr3 = new int{*ptr1};
    
    /*
        0x14dd098, 5
        0x14dd098, 5
        0x14dd0a8, 5
    */
    cout << ptr1 << ", "<< *ptr1 << endl;
    cout << ptr2 << ", "<< *ptr2 << endl;
    cout << ptr3 << ", "<< *ptr3 << endl;

}
int main() {
    exampleDeepCopyAndShadowCopy();
    Integer i{5};

    // Invoke copy constructor
    Integer i2{i};

    cout << i.GetValue() << endl;

    return 0; 
}