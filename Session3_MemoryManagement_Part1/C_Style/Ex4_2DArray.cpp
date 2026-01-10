#include <iostream>
using namespace std;

void Static2DArray(){
    // This array lives on stack
    int arr[2][3]{
        {1,2,3},
        {4,5,6}
    };
}

void Dynamic2DArray(){
    // T
    int *p1 = new int[3];
    int *p2 = new int[3];

    int **pData = new int *[2];
    pData[0] = p1;
    pData[1] = p2;

    pData[0][1] = 2;
    delete[]p1; // same as delete[]pData[0]
    delete[]p2; // same as delete[]pData[1]

    delete[]pData;
}

int main() {
    Dynamic2DArray();

    return 0;
}