#include <iostream>
#include <vector>
#include <string>
#include "helloworld.h"

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    cout << a<<endl;
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}