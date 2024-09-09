#include <iostream>
using namespace std;

class Integer {
private:
    
public:
    int *m_pInt;
    Integer();
    Integer(int);
    Integer(const Integer &object);

    Integer operator+(const Integer &) const;
    
    ~Integer();
};