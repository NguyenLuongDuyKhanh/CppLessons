#include <sys/inotify.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = inotify_init();
    if (fd < 0) {
        perror("inotify_init");
        return 1;
    }

    int wd = inotify_add_watch(fd, "./mydir", IN_CREATE | IN_DELETE | IN_MODIFY);
    if (wd < 0) {
        perror("inotify_add_watch");
        return 1;
    }

    char buf[4096] __attribute__ ((aligned(__alignof__(struct inotify_event))));
    while (1) {
        int len = read(fd, buf, sizeof(buf));
        if (len < 0) {
            perror("read");
            break;
        }
        for (char *ptr = buf; ptr < buf + len;
             ptr += sizeof(struct inotify_event) + ((struct inotify_event *)ptr)->len) {
            struct inotify_event *event = (struct inotify_event *)ptr;
            if (event->mask & IN_CREATE)
                printf("Created: %s\n", event->name);
            if (event->mask & IN_DELETE)
                printf("Deleted: %s\n", event->name);
            if (event->mask & IN_MODIFY)
                printf("Modified: %s\n", event->name);
        }
    }

    close(fd);
    return 0;
}
