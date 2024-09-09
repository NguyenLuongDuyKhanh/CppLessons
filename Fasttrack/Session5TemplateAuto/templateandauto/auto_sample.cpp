#include <iostream>
#include <typeinfo>
using namespace std;

/*
    cannot use auto in function declaration, it will lead into
    error: use of ‘auto functionA()’ before deduction of ‘auto’s
    auto cannot be used as parameter
*/
char functionA();
int functionB();
// trailing return type.
auto functionC() -> void;

int main() {
    auto variable(2.5); // have to put inititial value to make auto works
    cout << typeid(variable).name() << endl; // d
    auto var = functionA();
    cout << typeid(var).name() << endl;         // c
    cout << typeid(functionB()).name() << endl; // i
    functionC();
}

char functionA() { return 'a'; }

int functionB() { return 1; }
auto functionC() -> void { cout << "this is functionC" << endl; }