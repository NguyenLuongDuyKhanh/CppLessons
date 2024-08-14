Order of variable in

Memory access granualarity
    is the unit a process read/write access per each
    On raspberry, it is 2 bytes

In classes, structs: 
    In order of declaration
    Alignment by 1 word
    Class's methods are not count
    The size is allocated regardless whether 
    Contructors call

In union:
    Only one address for all elements
    The size of the union is equal to the size of the largest data type.

In main function:
    allocate from smallest to biggest


# References
https://www.iostream.co/article/ly-do-ton-tai-data-alignment-struct-alignment-memory-alignment-P1Ur7H
https://stackoverflow.com/questions/381244/purpose-of-memory-alignment
https://en.wikipedia.org/wiki/Data_structure_alignment