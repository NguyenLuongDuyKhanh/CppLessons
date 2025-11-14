#include <stdio.h>

int main() {
    int result = add(2, 3);  // call before declaration
    printf("Result: %d\n", result);
    return 0;
}

int add(int a, int b) {
    return a + b;
}
