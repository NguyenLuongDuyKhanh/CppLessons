#include <iostream>

int sampleFunction(int);

int main(){
    sampleFunction(10);
    /*
        Error without std:: 
        usinginLocalScope.cpp:7:5: error: ‘cout’ was not declared in this scope; did you mean ‘std::cout’?
    */
    cout << "Inside main";
    return 0;
}

int sampleFunction(int a){
    using namespace std;
    cout<<a;
    return 0;
}