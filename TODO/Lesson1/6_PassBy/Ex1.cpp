/* This example investigate the concern whether pass by value call the object's constructor?*/
#include <iostream>
using namespace std;

class SampleA {
    private:
        int a = 10;
    
    public:
        // Default constructor
        SampleA() {
            cout << "Default constructor is called." << endl;
        }
        // Copy constructor
        SampleA( const SampleA &obj) {
            cout << "Copy constructor is called." << endl;
        }
};

void takeValue(SampleA a) {

}

void takeReference(SampleA &a) {

}

int main() {
    // This line call a default constructor
    SampleA a;

    // This call copy constructor
    takeValue(a);

    // This does not call any constructor, there is no memory is occupied
    takeReference(a);

    return 0;
}