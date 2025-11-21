## The problem of 
- Range-based for loops work with arrays, but not with pointers. 
- When you have a function parameter that is declared as an array, it is adjusted to a pointer type.
- If you pass the array by reference instead (float (&arrays)[3][3]), it won't adjusted to a pointer

## The problem of cannot show the reference of elements in char[]
- There's an overload of operator<< for char*, that tries to print the nul-terminated string that it thinks your pointer points to the first character of. But not all char arrays are nul-terminated strings, hence the garbage.

- Arrays decay to pointers when passed to functions (but not in pass by reference method), so const int arr[5] is effectively the same as const int* arr. This means there’s no actual enforcement of the array’s size at runtime.
- If modifications are made to the array inside a function then it will affect the original array as the arrays can only be passed by pointer or reference.
- The use of 'const' keyword can prevent the function from modifying the array param 
- There is no way to determine an array's size through its pointer

## Array decay

## Remove from an array 
Removing an element from an array is tricky because we cannot modify the memory space occupied by the array.
So, we pseudo delete the element by moving it to the end of the array and reducing the size

## Reference 
https://www.geeksforgeeks.org/pass-array-to-functions-in-cpp/
https://www.geeksforgeeks.org/using-sizof-operator-with-array-paratmeters-in-c/