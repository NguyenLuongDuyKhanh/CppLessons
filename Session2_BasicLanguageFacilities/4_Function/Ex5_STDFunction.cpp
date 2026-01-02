// C++ program to pass the std::function
// as arguments
#include <bits/stdc++.h>
using namespace std;

// Functions for simple math operations
int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a * b;
}
int divs(int a, int b) {
    return a / b;
}

// A simple class
class C {
public:
    int f(int a, int b) {
        return a * b;
    }
};

// Using std::function as parameter
void func(int a, int b, 
         function<int(int, int)> calc) {
  
    int res = calc(a, b);
    cout << "Result: " << res << endl;
}

// Composed function
function<int(int)> cf(function<int(int)> f1,
                        function<int(int)> f2) {
  
  	// Returning a lambda expression that
  	// in turn returns a function
    return [f1, f2](int x) {
      
      	// Apply f1 first, then f2
        return f2(f1(x)); 
    };
}

int main() {
    
  	// Calling all the arithmetic functions
    func(8, 2, add);
    func(8, 2, sub);
    func(8, 2, mul);
    func(8, 2, divs);

    C c;
    
    // Wrapping member function of C
    function<int(C&, int, int)> calc = &C::f;
    
    // Call the member function using function
  	if (calc)
    	cout << "Product: " << calc(c, 4, 5);
  	else
      	cout << "No Callable Assigned";

    auto add = [](int x) { return x + 2; };
    auto mul = [](int x) { return x * 3; };

    function<int(int)> calc1 = cf(add, mul);
    cout << calc1(4);
    return 0;
}