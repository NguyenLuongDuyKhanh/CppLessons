#include <iostream>
using namespace std;
// Memory on stack is allocated faster than on heap (just increasing head/tail pointer)
// Stack automatically allocate/deallocation when enter/exist the scope
int main() {
    constexpr uint16_t sample{10};
    cout << sample << endl;
    sample = 50;
    
    return 0;
}