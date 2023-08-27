# 
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