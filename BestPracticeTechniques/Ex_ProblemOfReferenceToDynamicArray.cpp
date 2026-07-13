#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a{1,2,3};
    int* ptr=&a[0];
    cout << ptr << endl;

    for(int i=0; i<100; i++) {
        a.push_back(i);
        if (&a[0] != ptr) {
            ptr = &a[0];
            cout << ptr << endl;
        }
    }
} 

// The below out prove that when the vector extends, its memory is reallocated so the reference to elements changes (the pointer of course change too)
/*
0x5555555862b0
0x5555555866e0
0x555555586700
0x555555586740
0x5555555867b0
0x555555586880
0x555555586a10
[1] + Done                       "/usr/bin/gdb" --interpreter=mi --tty=${DbgTerm} 0<"/tmp/Microsoft-MIEngine-In-ltrjg2sk.gap" 1>"/tmp/Microsoft-MIEngine-Out-njxbrrzv.4gq"
*/