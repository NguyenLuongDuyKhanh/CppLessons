#include <stdio.h>

int main() {
    char *buffer = NULL;
    // Attempt to write to a NULL pointer
    int a = 112233;
    snprintf(buffer, 100, "This will cause a segmentation fault");
    return 0;
}
