// C++ program to illustrate how to 
// avoid errors using Header Guard 
#include <iostream> 
using namespace std;
// Include header guards in both 
// the header files 
#include "mathematics.h" 

// Now, the error will not occur 
#include "pentagon.h" 

using namespace std; 

// Driver Code 
int main() 
{ 
	// Function Call to find the 
	// sides of the pentagon 
	int i{ getting_pentagon_side() }; 

	// Print the sides 
	cout << "sides in a pentagon is: " << i; 

	return 0; 
} 
