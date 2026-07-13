A **POSIX timer** is a kernel-managed timer defined by the POSIX standard (`timer_create()`, `timer_settime()`, etc.). It allows your program to schedule an event to occur at a specific time or periodically, without needing to constantly check the clock yourself.

POSIX timers are different from functions like `sleep()` or `usleep()` because they can:

* Expire once or periodically.
* Notify your program automatically when they expire.
* Use different clocks (`CLOCK_REALTIME`, `CLOCK_MONOTONIC`, etc.).
* Achieve much better timing precision.

---

# POSIX Timer API

The main APIs are:

```c
#include <time.h>

int timer_create(clockid_t clockid,
                 struct sigevent *evp,
                 timer_t *timerid);

int timer_settime(timer_t timerid,
                  int flags,
                  const struct itimerspec *new_value,
                  struct itimerspec *old_value);

int timer_gettime(timer_t timerid,
                  struct itimerspec *curr_value);

int timer_delete(timer_t timerid);
```

---

# How it works

```
timer_create()
      |
      V
Kernel creates timer
      |
timer_settime()
      |
      V
Timer starts counting
      |
      V
Timer expires
      |
      +-------------------+
      |                   |
 Send signal          Start thread
      |                   |
      V                   V
 Your handler       Callback function
```

---

# Notification methods

When the timer expires, Linux can notify you in several ways.

## 1. Signal (most common)

The kernel sends a signal like `SIGALRM`.

```
Timer expired
      |
      V
Kernel
      |
      V
SIGALRM
      |
      V
signal handler
```

---

## 2. Spawn a thread

The kernel creates a thread and calls your callback.

```
Timer expired
      |
      V
Kernel
      |
      V
New thread
      |
      V
callback()
```

---

## 3. No notification

You can periodically poll the timer yourself.

---

# Example 1: Periodic timer every second

```c
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

void handler(int sig)
{
    printf("Timer expired!\n");
}

int main()
{
    timer_t timerid;

    struct sigevent sev = {
        .sigev_notify = SIGEV_SIGNAL,
        .sigev_signo = SIGUSR1
    };

    signal(SIGUSR1, handler);

    timer_create(CLOCK_MONOTONIC, &sev, &timerid);

    struct itimerspec its = {
        .it_value.tv_sec = 1,      // first expiration
        .it_value.tv_nsec = 0,
        .it_interval.tv_sec = 1,   // repeat every second
        .it_interval.tv_nsec = 0
    };

    timer_settime(timerid, 0, &its, NULL);

    while (1)
        pause();
}
```

Output

```
Timer expired!
Timer expired!
Timer expired!
Timer expired!
```

---

# Example 2: One-shot timer

Simply set the interval to zero.

```c
struct itimerspec its = {
    .it_value.tv_sec = 5,
    .it_value.tv_nsec = 0,
    .it_interval.tv_sec = 0,
    .it_interval.tv_nsec = 0
};
```

After five seconds:

```
Timer expired!
```

The timer automatically stops.

---

# Example 3: Callback thread

Instead of signals:

```c
void callback(union sigval sv)
{
    printf("Callback thread!\n");
}

struct sigevent sev = {
    .sigev_notify = SIGEV_THREAD,
    .sigev_notify_function = callback
};
```

When the timer expires:

```
Main thread
      |
      |
      +------------+
                   |
              callback thread
```

This is often easier than writing signal handlers because you avoid the restrictions on what functions are safe to call from a signal handler.

---

# Which clock should you use?

There are several clocks available:

| Clock                      | Meaning                             | Affected by changing system time? |
| -------------------------- | ----------------------------------- | --------------------------------- |
| `CLOCK_REALTIME`           | Wall clock                          | Yes                               |
| `CLOCK_MONOTONIC`          | Time since boot                     | No                                |
| `CLOCK_BOOTTIME`           | Time since boot including suspend   | No                                |
| `CLOCK_PROCESS_CPUTIME_ID` | CPU time used by the process        | No                                |
| `CLOCK_THREAD_CPUTIME_ID`  | CPU time used by the current thread | No                                |

For periodic work (e.g., sampling sensors, refreshing a display, scheduling tasks), `CLOCK_MONOTONIC` is usually the best choice because it is not affected if the system clock is adjusted.

---

# POSIX timers vs `sleep()`

| Feature             | `sleep()`                      | POSIX timer |
| ------------------- | ------------------------------ | ----------- |
| One-shot            | ✓                              | ✓           |
| Periodic            | ✗                              | ✓           |
| Multiple timers     | Difficult                      | ✓           |
| High precision      | Limited                        | ✓           |
| Signal notification | ✗                              | ✓           |
| Thread callback     | ✗                              | ✓           |
| Kernel-managed      | No (blocks the calling thread) | Yes         |

---

# Typical use cases

POSIX timers are widely used in systems programming:

* Triggering a task every 10 ms or 1 s.
* Implementing protocol timeouts (e.g., retransmission timers).
* Watchdog or heartbeat mechanisms.
* Scheduling periodic data collection from sensors.
* Refreshing UI or display at regular intervals.
* High-resolution timing in servers or embedded Linux applications.

> **Note:** On Linux, POSIX timers are different from the `timerfd_*()` API. POSIX timers deliver signals or callbacks, while `timerfd` exposes a timer as a file descriptor that you can monitor with `poll()`, `select()`, or `epoll()`. For event-driven servers, `timerfd` often integrates more naturally into the main event loop.
