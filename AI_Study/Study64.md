In Unix/Linux, **everything is a file descriptor (fd)**. A file descriptor is just a small integer that the kernel uses to identify an open resource.

Common file descriptors:

| FD | Meaning                              |
| -- | ------------------------------------ |
| 0  | stdin                                |
| 1  | stdout                               |
| 2  | stderr                               |
| 3+ | Files, sockets, pipes, devices, etc. |

For example:

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_RDONLY);

    printf("fd = %d\n", fd);

    char buf[100];
    ssize_t n = read(fd, buf, sizeof(buf));

    close(fd);
}
```

Suppose `open()` returns:

```
fd = 3
```

Your process now has something like

```
FD Table
+----+------------------+
| 0  | stdin            |
| 1  | stdout           |
| 2  | stderr           |
| 3  | test.txt         |
+----+------------------+
```

---

# What is `poll()`?

`poll()` lets a program **wait for events on multiple file descriptors simultaneously**.

Instead of asking repeatedly

> "Has socket A received data?"
>
> "Has socket B received data?"
>
> "Has pipe C received data?"

you ask the kernel

> "Wake me up when any of these become ready."

This avoids wasting CPU in busy loops.

---

## Prototype

```c
#include <poll.h>

int poll(struct pollfd *fds,
         nfds_t nfds,
         int timeout);
```

Arguments:

* `fds` — array of file descriptors
* `nfds` — number of entries
* `timeout`

  * `-1` : wait forever
  * `0` : return immediately
  * `1000` : wait 1 second

Return value:

```
>0   some fds are ready
 0   timeout
-1   error
```

---

# struct pollfd

```c
struct pollfd {
    int   fd;
    short events;
    short revents;
};
```

Example:

```c
struct pollfd pfd;

pfd.fd = sockfd;
pfd.events = POLLIN;
```

Meaning:

> "I'm interested when this socket becomes readable."

After `poll()` returns:

```c
if (pfd.revents & POLLIN) {
    // data is available
}
```

---

# Example 1: Wait for keyboard input

```c
#include <stdio.h>
#include <unistd.h>
#include <poll.h>

int main() {
    struct pollfd pfd;

    pfd.fd = STDIN_FILENO;
    pfd.events = POLLIN;

    printf("Type something within 5 seconds...\n");

    int ret = poll(&pfd, 1, 5000);

    if (ret == 0) {
        printf("Timeout!\n");
    } else if (ret > 0) {
        char buf[100];
        fgets(buf, sizeof(buf), stdin);
        printf("You typed: %s", buf);
    }
}
```

Output:

```
Type something within 5 seconds...
```

If you type:

```
hello
```

Output:

```
You typed: hello
```

If you don't:

```
Timeout!
```

---

# Example 2: Wait for two pipes

```c
#include <unistd.h>
#include <poll.h>
#include <stdio.h>

int main() {
    int pipe1[2];
    int pipe2[2];

    pipe(pipe1);
    pipe(pipe2);

    struct pollfd fds[2];

    fds[0].fd = pipe1[0];
    fds[0].events = POLLIN;

    fds[1].fd = pipe2[0];
    fds[1].events = POLLIN;

    printf("Waiting...\n");

    poll(fds, 2, -1);

    if (fds[0].revents & POLLIN)
        printf("pipe1 has data\n");

    if (fds[1].revents & POLLIN)
        printf("pipe2 has data\n");
}
```

The process sleeps until **either** pipe receives data.

---

# Example 3: Multiple sockets (typical server)

A network server often monitors many client sockets:

```c
struct pollfd clients[1000];

clients[0].fd = listen_socket;
clients[0].events = POLLIN;

clients[1].fd = client1;
clients[1].events = POLLIN;

clients[2].fd = client2;
clients[2].events = POLLIN;

clients[3].fd = client3;
clients[3].events = POLLIN;
```

Main loop:

```c
while (1) {
    int n = poll(clients, num_clients, -1);

    for (int i = 0; i < num_clients; i++) {
        if (clients[i].revents & POLLIN) {
            // Handle whichever socket is ready
        }
    }
}
```

The kernel blocks the process until one or more sockets become ready, then fills in the `revents` field for those entries.

---

# Common event flags

| Flag       | Meaning                         |
| ---------- | ------------------------------- |
| `POLLIN`   | Data available to read          |
| `POLLOUT`  | Ready for writing               |
| `POLLERR`  | Error occurred                  |
| `POLLHUP`  | Other end closed the connection |
| `POLLNVAL` | Invalid file descriptor         |

Example:

```c
if (fds[i].revents & POLLHUP) {
    printf("Client disconnected\n");
}
```

---

# Why use `poll()` instead of repeatedly calling `read()`?

Without `poll()`:

```c
while (1) {
    if (read(sock1, ...))
        ...

    if (read(sock2, ...))
        ...

    if (read(sock3, ...))
        ...
}
```

This approach either:

* blocks on the first `read()` (so you never check the others), or
* requires non-blocking I/O and repeatedly checking every descriptor, which wastes CPU.

With `poll()`:

```c
while (1) {
    poll(fds, nfds, -1);

    // Only handle descriptors that are actually ready.
}
```

The process sleeps efficiently until work is available.

---

# `poll()` vs `select()` vs `epoll()`

| Feature     | `select()`                                   | `poll()`                | `epoll()` (Linux)                                          |
| ----------- | -------------------------------------------- | ----------------------- | ---------------------------------------------------------- |
| Maximum FDs | Limited (typically `FD_SETSIZE`, often 1024) | No fixed limit          | Very large                                                 |
| API         | `fd_set` bit masks                           | Array of `pollfd`       | Kernel-managed interest list                               |
| Performance | O(n)                                         | O(n)                    | O(ready fds)                                               |
| Best for    | Small programs                               | Moderate numbers of FDs | High-performance servers handling thousands of connections |

For modern Linux applications, `poll()` is a good improvement over `select()` because it removes the `FD_SETSIZE` limitation and has a simpler interface. For servers that need to scale to thousands or tens of thousands of concurrent connections, `epoll()` is the preferred mechanism because it avoids scanning every file descriptor on each wake-up.
