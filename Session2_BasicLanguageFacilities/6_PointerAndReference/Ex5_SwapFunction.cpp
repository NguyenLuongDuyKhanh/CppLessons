#include <iostream>

void Swap_by_value(int x, int y) {
    int temp{x};
    x = y;
    y = temp;
}

/*aka pass by pointer*/
void Swap_by_address(int *x, int *y) {
    int temp{*x};
    *x = *y;
    *y = temp;
}

void Swap_by_reference(int &x, int &y) {
    int temp{x};
    x = y;
    y = temp;
}

int main() {
    using namespace std;

    /*  This piece of code try to swap a<->b
        Swap_by_value cannot swap these 2 variable. 
        It actually create a copy of a and b, and swap the value of those copied varibale, thus the origin a and b are not affected.
    */
    int a{5}, b{10};
    Swap_by_value(a, b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    /* Swap_by_address can swap.
    */
    int c{5}, d{10};
    Swap_by_address(&c, &d);
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;

    /* Swap_by_address can swap.
    */
    int e{5}, f{10};
    Swap_by_reference(e, f);
    cout << "e: " << e << endl;
    cout << "f: " << f << endl;
    return 0;
}