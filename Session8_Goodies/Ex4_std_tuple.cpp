#include <iostream>
#include <tuple>

int main() {
    std::tuple<char, int, float> geek;
    geek = std::make_tuple('a', 10, 15.5);

    // Printing initial tuple values using get()
    cout << "The initial values of tuple are : ";
    cout << get<0>(geek) << " " << get<1>(geek);
    cout << " " << get<2>(geek) << endl;
 
    // Use of get() to change values of tuple
    get<0>(geek) = 'b';
    get<2>(geek) =  20.5;
 
     // Printing modified tuple values
    cout << "The modified values of tuple are : ";
    cout << get<0>(geek) << " " << get<1>(geek);
    cout << " " << get<2>(geek) << endl;

    return 0;
}