#include <iostream>
using namespace std;

class MyArray {
private:
    int* data1;
    int* data2;

public:
    MyArray() : data1(new int(10)), data2(new int(20)) {
    }

    ~MyArray() {
        delete data1;
        delete data2;
    }

    // Non-const version for read/write access
    int& operator[](unsigned int index) {
        // Add bounds checking for safety
        if (index == 0) {
            return *data1;
        } else {
            return *data2;
        }
    }

    // Const version for read-only access (when the object is const)
    const int& operator[](unsigned int index) const {
        // Add bounds checking
        if (index == 0) {
            return *data1;
        } else {
            return *data2;
        }
    }

    // Function call operator
    void operator()() {
        cout << "Function call operator is called" << endl;
    }

};


int main() {
    MyArray a;
    cout << a[1] << endl; // retun 20;
    a();

    return 0;
}
