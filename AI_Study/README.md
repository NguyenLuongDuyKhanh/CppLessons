## [Study1](Study1.md)
How system calls look like after building C++ program. Give example of using pthread and ASM code to create pthread. Also example of Raw thread creation via inline asm.

## [Study2](Study2.md)
Give me an example showing std::atomic to protect a shared resource in C++, also explain it in ASM. Compare pros and cons to other method.

## [Study3](Study3.md)
What is debug symbol and how to deliver it separately from striped binary file.

## [Study4](Study4.md)
List the usage of 'const' keyword in C++, compare to that of C. Best practice of using const.

## [Study5](Study5.md)
What is memory ordering in C++. Explain and compare std::memory_order_relaxed, memory_order_acquire, memory_order_release, memory_order_seq_cst.

## [Study6](Study6.md)
Teach me modern C++ memory model.

## [Study7](Study7.md)
Show me example of struct inheritance in C++, when I'd prefer struct over class in C++?

## [Study8](Study8.md)
What difference between i++ and ++i in C++, also show me the difference in asm, is there any difference in performance. When I would prefer one to another?

## [Study9](Study9.md)
Compare data structures such as array, dynamic array, linked list, array of references,... in term of storing a number of large objects. 

## [Study10](Study10.md)
What is 'extern "C"' in C++ code? Show me example.

## [Study11](Study11.md)
What is 'printf()' function in C, tell me the compatibility of that in C/C++, Linux and bare metel platforms.


## [Study12](Study12.md)
What is the use of 'static' in C/C++. Why we would prefer using 'static' to define functions. Tell me the pros and cons and best practice of using that.

# [Study13](Study13.md)
In 'switch/case' flow in C/C++, which is better between 'break' and 'goto done'. Tell me the best practice of when to use which?

# [Study14](Study14.md)
Compare these piece of code 
    void funcA(const int var) 
    void funcA(int var)
    void funcA(cont int& var) 
Tell me the best practice of using those

## [Study15](Study15.md)
What is 'abort()' function in C/C++, any alternative to abort to terminate C++.

## [Study16](Study16.md)
What 'const' means in the below line of code int getMemberA() const (return _memberA;)

## [Study17](Study17.md)
How to mark mutable member in C++. The use of 'mutable' keyword.

## [Study18](Study18.md)
What is 'declaration' and 'definition', when an object actually live in the memory? When he constructor of that object is called?

## [Study19](Study19.md)
Teach me the constructors/destructors call order in C++ and Python, is it needed to call parent's constructor explicitly to construct parent's attribute? Give me some example to demonstrate.

## [Study20](Study20.md)
What are difference between malloc/calloc/realloc in C. Show me examples of using them. Show me the internal memory layout (heap & free list) to see how they actually works under the hood? When should we use realloc rather than calloc or malloc.

## [Study21](Study21.md)
Explain "memory leak" and how to detect them. How does the OS reclaim all memory when a process terminates? Teach me the termination of a process in linux.
Show me A diagram of memory layout before/after process termination and How kernel functions like mmput() and release_task() work internally

# [Study22](Study22.md)
Show me a diagram of the actual kernel structs, How the kernel schedules the process’s final removal and Annotated kernel source code (from kernel/exit.c and mm/mmap.c)

# [Study23](Study23.md)
What happens in memory when you run a C++ program (stack, heap, data, code segment). Show me step-by-step example of a short C++ program and showing exactly where each variable lands in memory?

# [Study24](Study24.md)
What happens if the program consume more memory than a regular program/process. Explain the memory growth in Linux. Show examples.

## [Study25](Study25.md)
What is hash map look up in data structures. Show me example in C++ Python and Go.

## [Study26](Study26.md)
Explain how "new/delete" differ from "malloc/free".

## [Study27](Study27.md)
Explain shallow copy and deep copy in C++. Give me examples, advice and best practice, tell me when to use what?

## [Study28](Study28.md)
Explain overload and override in C++, give examples.

## [Study29](Study29.md)
What is the difference between composition and aggregation. Tell me best practice of designing those two relationship.

## [Study30](Study30.md)
In C++ programming, why should we disable copy constructor? Give me example.

## [Study31](Study31.md)
Teach me C-style string and std::string. Show me example of using those.

