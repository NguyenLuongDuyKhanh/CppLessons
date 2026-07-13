#include "iostream"
#include "Ex4_MoveSemanticsInteger.h"

/* Default constructor */
Integer::Integer() {
    cout << "Integer()" << endl;
    m_pInt = new int(0);
}

/* Parameterized constructor */
Integer::Integer(int value) {
    cout << "Integer(int value)" << endl;
    m_pInt = new int(value);
}

/*  Copy constructor - Deep copy 
    Allocate dedicated memory for the new object which copy value from the source obj.
*/
Integer::Integer(const Integer &obj) {
    cout << "Integer(const Integer &obj)" << endl;
    m_pInt = new int(*obj.m_pInt);
}

/*  Move semantics - Shallow
    We steal resource from the obj, no need dedicated memory for this
*/
Integer::Integer(Integer &&obj) {
    cout << "Integer(Integer &&obj)" << endl;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

int Integer::GetValue() const{
    return *m_pInt;
}

void Integer::SetValue(int value) {
    *m_pInt = value;
}

Integer::~Integer() {
    cout << "~Integer()" << endl;
    delete m_pInt;
}

Integer Add(const Integer &a, const Integer &b) {
    Integer temp; 
    temp.SetValue(a.GetValue() + b.GetValue());
    return temp;
}
int main() {
    Integer a(1);

    //auto b{static_cast<Integer &&>(a)}; // Cast a to r-value -> call the move constructor
    //cout << b.GetValue() << endl;

    auto c{std::move(a)};               // This call the move constructor explicitly
    cout << c.GetValue() << endl;
    a.SetValue(10); // Seg faul -> memory of 'a' no longer exist, it is tranformed to r-value hence does not its own value.
    
    cout << c.GetValue();

    return 0;
}