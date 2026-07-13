#include <iostream>
using namespace std;

/* By turning this signature to 'int printFunc(const int* arg)' we can avoid accidentally modify arg.
*/
int printFunc(int* arg){
    cout << *arg << endl;
    *arg = 1;

    return 0;
}

int main() {
    const int chunk_size = 512;
    int another_entry = 513;

    /*  pointer to a const
        chunk_size is a const, we cannot use a pointer to point to that, we need to use a 'pointer to a const' to point to that.
        The in this case, the 'ptr' itself is not a const (also mean it can point to another entry but it cannot change the value it points to.
        Often used in function argument where we want to enhance performance but not change the origin value.
    */

    // int* ptr = &chunk_size;      // A value of "const int* cannot be used to initialize an entry of "int*"
    const int* ptr = &chunk_size;   // Valid statement
    // *ptr=513;                    // Invalid
    ptr = &another_entry;           // Valid
    // *ptr = 123;                  // Invalid

    printFunc(&another_entry);
    cout << *ptr << endl;

    return 0;
}