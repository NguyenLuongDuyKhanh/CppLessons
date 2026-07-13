at_quick_exit in C++
1
2
3
The at_quick_exit function, introduced in C11 and C++11, allows you to register cleanup functions that will be executed when quick_exit is called. Unlike atexit, which is used for normal program termination, at_quick_exit is specifically designed for quick program termination scenarios.

Example Usage

#include <cstdlib>
#include <iostream>

void cleanup1() {
std::cout << "Cleanup Function 1 executed.\n";
}

void cleanup2() {
std::cout << "Cleanup Function 2 executed.\n";
}

int main() {
// Register cleanup functions
at_quick_exit(cleanup1);
at_quick_exit(cleanup2);

std::cout << "Main function running.\n";

// Trigger quick exit
quick_exit(EXIT_SUCCESS);

// This line will never be executed
return 0;
}
Output:

Main function running
Cleanup Function 2 executed
Cleanup Function 1 executed
Key Points

Execution Order: Functions registered with at_quick_exit are executed in reverse order of their registration.

Separation from atexit: Functions registered with at_quick_exit are not called during normal termination (exit). Similarly, atexit functions are not called during quick_exit.

Limitations: A minimum of 32 functions can be registered, but the exact limit depends on the implementation.

Exception Handling: If a registered function throws an exception during execution, the program will terminate by calling std::terminate.

Use Cases

Emergency Cleanup: Useful for releasing critical resources (e.g., closing file descriptors) when the program must terminate quickly due to severe errors.

Multithreaded Programs: Allows safe and efficient cleanup in scenarios where waiting for all threads to finish is impractical.

Note: Avoid using operations that may fail (e.g., dynamic memory allocation) in the registered functions, as they are meant for quick and reliable cleanup.

Learn more:
attribution link icon
1 -
en.cppreference.com
attribution link icon
2 -
blog.csdn.net
attribution link icon
3 -
cplusplus.com

https://cplusplus.com/reference/cstdlib/at_quick_exit/