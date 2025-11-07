#include <iostream>
#include <string>

int main() {
    int num_int = 123;
    double num_double = 45.67;
    float num_float = 8.9f;

    std::string str_int = std::to_string(num_int);
    std::string str_double = std::to_string(num_double);
    std::string str_float = std::to_string(num_float);

    std::cout << "Integer as string: " << str_int << std::endl;
    std::cout << "Double as string: " << str_double << std::endl;
    std::cout << "Float as string: " << str_float << std::endl;

    return 0;
}