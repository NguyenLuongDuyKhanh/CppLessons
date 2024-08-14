## Overal 
Header guard is recommended, not pragma once (pragma once is not a standard of C++ hence not many compilers support)


## Ex2
The below is shown be cause #include "pentagon.h" is in both pentagon.cpp as well as mathematics.h
"""
    pi@raspberrypi:~/workspace/CppLessons/Session2_BasicLanguageFacilities/Lesson1/20_headerguard/Ex2 $ g++ -o ~/bin/main pentagon.cpp 
    In file included from pentagon.cpp:7:
    pentagon.h:4:5: error: redefinition of ‘int getting_pentagon_side()’
        4 | int getting_pentagon_side()
          |     ^~~~~~~~~~~~~~~~~~~~~
    In file included from mathematics.h:3,
                     from pentagon.cpp:6:
    pentagon.h:4:5: note: ‘int getting_pentagon_side()’ previously defined here
        4 | int getting_pentagon_side()
          |     ^~~~~~~~~~~~~~~~~~~~~
"""

## Ex3
#define PENTAGON_H as header guard to over come this issue

## References
https://www.geeksforgeeks.org/cpp-preprocessor-directives-set-2/