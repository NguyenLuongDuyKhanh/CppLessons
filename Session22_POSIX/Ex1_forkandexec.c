#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // POSIX: fork, exec, getpid
#include <sys/wait.h> // POSIX: wait

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child (PID=%d) running ls\n", getpid());
        execl("/bin/ls", "ls", "-l", NULL);
        perror("execl failed"); // only if exec fails
        exit(1);
    } else {
        // Parent process
        wait(NULL); // wait for child to finish
        printf("Parent (PID=%d) done\n", getpid());
    }

    return 0;
}