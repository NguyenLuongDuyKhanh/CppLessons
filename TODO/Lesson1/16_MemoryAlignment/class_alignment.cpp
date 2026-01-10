# include <iostream>

class MyClass1 {
  public:
    int myNum;
    char myChar;
};

// Ineffective alignment
class MyClass2 {
  public:
    char myChar1;
    int myNum;
    char myChar2;
};

// Effective alignment
class MyClass3 {
  public:
    char myChar1;
    char myChar2;
    int myNum;

    MyClass3() {
      std::cout << "Constructor was called";
    }
};

int main(){
    MyClass1 sample1;
    std::cout << sizeof(sample1) << std::endl; //8

    MyClass2 sample2;
    std::cout << sizeof(sample2) << std::endl; //12

    MyClass3 sample3;
    std::cout << sizeof(sample3) << std::endl; //8

}