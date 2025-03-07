# Main function must be an int function, tested with gcc/g++ clang/clang++
  	"""
    	pi@raspberrypi:~/workspace/CppLessons/Session1_CompilerAndDebugger/CplusAssembler $ gcc Ex1.cpp 
    	Ex1.cpp:4:1: error: ‘::main’ must return ‘int’
    	    4 | void main() {
    	      | ^~~~
    	pi@raspberrypi:~/workspace/CppLessons/Session1_CompilerAndDebugger/CplusAssembler $ g++ Ex1.cpp 
    	Ex1.cpp:4:1: error: ‘::main’ must return ‘int’
    	    4 | void main() {
    	      | ^~~~  
	
    	pi@raspberrypi:~/workspace/CppLessons/Session1_CompilerAndDebugger/CplusAssembler $ clang Ex1.cpp 
    	Ex1.cpp:4:1: error: 'main' must return 'int'
    	void main() {
    	^~~~
    	int
    	1 error generated.  
	
    	pi@raspberrypi:~/workspace/CppLessons/Session1_CompilerAndDebugger/CplusAssembler $ clang++ Ex1.cpp 
    	Ex1.cpp:4:1: error: 'main' must return 'int'
    	void main() {
    	^~~~
    	int
    	1 error generated.
  	"""

# Add option -S to see assembly code 
g++ -S Ex1.cpp
# Add option -E to see precompiled code
g++ -E Ex1.cpp > Ex1.precompiledcode

