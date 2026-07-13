#include <iostream>
using namespace std;

class Integer {
private:
    
public:
    /* If m_pInt is private, we need to declare friend functions thereby those functions can access private attr */
    int *m_pInt;
    /* Constructor */
    Integer();
    //explicit Integer(int); // Using explicit with this parameterized constructor to avoid implicit call
    Integer(int); 
    Integer(const Integer &object); // Copy constructor
    Integer(Integer && obj);        // Move constructor

    /* Binary operator */
    Integer operator+(const Integer &) const;
    
    /* Unary Operator */
    Integer & operator ++();    // Pre-increment
    Integer operator ++(int);   // Post-increment

    /* Dereference operator */
    int& operator*();
    
    /* Pointer member access */
    int operator->();

    /* Address of */
    int* operator&();

    /* Assignment operator */
    Integer & operator=(const Integer &a);  // Copy assignment operator
    Integer & operator=(Integer && obj);    // Move assignment operator

    /* Friend */
    friend std::istream & operator >>(istream &in, Integer &a);

    /* Type conversion */
    /* This helps to convert an Interger to primitive int, without this Example 3 will fails*/
    operator int();
    /* Adding explicit as below force user to call this conversion explicitly, to avoid implicitly call conversion */
    // explicit operator int();
    
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

class Printer {

};