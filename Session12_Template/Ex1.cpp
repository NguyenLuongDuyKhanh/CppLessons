#include <iostream>
using namespace std;

template<typename T>
T Max(T x, T y) {
    cout << typeid(T).name() << endl;
    return x > y ? x: y;
}

int main() {

    Max(static_cast<float>(3), 5.5f); // f

    // Override the compilers deduction process
    Max<double>(3,6.2); // d
    return 0;
}