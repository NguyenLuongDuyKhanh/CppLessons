#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr;
    int n;
    printf("Enter the number of elements that you want\n");
    scanf("%d", &n);
    ptr = (int*)calloc(n, sizeof(int));
    printf("The elements of the array areL\n");
    for (int i=0; i<n; i++) {
        printf("%d \n", ptr[i]);
    }
    free(ptr);
    printf("Dynamic memory successfully freed");
    return 0;
}