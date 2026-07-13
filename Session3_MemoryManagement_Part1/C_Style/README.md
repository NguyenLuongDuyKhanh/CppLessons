## Dynamic allocations are done by the below functions in C
- malloc - allocate raw memory.
- calloc - allocate memory an initializes it to zero.
- realloc - check whether it has sufficient space or not? If not, allocate more.
- free - deallocate
  
## Dangling pointer
Dangling pointer is the pointer points to a memory that already been freed.
It is best practice to assign the pointer to nulltre after free.

## Check return pointer
Allocation may fail an the return value is a NULL pointer. 

## malloc vs new
malloc

It is RAII (Resource Acquisition Is Initialization - Chiếm dụng Tài nguyên là Khởi tạo)

| malloc                                                | new                                               |
| --------                                              | -------                                           |
| Function                                              | Operator                                          |
| No initialize data                                    | Initialize data as soon as memory is allocated.   |
| No call constructore                                  | Call constructor automatically                    |
| Return void pointer that needs to be type casted      | Return correct type of pointer                    |
| Cannot be customize                                   | Can be customized through overloading             |
| Return NULL on failure                                | Throw exception on failure                        |