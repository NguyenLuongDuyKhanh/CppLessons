# Program cash
Program cash is when the except could not be handle, leads to unexpected behaviour, the OS will take over that process with some signal. At that point, you don't really know what state your program is in, if it is even possible to continue execution. So catching signal and keep running is not a good approach.

There are many reasons cause a program cash.

## Divide by zero
Ex1_DevideByZero.cpp generates a "Floating point exception" which cannot be catched and lead to program cash


## Segmentation fault - Segfault
A segmentation fault is raised by the kernel when a process tries to access memory it isn't authorized to.
The high 3 bits of the address selected one of 8 sement registers, which specified where in physical memory that segment was located. Each sement had a length as well. If your program accessed an address “off the end” of a segment then you got a segmentation violation.
Segmentation violations are not the same thing as page faults. A page fault suggests a transient condition, which can be corrected by the OS. A segmentation violation usually represents a program bug.
Can only catched if run in a debuger.

### Buffer overflow
Ex2_BufferOverFlow.cpp generates a buffer overflow, leads to segfault

### Stack overflow
Ex3_StackOverflow.cpp generates stack overflow, leads to Segmentation fault (core dumped)

### Wrong address
Ex4_AccessWrongAddress.cpp access wrong address -> Segfault

### Memory leak
Ex5_MemoryLead.cpp allocate too much memory space but do not free. Complier raise a warning when building and finally leads to segfault in run time.

## Best practices to prevent
- Always initialize pointers right after declare
- Always check the success after allocating pointer
    + Smart pointer is our friend
- Always check if pointer null before dereferencing 
    + Smart pointer is our friend
- Always check the size of array/list before loop/using

### Valgrind 
Valgrind is a tool to analyze memory

Install
"""
    sudo apt install valgrind
"""

see valgrindOutput for an example output of the command
"""
    valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out
"""

# Debug
A core dump is a file that captures the memory of a running process at a specific point in time, typically when the process crashes. The @ symbol in the context of a core dump might refer to a specific memory address, a marker, or a shorthand used in debugging tools or logs. Here's a brief explanation of how it might relate:

Memory Address:
The @ symbol could indicate a memory address where an error occurred. For example, a segmentation fault might show something like:

Segmentation fault at address @0x7ffdf1234abc


This helps developers locate the problematic memory region.

Debugging Context:
In debugging tools like gdb, @ might be used to specify a location or context. For instance, it could represent a specific instruction pointer or a variable's memory location.

Symbolic Representation:
Some tools or logs use @ to denote a function or file where the crash occurred, e.g.:

Crash in function foo() @ file.c:42


If you're encountering this in a specific tool or log, it would be helpful to refer to the documentation of that tool for precise usage. Let me know if you'd like more tailored guidance!



## Recover strategies

# References
https://www.geeksforgeeks.org/reasons-c-program-crash/
https://www.tutorialspoint.com/reasons-for-a-cplusplus-program-crash

# TODO
- investigate more