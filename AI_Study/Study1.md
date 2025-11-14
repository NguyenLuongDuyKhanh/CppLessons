Great question — you’re diving deep into how **threads and system calls** work at the low level in Linux. Let’s go step by step from high-level C++ to raw assembly, so you can see **how system calls appear** after compilation and how to **create threads both via pthread and raw syscall/asm**.

---

## 🧩 1. What System Calls Look Like After Building

When you compile and run a C/C++ program on Linux, functions like `pthread_create()` or `open()`, `read()`, etc., are **not direct CPU instructions** — they’re **library wrappers** around **system calls** made to the Linux kernel.

Example:

```cpp
pthread_create(...);
```

At runtime, this eventually calls the `clone` system call (on Linux) via the **`syscall` instruction** (x86-64) or **`int 0x80`** (older x86).

Disassembly of a typical system call sequence:

```asm
mov eax, 56          ; syscall number for clone
mov rdi, flags       ; 1st argument
mov rsi, child_stack ; 2nd argument
mov rdx, ptid        ; 3rd argument
mov r10, ctid        ; 4th argument
mov r8,  tls         ; 5th argument
syscall              ; enter kernel mode
```

So in short:

* C++ calls → glibc wrapper → syscall instruction → kernel.

---

## 🧵 2. Example: Normal pthread usage in C++

```cpp
#include <pthread.h>
#include <iostream>
using namespace std;

void* worker(void* arg) {
    cout << "Hello from thread! ID = " << pthread_self() << endl;
    return nullptr;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, nullptr, worker, nullptr);
    pthread_join(tid, nullptr);
    cout << "Main thread done\n";
    return 0;
}
```

### 🔍 Disassembly (simplified)

If you compile with:

```bash
g++ -O2 -pthread -S thread.cpp -o thread.s
```

You’ll see `call pthread_create@PLT`, which links to glibc.
Inside glibc, you’ll find something like:

```asm
call clone@PLT
mov eax, 56        ; SYS_clone
syscall
```

So, `pthread_create()` → `clone()` → `syscall`.

---

## ⚙️ 3. Creating a Thread Manually Using clone() in C++

Let’s bypass pthread and use **`clone()` syscall directly**.

```cpp
#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>

int threadFunc(void* arg) {
    std::cout << "Hello from clone thread!\n";
    return 0;
}

int main() {
    const int STACK_SIZE = 1024 * 1024;
    void* stack = malloc(STACK_SIZE);
    void* stackTop = (char*)stack + STACK_SIZE;

    pid_t tid = clone(threadFunc, stackTop,
                      CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM,
                      nullptr);

    if (tid == -1) {
        perror("clone");
        return 1;
    }

    waitpid(tid, nullptr, 0);
    std::cout << "Main done\n";
    free(stack);
    return 0;
}
```

Here, you directly use `clone()` — the same syscall used by pthread internally.

---

## 🧠 4. Creating a Thread Using Raw Inline Assembly

Now, let’s go **fully raw** — directly invoke the `clone` syscall in inline assembly.

### Example:

```cpp
#include <iostream>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <sched.h>

int thread_main(void* arg) {
    std::cout << "Thread running (raw asm)\n";
    _exit(0);
}

int main() {
    const int STACK_SIZE = 1024 * 1024;
    void* stack = malloc(STACK_SIZE);
    void* stackTop = (char*)stack + STACK_SIZE;

    pid_t tid;

    asm volatile(
        "mov %[stack_top], %%rsi\n\t"     // 2nd arg (stack)
        "mov %[flags], %%rdi\n\t"         // 1st arg (flags)
        "mov $56, %%rax\n\t"              // SYS_clone = 56
        "syscall\n\t"
        "mov %%eax, %[tid]\n\t"           // return value
        : [tid]"=r"(tid)
        : [flags]"r"(CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND),
          [stack_top]"r"(stackTop)
        : "%rax", "%rdi", "%rsi", "memory"
    );

    if (tid == 0) {
        thread_main(nullptr); // child thread code
    } else {
        waitpid(tid, nullptr, 0);
        std::cout << "Main done\n";
    }

    free(stack);
    return 0;
}
```

✅ This inline assembly:

* Directly performs `syscall` with number `56` (for `clone`)
* Doesn’t use libc at all
* Creates a lightweight thread sharing memory with the parent

---

## 🧩 5. Key System Calls Involved

| System Call          | Used By                  | Purpose                        |
| -------------------- | ------------------------ | ------------------------------ |
| `clone()`            | pthreads, manual threads | Creates new thread/process     |
| `mmap()`             | glibc                    | Allocates memory for stack     |
| `futex()`            | pthread sync             | Locking/waiting                |
| `exit()` / `_exit()` | glibc                    | Thread exit cleanup            |
| `set_tid_address()`  | pthread init             | Manage TID for thread tracking |

---

## 🧱 6. Visualization Summary

```
C++ code
 └── pthread_create()
      └── clone()   ← system call
           └── syscall instruction
                └── Kernel creates thread
```

And your inline asm example skips straight to the bottom:

```
You → syscall clone → Kernel thread
```

---

Would you like me to show **what the compiled binary’s system calls look like** using `strace` or `objdump -d` so you can *see the syscall instruction sequence in the actual ELF*?
