#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr;
    int n;
    printf("Enter the number of elements that you wantL \n");
    scanf("%d", &n);
    ptr = (int*)calloc(n, sizeof(int)); // system call to allocate memory
    if (ptr==NULL) {
        printf("Memory not allocated \n");
    } else {
        printf("Memory Allocated Successfully \n");
        printf("Enter the values \n");
        for (int i=0; i<n; i++) {
            scanf("%d", &ptr[i]);
        }
        printf("The elements of the array are as: \n");
        for (int i=0; i<n; i++){
            printf("%d \n", ptr[i]);
        }
    }
    free(ptr);
    return 0;
}