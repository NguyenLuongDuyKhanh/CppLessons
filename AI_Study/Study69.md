These are excellent questions because they touch on how an operating system manages processes and virtual memory. Let's build the concepts from the ground up.

---

# 1. How do processes synchronize?

Unlike threads, **processes do not share memory by default**. Each process has its own virtual address space.

```
Process A
+----------------------+
| Code                 |
| Heap                 |
| Stack                |
+----------------------+

Process B
+----------------------+
| Code                 |
| Heap                 |
| Stack                |
+----------------------+
```

A variable like

```c
bool lock = false;
```

exists independently in each process.

Changing it in Process A has no effect on Process B.

Therefore synchronization requires **shared kernel objects** or **shared memory**.

Common methods include:

| Mechanism              | Stored where?                             |
| ---------------------- | ----------------------------------------- |
| Semaphore              | Kernel                                    |
| Mutex (process-shared) | Kernel + shared memory                    |
| Shared memory          | Physical pages mapped into both processes |
| File lock              | Kernel                                    |
| Pipe                   | Kernel                                    |
| Socket                 | Kernel                                    |
| Eventfd (Linux)        | Kernel                                    |
| Futex                  | Shared memory + kernel when contended     |

---

# 2. Where is the lock stored?

The answer depends on the synchronization primitive.

## Case 1: pthread mutex between threads

```cpp
pthread_mutex_t mutex;
```

This variable lives in your program memory:

```
Heap
+----------------+
| mutex object   |
+----------------+
```

Internally it contains fields like

```
owner
state
waiters
kind
```

When uncontended, locking may happen entirely in user space.

When another thread must sleep, the kernel becomes involved through a **futex**.

---

## Case 2: Between processes

Suppose two processes need one mutex.

```
Process A
          \
           Shared Memory
          /
Process B
```

The mutex object must reside inside shared memory.

Example

```cpp
shm_open()
mmap()

pthread_mutex_t *mutex =
    mmap(...);
```

Now both processes see exactly the same bytes.

```
Shared Memory

+----------------------+
| pthread_mutex_t      |
+----------------------+
```

Both virtual addresses may differ

```
Process A
0x7ff1a000

Process B
0x7f8bc000
```

but they map to the **same physical page**.

---

## Case 3: Semaphore

```cpp
sem_t sem;
```

Named semaphore

```
sem_open("/mysem")
```

is maintained by the kernel.

Internally the kernel stores something like

```
count = 3
waiting queue
owner
```

Your program only has a handle.

---

## Case 4: Futex

Linux mutexes are extremely interesting.

The actual lock variable is just

```cpp
int lock = 0;
```

stored in shared memory.

```
Shared page

lock = 0
```

Fast path

```
CAS(lock,0,1)
```

No kernel call.

If the CAS fails,

```
futex_wait()
```

Kernel puts thread/process to sleep.

Kernel remembers

```
Address:
0x7ffd12345000
```

and wakes sleepers later.

This is why futexes are very fast.

---

# 3. How can two processes access the same lock?

Using shared memory.

Example

```cpp
int fd = shm_open("/example", O_CREAT|O_RDWR, 0666);

ftruncate(fd, 4096);

void *ptr = mmap(NULL,
                 4096,
                 PROT_READ|PROT_WRITE,
                 MAP_SHARED,
                 fd,
                 0);
```

Both processes call the same code.

Result

```
Physical RAM

+----------------------+
| Shared page          |
+----------------------+

       ↑          ↑

Process A     Process B
```

---

# 4. How can I inspect a process's memory?

Linux exposes this nicely.

## Method 1

```
cat /proc/<pid>/maps
```

Example

```
555555554000-555555756000 r-xp program

555555956000-555555977000 rw-p heap

7ffff7dd0000-7ffff7ffc000 libc.so

7ffffffde000-7ffffffff000 stack
```

This tells you

* code
* heap
* libraries
* stack
* permissions

---

## Method 2

Inside your own process

```cpp
#include <unistd.h>

printf("%p\n", &main);
```

or

```cpp
int x;

printf("%p\n", &x);
```

You can also print

```cpp
malloc()

printf("%p", ptr);
```

to see heap addresses.

---

## Method 3

Use `pmap`

```
pmap <pid>
```

Example

```
0000555555554000   132K r-x program
0000555555776000    16K rw-
00007ffff7dc0000  1824K libc
```

---

## Method 4

Using `gdb`

```
gdb ./program
```

Inside gdb

```
info proc mappings
```

or

```
maintenance info sections
```

---

## Method 5

Read `/proc/<pid>/smaps`

This gives much more information.

```
Size:
RSS:
Private_Dirty:
Shared_Clean:
```

Very useful when investigating memory usage.

---

# 5. How do I know whether an address is valid?

Suppose you have

```cpp
void *p = (void*)0x12345678;
```

How do you know if it's valid?

The CPU consults the page tables.

If the page is mapped:

```
Page table

0x12345000
    ↓
Physical page
```

the access succeeds.

Otherwise

```
Segmentation Fault
```

The kernel raises a page fault because no valid mapping exists.

---

## User-space inspection

You can compare against `/proc/self/maps`.

Suppose the maps contain

```
7ffd00000000-7ffd00021000 rw-p
```

Any address inside

```
7ffd00001000
```

is potentially valid (subject to the region's permissions).

An address outside every mapped range is invalid.

---

# 6. Typical Linux process memory layout

```
High addresses
+----------------------+
| Kernel (not visible) |
+----------------------+
| Stack                |
+----------------------+
| mmap() regions       |
| Shared libraries     |
| Shared memory        |
+----------------------+
| Heap                 |
+----------------------+
| Data (.data/.bss)    |
+----------------------+
| Code (.text)         |
+----------------------+
Low addresses
```

Every region has permissions:

```
rwx

r--   read only

rw-   read/write

r-x   executable

---   inaccessible
```

---

# 7. A practical experiment

You can explore these concepts with a simple C program:

```c
#include <stdio.h>
#include <stdlib.h>

int global = 1;

int main() {
    int local = 2;
    int *heap = malloc(sizeof(int));

    printf("Code   : %p\n", (void *)&main);
    printf("Global : %p\n", (void *)&global);
    printf("Heap   : %p\n", (void *)heap);
    printf("Stack  : %p\n", (void *)&local);

    getchar();  // Pause so you can inspect the process
}
```

Compile and run it:

```bash
gcc -g memory.c -o memory
./memory
```

In another terminal, find its PID and inspect its mappings:

```bash
pidof memory
cat /proc/<pid>/maps
pmap <pid>
```

Compare the printed addresses with the ranges in `/proc/<pid>/maps`. You'll see the code address falls in the executable (`r-x`) region, the global variable in the data segment, the heap allocation in the heap or an `mmap` region, and the local variable near the top of the stack mapping.

Once you're comfortable with that, the next step is to write **two separate processes** that use `shm_open()` and `mmap()` to share a page, place a `pthread_mutex_t` (configured with `PTHREAD_PROCESS_SHARED`) in that page, and observe how both processes synchronise using the same shared-memory lock. That experiment ties together virtual memory, shared memory, and inter-process synchronisation.
