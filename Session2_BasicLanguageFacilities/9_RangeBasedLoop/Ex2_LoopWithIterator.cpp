#include <iostream>
using namespace std;

int main() {
    int arr[]{1,2,3};

    int *begin_ptr = std::begin(arr);
    int *end_ptr = std::end(arr);

    while (begin_ptr!=end_ptr) {
        cout << *begin_ptr << " ";
        begin_ptr++;
    }

    return 0;
}