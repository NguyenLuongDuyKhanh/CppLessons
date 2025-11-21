#include <iostream>
#include <typeinfo>
#include <algorithm> // of #include <bits/stdc++.h>

using namespace std;

// Using std::remove
int removeindex1() {
    int sampleArr[]{1, 4, 7, 9};
    int key = 7;

    int n = sizeof(sampleArr) / sizeof(sampleArr[0]);
    auto end = std::remove(sampleArr, sampleArr + n, key);
    std::cout << typeid(end).name() << std::endl; // end is an int*

    // Calculate the new size of the array
  	// after removal
    n = end - sampleArr; // without this line of code, sampleArr's size stands at 4 elements as the begining
    std::cout << end << " " << sampleArr << " " << n << std::endl; // the 'end' address is 12 bytes away from 'sampleArr' address -> there are 3 integers in the array
    
    std::cout << "Size of array after removing 1 element: " << sizeof(sampleArr) / sizeof(sampleArr[0]) << endl;
    for (int i = 0; i < n; i++)
        std::cout << sampleArr[i] << " ";

    return 0;
}

// Using a raw loop
int removeindex2() {
    int arr[]{1, 4, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // The element which we have to delete
    int key = 7;

    // Search key in array
    for (int i = 0; i < n; i++) {

        // If key is found in array
        if (arr[i] == key) {
          
                // Reduce size of array and move all
                // elements one space towards left
                n = n - 1;
                for (int j = i; j < n; j++)
                    arr[j] = arr[j + 1];
            break;
        }
    }
    std::cout << "Size of array after removing 1 element: " << sizeof(arr) / sizeof(arr[0]) << endl;

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    return 0;
}

int main() {
    // removeindex1();
    removeindex2();
    return 0;
}