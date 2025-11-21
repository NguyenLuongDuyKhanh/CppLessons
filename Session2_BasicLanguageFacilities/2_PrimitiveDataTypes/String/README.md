## c_str()
In C++, the std::string class provides the c_str() method to obtain a C-style string (a null-terminated const char*) representation of the string's content. This is particularly useful when interacting with C libraries or functions that expect a const char*.

## std::to_string
The std::to_string function in C++ is a utility provided in the <string> header that allows for the conversion of numerical values into their string representations. This function is part of the C++ Standard Library and is available since C++11.
std::to_string takes a numerical value as an argument and returns a std::string object containing the character representation of that value. It supports various numerical data types, including:
int, long, long long (signed integers)
unsigned, unsigned long, unsigned long long (unsigned integers)
float, double, long double (floating-point numbers)