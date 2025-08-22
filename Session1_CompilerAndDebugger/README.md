

Using && (double ampersand) to run commands simultaneously
In case if you want that the second job/command needs to wait for the first job/command to finish, use the && between the commands. So in that way if any error occurs while the sentence is being executed it will stop.

```
    command1 && command2
    command1; command2
```

The ; token just separates commands, so it will run the second command regardless of whether or not the first one succeeds.

# Compiler
    gcc - GNU Compiler Collections - use to compile C program
    g++ - Use to compile C++ program, but also C program
    cc - is an environment variable referring to the system's C compiler. On linux platforms, CC almost always points to /usr/bin/gcc.

        pi@raspberrypi:~/workspace $ type -a gcc
        gcc is /usr/bin/gcc
        gcc is /bin/gcc
        pi@raspberrypi:~/workspace $ type -a g++
        g++ is /usr/bin/g++
        g++ is /bin/g++

        pi@raspberrypi:~/workspace $ which cc
        /usr/bin/cc
        pi@raspberrypi:~/workspace $ type -a cc
        cc is /usr/bin/cc
        cc is /bin/cc
        pi@raspberrypi:~/workspace $ ls -lha /usr/bin/cc
        lrwxrwxrwx 1 root root 20 May  3  2023 /usr/bin/cc -> /etc/alternatives/cc
        pi@raspberrypi:~/workspace $ ls -lha 
        pi@raspberrypi:~/workspace $ ls -lha /etc/alternatives/cc
        lrwxrwxrwx 1 root root 12 May  3  2023 /etc/alternatives/cc -> /usr/bin/gcc
        
    Explanation:
        /bin directory contains all programs that are used by system admin and all others users. /bin directory we can access whenever we want
        /usr/bin is accessible only for users that are locally logged.
# Debugger

# Build multiple files

## Using g++ without link
If you have your two source files, you can compile them into object files without linking, as so:

gcc main.c -o main.o -c
gcc module.c -o module.o -c
where the -c flag tells the compiler to stop after the compilation phase, without linking. Then, you can link your two object files as so:

gcc -o myprog main.o module.o
This is all perfectly normal behavior, you'll usually get your makefile to compile things separately and link them at the end, so you don't have to recompile every single source file every time you change one of them.

Talking about main.o "calling functions in" module.o is perfectly fine, but an .o file is not a source file, it's a compiled object file. If "put my source code in files with extension .o" actually meant "compile my source code into files with extension .o" then the situation would make a whole lot more sense.

## Using make file
Create a make file and 
pi@raspberrypi:~/CppLessons/Session1_Basic/Lesson1/3_Function $ make main
g++ -Wall -g -c sample.cc
g++ -Wall -g -o main main.o sample.o

# In all the examples so far, we’ve called gcc on a single source file and
it has created a single executable program. This hides the fact that gcc
actually does two things: first, it compiles your C source file into what’s
called an object file, and then it links the object file with all the library
functions to create the executable. This second step is performed by a
program called a linker; gcc actually does both jobs.
If you create a program with multiple source files, you just need to
include the names of all the source files in the call to gcc. It will then
create one object file for each source file, and then link all your object
files together to create the executable.
There’s one snag, though. If you’ve separated your code into separate
files (usually referred to as modules), you’ll have some files which
make calls to functions in other files in order to work. These files don’t
find out about each other until the linker operates on them; the files
are compiled individually, and the compiler will complain if you use
functions in a file it doesn’t know about.

# Linker
## Dinamic link and static link
https://mayowaobisesan.medium.com/c-linker-9b005f0a86f2
Các kiểu link
Dynamic
Static
Classpath
Notlinked

# TODO
write a library without main function
Check lại xem header lib như boost có lợi gì
Debug khi không có file source, file source ở chỗ khác hoặc debg trong lib thì làm sao 