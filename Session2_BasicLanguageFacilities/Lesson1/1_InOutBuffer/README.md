##
Without a 'flush'/'endl', the above program will output 1 2 3 4 5 at once after 5 seconds.
Adding 'flush' force flush output buffer to the permenance location.
'\n' is a character. The output buffer will not be flushed immediately, and the message will be stored in the buffer until the program finishes.

Compare 'endl' to '\n':
    'endl' is a manipulator and doesn't occupy any memory.  '\n' is a character occupies 1 byte memory.
    'endl' is supported in c++ only while \n can be used in c/c++

## Reference 
https://www.geeksforgeeks.org/buffer-flush-means-c/
https://www.geeksforgeeks.org/endl-vs-n-in-cpp/