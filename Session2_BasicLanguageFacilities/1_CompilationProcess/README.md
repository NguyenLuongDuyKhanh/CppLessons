## Preprocessing
- Performed by the preprocessor
- Process all the statements begin with #
    Replace include statement by the content of the corresponding files
    Macro are expanded

## Compilation
- Performed by the compiler
- Check for syntax error;
    If there are syntax error -> stop compiling 
    If there are no syntax error -> compile into assembly code of correspoding platform

## Assembling 
- Performed by assembler
- Assembly code is converted into object code
- Object file has a .obj extension or omitted on some platforms

## Linking
- Performed by linker
- Object code link with standard libraries
- Results in an executable file