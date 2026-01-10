#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[]{1,2,3};

    // Convention loop with array
    int i{0};
    for (; i<3; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    // Range based loop with raw array
    for (int x: arr) {
        cout << x << " ";
    } cout << endl;

    // Range based loop with container
    vector<int> v(arr, arr+3);
    for (int x: v) {
        cout << x << " ";
    } cout << endl;

    // Range based loop with literal
    for (int x: {1,2,3}) {
        cout << x << " ";
    } cout << endl;

    return 0;
}