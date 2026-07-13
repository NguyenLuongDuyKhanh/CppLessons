# Exception

## Exception | Error | Bug | crash


## The use of Try-Catch-Throw
Only one "try", many "catch". Can be used without throw but this block is useless in that case


## Synchronous Exceptions and Asynchronous Exceptions.
Synchronous exceptions are the exceptions that occur at a particular instruction. They can only originate from throw expressions 
Asynchronous exceptions are the exceptions that create errors that are not controllable by the program. For example-hardware malfunctions, disk failure, etc.

## Segfault and ilegal instruction crash cannot be handled

## A brief list of Exceptions can be found here
https://www.geeksforgeeks.org/cpp-program-to-handle-the-exception-methods/
##
In example 2, there are 2 user-defined exception
    'MyPrimeException' derive from 'exception'
    'MyPrimeException_1' derive from 'MyPrimeException'
- If catch is used with a specific Exception, it can only catch that exceptiom. See Ex2.cpp, the catch statement in sampleFunction can only catch MyPrimeException_1, MyPrimeException cannot be catched inside sampleFunction hence it will be popagate to the caller, in this case is the main function. Say if it event cannot be catch in main, the program will cash
    """
        terminate called after throwing an instance of 'MyPrimeException'
    """
- If an exception happend in the try block, all resource which were initialized in the try block will be destroyed before jumping onto the catch block, check the deconstructing of 'Test' object.
    """
        Constructor of Test 
        Destructor of Test 
        Caught Exception
    """

## Ex3.cpp ilustrate the below concept, but it cannot be built on C++ 17
When a function with an exception specification throws an exception that is not listed in its exception specification, the C++ runtime does the following:
    - The unexpected() function is called.
    - The unexpected() function calls the function pointed to by unexpected_handler. By default, unexpected_handler points to the function terminate().
