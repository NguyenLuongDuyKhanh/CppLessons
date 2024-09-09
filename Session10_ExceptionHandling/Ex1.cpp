#include <iostream>
#include <limits>
using namespace std;

int ProcessRecords(int count) {
    int *pArray = (int*)malloc(count *sizeof(int));
    //int a = 1/0;
    if (pArray == nullptr) {
        throw std::runtime_error("Failed to allocate memory");
    }
    for (int i=0; i<count; i++) {
        pArray[i] = i;
    }
    free(pArray);
    return 0;
}

int main() {
    try {
        ProcessRecords(std::numeric_limits<int>::max());
    } catch (runtime_error &ex) {
        cout << ex.what() << endl;
    }
    return 0;
}
