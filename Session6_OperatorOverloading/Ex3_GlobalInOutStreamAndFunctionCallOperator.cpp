#include "Integer.h"

Integer operator+(int x, const Integer &y) {
    Integer temp;
    temp.m_pInt = x + y.m_pInt;

    return temp;
}

ostream & operator <<(ostream &out, const Integer &a) {
    out << *a.m_pInt;
    return out;
}

istream & operator >>(istream &in, Integer &a) {
    int x;
    in >> x;
    *a.m_pInt = x;

    return in;
}

int main() {
    Integer a(1), b(2);

    /* This line need and operator 1.operator+(Interger)
        -> must define the global operator+(int x, const Integer &y)
    */
    // Integer c = 1 + a;

    /*  This line need an operator a.operator+(int)

    */
    // Integer d = a + 1;
    cin >> a;
    
    cout << a << endl;

    return 0;
}