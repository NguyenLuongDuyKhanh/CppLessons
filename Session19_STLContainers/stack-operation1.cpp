#include <iostream>
#include <stack>
using namespace std;

void createStack(stack <int>mystack)
{
    stack<int>ss = mystack;
    while (!ss.empty()){
        cout<< '\t' <<ss.top();
        ss.pop();
    }
    cout<< '\n';
}

int main() {
    stack<int>ss;
    ss.push(32);
    ss.push(21);
    ss.push(39);
    ss.push(89);
    ss.push(25);
    cout<< "The stack ss is: ";
    createStack(ss);
    cout<< "\n ss.size() : "<<"Size of the stack is:" <<ss.size();
    cout<< "\n ss.top() : " <<"Top element in the stack is:"<<ss.top();
    cout<< "\n ss.pop() : ";
    ss.pop();
    createStack(ss);
    return 0;
}