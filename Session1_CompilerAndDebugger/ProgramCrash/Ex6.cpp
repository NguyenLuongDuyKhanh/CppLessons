#include <iostream>
int function() {
    std::cout << "something" << std::end;
}
int main() {
    int arr[5] = {1, 2, 3, 4, 5}; // Array with 5 elements
    std::cout << arr[10] << std::endl; // Accessing out-of-bounds element
    int a = function();
    return 0;
}