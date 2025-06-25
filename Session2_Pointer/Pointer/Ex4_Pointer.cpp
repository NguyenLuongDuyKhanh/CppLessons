#include <iostream>
using namespace std;

int sampleFunction(int* array);

int main() {
  int arr[]{5,9,11};
  cout << &arr[0] << endl;
  cout << "Derefer " << *(&arr[0] + 1)<< endl; // Derefer
  cout << &arr[2] << endl;
  cout << &arr << "," << &arr[0] << endl;
  cout << "Modify the address to get the values " << (int*)(&arr + 1) << endl; // + 1 mean +4 bytes
  cout << "Modify the address to get the values " << (&arr[0] + 2) << endl;

  cout << arr[1] << endl;
  
  char chr_arr[]{'a','b','c'};
  cout << (void*)(&chr_arr[0]) << endl;
  cout << (void*)(&chr_arr[0] + 1)<< endl;
  
  sampleFunction(arr);
}

int sampleFunction(int* array) {
    cout << (int*)(array[1]);
}