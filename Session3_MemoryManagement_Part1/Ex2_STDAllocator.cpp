#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Sample {
    public:
        Sample() {
            cout << "Constructor is call" << endl;
        }
};

int main() {
    /* Due to RAII, this line call the construtor 10 times */
    Sample *var2 = new Sample[10];

    /*  This vector has a build in allocator hence it will not call constructor of members.
        "allocator is the memory allocator for the STL containers" -> every STL container has this behaviour.
    */
    vector<Sample> var1;
    var1.reserve(10);

    // allocator for integer values
    allocator<int> myAllocator;

    // allocate space for five ints
    int* arr = myAllocator.allocate(5);

    // construct arr[0] and arr[3]
    // myAllocator.construct(arr, 100); // no longer allowed in C++20
    arr[0] = 100; // do this instead
    arr[3] = 10;

    cout << arr[3] << endl;
    cout << arr[0] << endl;

    // deallocate space for five ints
    myAllocator.deallocate(arr, 5);
    return 0;
}