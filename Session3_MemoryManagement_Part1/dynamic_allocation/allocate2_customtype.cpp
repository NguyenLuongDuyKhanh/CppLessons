// C++ program to illustrate how to initialize a dynamic
// variable with allocation
#include <iostream>
//#include <memory>

using namespace std;

// Custom data type with constructor to take initial value
struct cust {
    int p;
    cust(int q)
        : p(q)
    {
    }
    cust() = default;
};

int main()
{
    // creating inbuit data types with initial value
    int* p = new int(25);
    float* q = new float(75.25);

    // Works fine, doesn’t require constructor
    cust* var1 = new cust;

    // OR

    // Works fine, doesn’t require constructor
    var1 = new cust();

    // Notice error if you comment this line
    cust* var = new cust(25);

    cout << *p << " " << *q << " " << var->p;
    return 0;
}