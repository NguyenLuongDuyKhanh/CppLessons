#include <string>
#include <iostream>
int main(){
    int a1;                         //Uninitialized
    a1 = 10;                        //Initialized
    int a2 = 0;                     //Initialized
    int a3(5);                      //Direct initialization

    std::string s1;                 //Default constructor of string was involked so it is automaticly initialized
    std::string s2("Somethings");   //Direct initialization

    char d1[8];                     //Uninitialize
    std::cout<<sizeof(d1);          //Initialized
    char d2[8] = {"a"};
    std::cout<<sizeof(d2);          //Aggregate initialization
}