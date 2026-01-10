#include <unistd.h>

int main() {
    const char *msg = "Hello, World!\n";
    write(1, msg, 14);  // 1 is the file descriptor for stdout
    return 0;
}