## [Study32](Study32.md) 
What is forward declaration in C++. Give me example and best practice of using it.

## [Study33](Study33.md)
Why static_cast<T> is safer and preferred over (T) in C++

## [Study34](Study34.md)
what advantage of using namespace. Teach me best practice to use namespace vs class in C++.

## [Study35](Study35.md)
what difference between NUL and nullptr. Examine a NULL and nullptr in stack trace, its type and its address

## [Study36](Study36.md)
What is the best practice to separate source files (.cpp) and header files (.h) in C++. Which part of code should live in on which files? Any problem if I write the hold implementation in header file?

## [Study37](Study37.md)
Hhow 'flush' work in c++, what is buffer, how buffer work, how often does flush perform, how to check.

## [Study38](Study38.md)
What is MinGW, MSVC, LLVM, GNU compiler.
 
## [Study39](Study39.md)
Runtime polymorphism and compile time polymorphism in C/C++

## [Study40](Study40.md)
What are __for_range, __for_begin, __for_end in a C++ for loop and how to inspect those in gdb.

## [Study41](Study41.md)
Teach me about thread in Linux, tell me the difference from process.

## [Study42](Study42.md)
What is thread detach?

## [Study43](Study43.md)
What are callable in C++?

## [Study44](Study44.md)
Teach me stack unwind in C++

## [Study45](Study45.md)
Teach me some feature in <type_traits> C++, including is_same.

## [Study46](Study46.md)
What is Auto_ptr in C++.

## [Study47](Study47.md)
How preprocessor choose the compiler #ifdef <platform>.

## [Study48](Study48.md)
Teach me about log level and syslog in Linux Cpp.

## [Study49](Study49.md)
Teach me database optimization techniques.

## [Study50](Study50.md)
Show me the implementation of malloc/calloc/realloc in C.

## [Study51](Study51.md)
Teach me about inline functions:
    - Compare inline vs macros vs constexpr
    - Show real assembly differences
    - Discuss link-time optimization (LTO)
    - Analyze STL inlining strategies

## [Study52](Study52.md)
What is SRAM and compare to DRAM

## [Study53](Study53.md)
How stack grow in runtime?

## [Study54](Study54.md)
In C++, can a class function without a constructor? Explain the explicit constructor and the default constructor. 

## [Study55](Study55.md)
Why dereferencing null pointer cause segmentation fault in C/C++? Why nullptr is preferred over NULL in C++?

## [Study56](Study56.md)
How system calls look like after compiling C++ program. Give me example of using pthread and asm code to create pthread.

## [Study57](Study57.md)
What are debug symbols and how to deliver it seperately from binary?

## [Study58](Study58.md)
List the usage of const in C++ and compare to that of C.

## [Study59](Study59.md)
If I want to store a set of objects in C++, which of the following methods is most suitable:
- Array of those objects' references
- Array of those objects
- Linked list of those objects

## [Study6](Study6.md)0
I have class A() {void aFunction();};
What difference in order of constructor calls between: 
A obj;
A* obj;

Anything wrong if:
A* obj;
obj->aFunction();

## [Study6](Study6.md)1
Explain static keyword in C variables and functions. Also teach me static vs extern.

## [Study6](Study6.md)2
What is "this" in C++, when must we use that keyword?

## [Study6](Study6.md)3
What are -l, -D, -W in gcc command? Teach me other common option with gcc/g++.

## [Study6](Study6.md)4
Give me example of using fds in C. What is poll() function.

## [Study6](Study6.md)5
What is POSIX timer. Give me example.

## [Study6](Study6.md)6
What is custom deleter and allocator in C++. Show me some examples.

## [Study6](Study6.md)7
Show me some example where std::pmr is useful.

## [Study6](Study6.md)8
Why make_share and make_unique is preferred to create smart pointers and how to use those effectively in C++.

## [Study6](Study6.md)9
How to synchronize between processes? Where are flags/lock is stored? How to inspect memory space of a process.

## [Study7](Study7.md)0
Header library có ưu điểm gì, tại sao boost lại chọn dạng header library?

## [Study7](Study7.md)1
Teach me about  trivially copyable types and not  trivially copyable types in C++.
