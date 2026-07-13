#include <iostream>
#include <vector>
#include <utility> // Required for std::move
#include <string>
using namespace std;

class Sample {
    private:
        int* attr;
    public:
        Sample() : attr(new int(10)){};
        Sample(Sample &&obj) {
            cout << "Sample(Sample &&obj)" << endl;
            attr = obj.attr;
            obj.attr = nullptr;
        }
        Sample(const Sample &obj) {
            cout << "Sample(const Sample &obj)" << endl;
        }
        void getAttr() {
            if (attr) {
                cout << *attr << " at " << attr << endl;
            } else {
                cout << "cannot read from nullptr" << endl;
            }
        }
};

int main() {
    Sample a;
    Sample b = a;           // Call the copy constructor
    a.getAttr();            // Return number 10. 10 at 0x55555832b0
    Sample c = std::move(a);// Call move constructor
    a.getAttr();            // Null, a loss its resource
    c.getAttr();            // number 10, c has a's resource. 10 at 0x55555832b0

    /* a and c live in difference address but their resource is just one at 0x55555832b0*/
    cout << &a << endl; // 0x7fffffece8
    cout << &c << endl; // 0x7fffffecd8
    return 0;
}