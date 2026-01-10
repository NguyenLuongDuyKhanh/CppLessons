#include <stdio.h>
#include <stdlib.h>

int main() {
    /* We should better convert the return value of malloc to (int*) because it originally (void*) */
    int *p = (int*)malloc(sizeof(int));
    *p = 5;
    printf("%d", *p);


    free(p);
    p=NULL;

    /*  calloc 
        use gdb to inspect the initialized memory
    */
    int *p2 = (int*)calloc(1, sizeof(int));

    /* Dynamic Array */
    int *arr1 = (int*)malloc(5*sizeof(int));
    int *arr2 = (int*)calloc(5, sizeof(int));

    printf("%d \n", arr1[2]);
    printf("%d \n", arr2[2]);

    return 0;
}