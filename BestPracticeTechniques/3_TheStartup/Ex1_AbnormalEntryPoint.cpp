#include<stdio.h>

void my_start() {
    // no libc, no main
    // while (1);
    printf("This is my_start");
}

int main() {
    printf("This is main function: ");

    return 0;
}