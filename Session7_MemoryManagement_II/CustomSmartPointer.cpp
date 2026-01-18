#include <iostream>
using namespace std;

// Defining class template
template <typename T> 
class MyCustomSmartPointer {
private:
    T *raw_ptr;
public:
    MyCustomSmartPointer() {
        raw_ptr = new T();
        cout << "Automatically construct " << endl;
    }

    ~MyCustomSmartPointer() {
        delete raw_ptr;
        cout << "Automatically deconstruct " << endl;
    }

    // Method to get values
    T getValues() {
        return *raw_ptr;
    }

    void setvalue(T value) {
        *raw_ptr =  value;
    }
};

// This function introduce a smart pointer object named 'a' whose scope is inside the function
// It means the memory of 'a' will be automatically released when it goes outside the scope. 
void aFunction() {
    MyCustomSmartPointer<int> a;
    a.setvalue(10);
    cout << a.getValues() << endl;
}

// This function introduce a pointer to smart pointer object
// It means the destructor will not be release automatically.
void aFunction2() {
    MyCustomSmartPointer<int>* a = new MyCustomSmartPointer<int>();
    a->setvalue(15);
    cout << a->getValues() << endl;
}

int main() {
    aFunction();

    aFunction2();
    return 0;
}