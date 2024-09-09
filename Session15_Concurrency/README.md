## Thread vs process
- Threads are not independent from each other unlike processes. As a result, threads shares with other threads their code section, data section and OS resources like open files and signals. 
- But, like processes, a thread has its own program counter (PC), a register set, and a stack space. 

Threads operate faster than processes due to following reasons: 
    1) Thread creation is much faster. 
    2) Context switching between threads is much faster. 
    3) Threads can be terminated easily 
    4) Communication between threads is faster.


## Normal thread
- It is important to call one of <join or detach> on a joinable thread to keep the main thread alive utill the child thread complete

In the destructor of std::thread, std::terminate is called if:
    - the thread was not joined (with t.join())
    - and was not detached either (with t.detach())
Thus, you should always either join or detach a thread before the flows of execution reaches the destructor.

Use CustomString to examine and see:
```
    CustomString()
    [main] Started an operation
    CustomString(const String&)
    constructor of CustomString was called twice 
    use ref or cref (const reference) to avoid this
```

## Joinable or not
- After join()/detach() function return, the thread cannot be joined again -> not joinable
- Joining a thread more than once will cause 
    ```
    terminate called after throwing an instance of 'std::system_error'
      what():  Invalid argument
    ```
    -> a best practice to check whether a thread is joinable() before joining 

## Detach
- Separates the thread of execution from the thread object, allowing execution to continue independently.
- Detaching a thread means allowing the thread to execute independently from the thread that created it. 
- Once detached, the parent thread can continue its execution without waiting for the detached thread to finish. 
- Detaching a thread is useful when you don’t need to synchronize with the thread or obtain its return value.
- You should be careful while detaching a thread as the main thread may terminate before the thread completes its task.

## Race condition and mutex
- In Ex2_mutex.cpp g_Data is a race condition because 2 threads access it simutaniously 
- A std::mutex lock will ensure one thread can access at a time
- Compare to contex manager in python, std::lock_guard ensure the lock will be released eventually even if encouter exception/return while acquring lock

## High level (task-based) concurrency
