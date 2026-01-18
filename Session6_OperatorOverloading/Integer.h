#include <iostream>
using namespace std;

class Integer {
private:
    
public:
    int *m_pInt;
    /* Constructor */
    Integer();
    Integer(int);
    Integer(const Integer &object); // Copy constructor
    Integer(Integer && obj);        // Move constructor

    /* Binary operator */
    Integer operator+(const Integer &) const;
    
    /* Unary Operator */
    Integer & operator ++();    // Pre-increment
    Integer operator ++(int);   // Post-increment

    /* Assignment operator */
    Integer & operator=(const Integer &a);  // Copy assignment operator
    Integer & operator=(Integer && obj);    // Move assignment operator

    /* Destructor */
    ~Integer();
};

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