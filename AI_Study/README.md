## Study1
How system calls look like after building C++ program. Give example of using pthread and ASM code to create pthread. Also example of Raw thread creation via inline asm.

## Study2
Give me an example showing std::atomic to protect a shared resource in C++, also explain it in ASM. Compare pros and cons to other method.

## Study3
What is debug symbol and how to deliver it separately from striped binary file.

## Study4
List the usage of 'const' keyword in C++, compare to that of C. Best practice of using const.

## Study5
What is memory ordering in C++. Explain and compare std::memory_order_relaxed, memory_order_acquire, memory_order_release, memory_order_seq_cst.

## Study 6
Teach me modern C++ memory model.

## Study 7
Show me example of struct inheritance in C++, when I'd prefer struct over class in C++?

## Study 8
What difference between i++ and ++i in C++, also show me the difference in asm, is there any difference in performance. When I would prefer one to another?

## Study 9
Compare data structures such as array, dynamic array, linked list, array of references,... in term of storing a number of large objects. 

## Study 10
What is 'extern "C"' in C++ code? Show me example.

## Study 11
What is 'printf()' function in C, tell me the compatibility of that in C/C++, Linux and bare metel platforms.


## Study 12
What is the use of 'static' in C/C++. Why we would prefer using 'static' to define functions. Tell me the pros and cons and best practice of using that.

# Study 13
In 'switch/case' flow in C/C++, which is better between 'break' and 'goto done'. Tell me the best practice of when to use which?

# Study 14
Compare these piece of code 
    void funcA(const int var) 
    void funcA(int var)
    void funcA(cont int& var) 
Tell me the best practice of using those

## Study 15
What is 'abort()' function in C/C++, any alternative to abort to terminate C++.

## Study 16
What 'const' means in the below line of code int getMemberA() const (return _memberA;)

## Study 17
How to mark mutable member in C++. The use of 'mutable' keyword.

## Study 18
What is 'declaration' and 'definition', when an object actually live in the memory? When he constructor of that object is called?

## Study 19
Teach me the constructors/destructors call order in C++ and Python, is it needed to call parent's constructor explicitly to construct parent's attribute? Give me some example to demonstrate.

## Study 20
What are difference between malloc/calloc/realloc in C. Show me examples of using them. Show me the internal memory layout (heap & free list) to see how they actually works under the hood? When should we use realloc rather than calloc or malloc.

## Study 21
Explain "memory leak" and how to detect them. How does the OS reclaim all memory when a process terminates? Teach me the termination of a process in linux.
Show me A diagram of memory layout before/after process termination and How kernel functions like mmput() and release_task() work internally

# Study 22
Show me a diagram of the actual kernel structs, How the kernel schedules the process’s final removal and Annotated kernel source code (from kernel/exit.c and mm/mmap.c)

# Study 23
What happens in memory when you run a C++ program (stack, heap, data, code segment). Show me step-by-step example of a short C++ program and showing exactly where each variable lands in memory?

# Study 24
What happens if the program consume more memory than a regular program/process. Explain the memory growth in Linux. Show examples.

## Study 25
What is hash map look up in data structures. Show me example in C++ Python and Go.

## Study 26
Explain how "new/delete" differ from "malloc/free".

## Study 27
Explain shallow copy and deep copy in C++. Give me examples, advice and best practice, tell me when to use what?

## Study 28
Explain overload and override in C++, give examples.

## Study 29
What is the difference between composition and aggregation. Tell me best practice of designing those two relationship.

## Study 30
In C++ programming, why should we disable copy constructor? Give me example.

## Study 31
Teach me C-style string and std::string. Show me example of using those.

## Study 32 
What is forward declaration in C++. Give me example and best practice of using it.

## Study 33
Why static_cast<T> is safer and preferred over (T) in C++

## Study 34
what advantage of using namespace. Teach me best practice to use namespace vs class in C++.

## Study 35
what difference between NUL and nullptr. Examine a NULL and nullptr in stack trace, its type and its address

## Study 36
What is the best practice to separate source files (.cpp) and header files (.h) in C++. Which part of code should live in on which files? Any problem if I write the hold implementation in header file?

## Study 37
Hhow 'flush' work in c++, what is buffer, how buffer work, how often does flush perform, how to check.

## Study 38
What is MinGW, MSVC, LLVM, GNU compiler.
 
## Study 39
Runtime polymorphism and compile time polymorphism in C/C++

## Study 40
What are __for_range, __for_begin, __for_end in a C++ for loop and how to inspect those in gdb.

## Study 41
Teach me about thread in Linux, tell me the difference from process.

## Study 42
What is thread detach?

## Study 43
What are callable in C++?

## Study 44
Teach me stack unwind in C++

## Study 45
Teach me some feature in <type_traits> C++, including is_same.

## Study 46
What is Auto_ptr in C++.

## Study 47
How preprocessor choose the compiler #ifdef <platform>.

## Study 48
Teach me about log level and syslog in Linux Cpp.

## Study 49
Teach me database optimization techniques.

## Study 50
Show me the implementation of malloc/calloc/realloc in C.
