#include <string>
#include <iostream>
int main(){

    // Using an asignment operator to init a variable is called copy initialization

    int a1;                         //Uninitialized
    a1 = 10;                        //Initialized
    int a2 = 0;                     //Initialized
    int a3(5);                      //Direct initialization

    std::string s1;                 //Default constructor of string was involked so it is automaticly initialized
    std::string s2("Somethings");   //Direct initialization

    char d1[8];                     //Uninitialize
    std::cout<<sizeof(d1)<<std::endl;          //Initialized
    char d2[8] = {"a"};             //Aggregate initialization
    std::cout<<sizeof(d2)<<std::endl;          

    int b1{};                       // Value initialization -> default is 0
    std::cout<<b1<<std::endl;
    char e1[8]{};                   // Set to default 
    char e2[8]{"Hello"};
    std::cout<<e1<<std::endl;
    std::cout<<e2<<std::endl;

    // Uniform initialization also helps to init variables on heap

    int *p1 = new int{};
    std::cout<<p1<<std::endl;
    std::cout<<*p1<<std::endl;
    int* p2 = new int{50};
    std::cout<<p2<<std::endl;
    std::cout<<*p2<<std::endl;

    // Narrowing conversion => investigate casting
    // float f{};
    // int i{f};

    // int i{};
    // float f{i};

    // int i = 5;
    // float f = i;
    int samplevar;
    std::cout<<samplevar<<std::endl;
}