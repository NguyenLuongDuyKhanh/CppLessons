#include <iostream>
using namespace std;

/* By turning function signature to 'void printFunc(int &ref)'
    We avoid accidentally change ref and also accept this function to be called with a litteral.
*/
void printFunc(int &ref) {
    cout << ref << endl;
    ref = 15;
}

int main() {
    // Declare a reference directly
    const int &ref = 5;
    cout << "There is a number " << ref << " at address " << &ref << endl;
    
    int arg = 10;
    printFunc(arg);

    // printFunc(1);
    return 0;
}