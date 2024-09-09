#include <iostream>
using namespace std;

/*Function Templates
*/
template <typename T, typename Y = int> T myMax(T x, Y y);

/* Class Templates
*/
template <typename T> class Array {
private:
    T* ptr;
    int size;
public:
    Array(T arr[], int s);
    void print();
};

template <typename T> Array<T>::Array(T arr[], int s) {
    ptr = new T[s];
    size = s;
    for (int i =0; i < size; i++) {
        ptr[i] = arr[i];
    }
}

template <typename T> void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(ptr + i);
    cout << endl;
}

int main() {

    cout << myMax<int, int>(3, 7) << endl;
    cout << myMax<double, int>(3.0, 7.0) << endl;
    cout << myMax<char, int>('g', 'e') << endl;

    int arr[5] = { 1, 2, 3, 4, 5 };
    Array<int> a(arr, 5);
    a.print();

    return 0;
}

template <typename T, typename Y> T myMax(T x, Y y) {
    return (x > y) ? x : y;
}