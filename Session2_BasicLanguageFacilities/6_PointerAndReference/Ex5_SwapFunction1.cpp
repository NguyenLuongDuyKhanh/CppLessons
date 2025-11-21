#include <iostream>

void Swap(int x, int y) {
    int temp{x};
    x = y;
    y = temp;
}

int main() {
    using namespace std;
    int a{5}, b{10};
    Swap(a, b);

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    return 0;
}