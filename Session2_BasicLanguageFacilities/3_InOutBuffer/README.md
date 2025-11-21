## Console I/O
- `std::basic_ostream` and `std::basic_istream` are two class in `std` namespace that serves input.
- `std::ostream` and `std::istream` are type definitions of those classes.
- `std::cout` is an object of `std::ostream` represents the console, whereas `std::cin` is an object of `std::istream`.
- `std::cout << "something"` pass something to `cout` object, also mean pass something to the console.
- `std::cin >> something` extract something from `cin` object, also mean extract something form the keyboard to store in `something`.
- All above class/objects/types are declared in `iostream` header

## What `flush` does
Without a `flush`/`endl`, the above program in `Ex1_Flush.cpp` will output 1 2 3 4 5 at once after 5 seconds.
Adding `flush` force flush output buffer to the permenance location.
`\n` is a character. The output buffer will not be flushed immediately, and the message will be stored in the buffer until the program finishes.

## Compare `endl` to `\n`:
- `endl` is a manipulator and doesn't occupy any memory.  `\n` is a character occupies 1 byte memory.
- `endl` is supported in C++ only while `\n` can be used in C/C++.

## Reference 
> https://www.geeksforgeeks.org/buffer-flush-means-c/
> https://www.geeksforgeeks.org/endl-vs-n-in-cpp/