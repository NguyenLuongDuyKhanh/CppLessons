#include <iostream>
using namespace std;

void NewArrays() {
    // int *p = new int; // This might work but very dangerous, see the Study.
    int *p = new int[5];

    for (int i=0; i<5; ++i) {
        p[i] = i;
    }

    for (int x=0; x<5; ++x) {
        cout << p[x] << " ";
    }
    // delete p; // this syntax delete the first element of the array while we need to delete the whole array.
    delete []p; // Correct
}

int main() {
    NewArrays();

    return 0;
}