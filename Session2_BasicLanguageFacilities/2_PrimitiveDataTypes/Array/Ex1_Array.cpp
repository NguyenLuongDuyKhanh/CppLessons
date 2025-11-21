// Variable Length Arrays (VLAs) in C++, also known as runtime-sized or variable-sized arrays
#include <iostream>

// function to initialize array
void initialize(int* arr, int size)
{
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

// function to print an array
void printArray(int size)
{
    // variable length array
    int arr[size];
    initialize(arr, size);

    for (int i = 0; i < size; i++) {
        std::cout <<arr[i];
    }
}

// driver code
int main()
{
    int n;
    printf("Enter the Size: ");
    std::cin >> n;
    printArray(n);

    return 0;
}