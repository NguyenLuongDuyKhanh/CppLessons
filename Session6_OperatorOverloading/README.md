## Basic
- Can be implemented as member or global function
    * In member function, one of operands is passed as argument through this pointer
        Integer Integer::operator +(const Integer &)
    * In global function, required same number as the operands
        Integer operator +(const Integer &, const Integer &)

## Todo 
- Pre-increment and post-increment