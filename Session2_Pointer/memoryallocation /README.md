## Memory layout
    | Command-line Arguments
    | Stack
    | ...
    | Heap
    | Uninitialized data segment (bss - block started by symbol)
    | Initialized data segment
    | Text

Text segment:
    Contains executable instructions. Code in text

Initialized Data Segment:
    Contains the global variables and static variables that are initialized by the programmer.
    This segment can be further classified into the initialized read-only area and the initialized read-write area.
    For instance, these global variable would be stored in the initialized read-write area
        char s[] = “hello world”
        int debug=1

        const char* string = “hello world”
        
Dynamic 

    """
        int global = 10; /* initialized global variable stored in DS*/

        int main(void)
        {
            static int i = 100; /* Initialized static variable stored in DS*/

            return 0;
        }

        //  text    data     bss     dec     hex filename
        //  1073     284       4    1361     551 main
    """

    An int pointer (without allocating) adds 4 bytes to bss section
    """
        int global = 10; /* initialized global variable stored in DS*/
        int *ptr_i;

        int main(void)
        {
            static int i = 100; /* Initialized static variable stored in DS*/

            return 0;
        }

        //  text    data     bss     dec     hex filename
        //  1073     284       8    1365     555 main
    """

    An int pointer in global scope with an int size memory allocating adds 4 bytes to bss and 16 bytes to data section
    """
        int global = 10; /* initialized global variable stored in DS*/
        int *ptr_i = new int;

        int main(void)
        {
            static int i = 100; /* Initialized static variable stored in DS*/

            return 0;
        }

        //  text    data     bss     dec     hex filename
        //  1394     300       8    1702     6a6 main
    """

    - An int pointer in local scope without allocating does not add any extension
    """
        
        int global = 10; /* initialized global variable stored in DS*/


        int main(void)
        {
            static int i = 100; /* Initialized static variable stored in DS*/
            int *ptr_i;
            return 0;
        }

        // text    data     bss     dec     hex filename
        // 1073     284       4    1361     551 main
    """

    - An int pointer in local scope with an int size memory allocating add 16 bytes to data
    """
        int global = 10; /* initialized global variable stored in DS*/


        int main(void)
        {
            static int i = 100; /* Initialized static variable stored in DS*/
            int *ptr_i = new int{5};
            return 0;
        }

        // text    data     bss     dec     hex filename
        // 1421     304       4    1729     6c1 main
    """
# References
https://www.geeksforgeeks.org/memory-layout-of-c-program/
