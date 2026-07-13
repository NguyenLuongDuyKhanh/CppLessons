#include <iostream>
#include <stdio.h>
using namespace std;

void introducedStatic() {
    // This line introduce a static variable and initialize its value by 6. 
    // It is initialzed once only, no matter how many times this function are called.
    static int sample = 6; 

    // This line is called when introducedStatic is called.
    sample++;    
    printf("%d \n", sample);
};

void consumeStatic() {
    // This function try to access a local-static variable, of cource it cannot/
    // A local static is accessiable in its scope only.
    
    // printf("%d", sample);
};

int main() {
    /* The first call, 'sample' is initialized by 6 and increase to 7 */
    introducedStatic();

    /* The second call, 'sample' was already initialize, it then increase from 7 to eight */
    introducedStatic();

    return 0;
};
