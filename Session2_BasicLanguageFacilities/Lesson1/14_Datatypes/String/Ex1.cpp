#include <iostream>
#include <string>

int main() {
    std::string myString = "Hello, C-style string!";

    // Get the C-style string representation
    const char* c_style_string = myString.c_str();

    // Now you can use c_style_string with C functions
    std::cout << "C-style string: " << c_style_string << std::endl;

    return 0;
}
