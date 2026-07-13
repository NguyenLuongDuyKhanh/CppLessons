## Raw pointer
- A good practice is that assign nullptr to a pointer after delete it, because it holds the address of the object which is deleted
- void pointer or "Generic Pointer"
    can point to objects of any data type
    general purpose pointer that can store the address of any data type and it can be typecasted to any type. A void pointer is not associated with any particular data type
    
## unique_ptr
- Use if a pointer has not to be shared with other parts of the code
- re
- Copy constructor of unique pointer is delete, hence we cannot pass it to other part of the code (other functions). must use std::move to move to other function

## sharing a unique pointer
- Ex2 demonstrade a pointer is share among objects: prj is shared among Employees.
- A drawback is that we must manage memory manually
- Ex3_share_unique_ptr we was trying to move a unique_ptr to e2. It cause ptr cannot be used -> crash with Segmentation fault
