#include <iostream>
using namespace std;

class Sample {
private:
    int attr;

public:
    Sample() : attr(123) {
        cout << "Constructor is called" << endl;

    }

    int getAttr() {
        return attr;
    }
};

int main() {
    /* Using 'new' will do 2 things
        - Allocate memory
        - Initialize object
    -> Therefore, the constructor is called for b and the value of b.attr is 123
    */
    Sample* b = new Sample();
    cout << b->getAttr() << endl;

    /* Using mallock allocate memory only, it won't called constructor
    -> Therefore, no constructor called and the value of a.attr is 0
    */
    Sample* a = (Sample*)malloc(sizeof(Sample));
    cout << a->getAttr() << endl;
    return 0;
}