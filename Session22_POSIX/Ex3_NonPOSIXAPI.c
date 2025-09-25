#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/epoll.h>   // Linux-specific
#include <string.h>

int main() {
    int epfd = epoll_create1(0);   // Linux-only system call
    if (epfd == -1) {
        perror("epoll_create1");
        return 1;
    }

    struct epoll_event ev;
    memset(&ev, 0, sizeof(ev));
    ev.events = EPOLLIN;
    ev.data.fd = STDIN_FILENO;

    if (epoll_ctl(epfd, EPOLL_CTL_ADD, STDIN_FILENO, &ev) == -1) {
        perror("epoll_ctl");
        close(epfd);
        return 1;
    }

    printf("Type something and press Enter...\n");

    struct epoll_event events[1];
    int n = epoll_wait(epfd, events, 1, -1); // wait indefinitely
    if (n > 0) {
        printf("Input is ready on stdin!\n");
    }

    close(epfd);
    return 0;
}