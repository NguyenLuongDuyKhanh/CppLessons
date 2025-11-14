#include <stdlib.h>
#include <stdio.h>
 
void f1(void)
{
    puts("f1");
}
 
void f2(void)
{
    puts("f2");
}
 
int main(void)
{
    if ( ! atexit(f1) && ! atexit(f2) && ! atexit(f2) ) {
        puts("Register success");
        // return EXIT_SUCCESS ;
    } else{ 
        // atexit registration failed
        puts("Register failed");
        return EXIT_FAILURE ;
    }

    printf("Doing somethings...\n");
    exit(EXIT_SUCCESS);
}   // <- if registration was successful calls f2, f2, f1
