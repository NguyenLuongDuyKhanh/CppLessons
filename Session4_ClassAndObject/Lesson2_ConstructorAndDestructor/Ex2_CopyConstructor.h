#include <iostream>
using namespace std;

class Integer {
    /*
        This class has a pointer member.
        Default copy constructor will copy this address to new object (shadow copy)
        Hence, every action that done to one object will afect both.
        In this error, destructor was called twice on just one pointer
            free(): double free detected in tcache 2
            Aborted
        
    */
    int* m_pInt;
public:
    // Default constructor
    Integer();
    // Parameterized constructor
    Integer(int);
    // Copy constructor
    Integer(Integer &object);
    
    int GetValue() const;
    void SetValue(int);
    
    // Destructor
    ~Integer();
};