#include <iostream>

int main(){
    union sample_union { 
        int age; 
        char grade; 
        float GPA; 
    }; 

    std::cout << sizeof(sample_union) << std::endl; //4
}