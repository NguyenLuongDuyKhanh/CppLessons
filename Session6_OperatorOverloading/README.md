## Basic
- Can be implemented as member or global function
    * In member function, one of operands is passed as argument through this pointer
        Integer Integer::operator +(const Integer &)
    * In global function, required same number as the operands
        Integer operator +(const Integer &, const Integer &)
- Operator overloading is not an operator, it is a function looks like a pointer. Thus it invoke 'call' system call underlie
- New and delete operator can be overloaded in global (for general use) or in class member (to used for specific class).
- Overloading new and delete can be use to implement garbage collector of a class.
- Operator function must not be static (except new and delete)
- We cannot access private member in a global operator, hence we need friend keywork
- Friend is discourage because it can access private attr directly -> dangerous.

## Todo 
- Pre-increment and post-increment