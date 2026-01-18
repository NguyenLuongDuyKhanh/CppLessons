/*  This example try to modiy a pointer inside a function to prove that a pointer is copied when it is pass to a function.
    That copied pointer points to same memory as the pointer in the caller, it means:
        - If we change the value pointed by the pointer, it affect the memory hence affect the pointer in the caller too.
        - If we change the pointer itself (points to elsewhere), it will not affect the pointer in the caller.
*/
#include <iostream>
using namespace std;

void thisFunctionTakeAPointer(int *apointer) {
    cout << "apointer " << *apointer << endl;
    apointer = new int(15);
}

void thisFunctionTakeAPointertoPointer(int **apointer) {
    cout << "apointer " << *apointer << endl;
    int *tmp = new int(15);
    apointer = new (int*)(tmp);
}

int main() {
    int aValue = 10;
    thisFunctionTakeAPointer(&aValue);
    cout << aValue << endl;

    int* bValue = new int(20);
    thisFunctionTakeAPointer(bValue);
    cout << *bValue;

    int* cValue = new int(30);
    thisFunctionTakeAPointertoPointer(&cValue);

    return 0;
}