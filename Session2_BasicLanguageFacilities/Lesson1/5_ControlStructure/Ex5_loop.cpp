#include <iostream>
using namespace std;

int main() {
    int outputsize{5};

    for (int i = 0; i < outputsize; i++) {
        cout << i << " " << flush;
        outputsize--; // for loop do not copy a 
    }
    return 0;
}