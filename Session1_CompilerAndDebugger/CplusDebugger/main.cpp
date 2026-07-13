#include <iostream>

using namespace std;

int main(){
    int num = 0;
    cout << "Enter a number between 1 - 10";
    cin >> num;
    int counter;
    counter ++;
    if (num > 0 && num <= 10)
    {
        cout << "Input accepted" << endl;
    }else
    {
        cout << "Error: number must be between 1 - 10" << endl;
        counter ++;
        return 1;
    }
    return 0;
}