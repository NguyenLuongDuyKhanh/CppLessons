#include <iostream>

int main() {
    using namespace std;
    int something;
    cin >> something;
    cout << "Receive: " << something << endl;

    // A buffer to read 8 characters
    char buff[8];

    // This way will stop if there a spaces in the input text
    cin >> buff;

    // This way will stop when encounter the delimiter ('\n' in this case)
    cin.getline(buff, 8, '\n');

    return 0;
}   