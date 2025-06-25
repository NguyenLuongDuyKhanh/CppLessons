// C++ program to demonstate the use of catch all
// in exception handling.

#include <iostream>
using namespace std;

// Define a class named Test
class Test {
    public:
        // Constructor of Test
        Test() { cout << "Constructor of Test " << endl; }
        // Destructor of Test
        ~Test() { cout << "Destructor of Test " << endl; }
};

// Empty class 
class MyPrimeException : public exception{ 
    public:
    MyPrimeException() : msg("No message") {}
    MyPrimeException(const char* message) : msg(message) {}

    // Override the what() method to provide an error message.
    const char* what() const throw() {
        return msg.c_str();
    }

    private:
        string msg;
};

// Empty class 
class MyPrimeException_1 : public MyPrimeException{ 
    public:
    MyPrimeException_1(const char* message) : msg(message) {}

    // Override the what() method to provide an error message.
    const char* what() const throw() {
        return msg.c_str();
    }

    private:
        string msg;
};

void sampleFunction() {
    
    try {
        Test a;
        for (int i=0; i<5 ;i++) {
            //if (i == 2) throw MyPrimeException_1("Exception1");
            if (i == 4) throw MyPrimeException("Exception");
        }
    } catch (MyPrimeException_1) {
        cout << "Caught MyPrimeException_1";
    }
    cout << "If an exception is handled within this function, this message will be printed." << endl;
}


int main()
{
    // try block
    try {

        // throw
        sampleFunction();
    }

    // catch block
    catch (MyPrimeException excp) {
        cout << "Caught " << excp.what();
    }

    // catch all
    catch (...) {
        cout << "Default Exception\n";
    }
    return 0;
}