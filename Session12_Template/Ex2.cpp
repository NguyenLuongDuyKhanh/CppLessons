#include <iostream>
#include <typeinfo>
using namespace std;
 
typedef int mytype;
// One function works for all data types.  This would work
// even for user defined types if operator '>' is overloaded
template <typename T> T 
myMax(T x, T y)
{
    return (x > y) ? x : y;
}
 
template <typename T, class X> // class or typename doesn't matter here
void Swap(T &a, X &b) {
    T temp = a;
    a = (T)b;
    b = (X)temp;
}

template <class temp>
temp sum(temp x1, temp x2)
{
	return x1 + x2;
}

template <class T>
class mypair {
    T values [2];
  public:
    mypair (T first, T second)
    {
      values[0]=first; values[1]=second;
    }
};

int main()
{
    cout << myMax<int>(3, 7) << endl;           // Call myMax for int
    cout << myMax<double>(3.0, 7.0) << endl;    // call myMax for double
    cout << myMax<char>('g', 'e') << endl;      // call myMax for char
    mytype a = 5;
    mytype b = 6;
    cout << myMax(a, b)<< endl;                 // call myMax for mytype
    int numberA = 1;;
    float numberB = 2.5;
    Swap(numberA,numberB);
    cout << "numberA= "<< numberA<< endl;
    cout << "numberB= "<< numberB<< endl;

    mypair<int> myobject (115, 36);
    mypair<double> myfloats (3.0, 2.18);

    auto result = sum(1.1,2.5);
    cout << typeid(result).name()<<endl;        // d
    return 0;
}