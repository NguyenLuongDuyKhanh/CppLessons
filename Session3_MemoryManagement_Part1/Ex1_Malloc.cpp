#include <iostream>
using namespace std;

class Sample {
private:
public:
    Sample() {
        cout << "Constructor is called" << endl;
    }
};

int main() {
    Sample* a = (Sample*)malloc(sizeof(int));

    return 0;
}