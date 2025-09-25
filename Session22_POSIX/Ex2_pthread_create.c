#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> // POSIX threads

void* worker(void* arg) {
    printf("Hello from thread! Arg=%s\n", (char*)arg);
    return NULL;
}

int main() {
    pthread_t tid;
    const char* message = "POSIX portability";

    if (pthread_create(&tid, NULL, worker, (void*)message) != 0) {
        perror("pthread_create failed");
        return 1;
    }

    pthread_join(tid, NULL); // wait for thread to finish
    printf("Main thread done\n");

    return 0;
}