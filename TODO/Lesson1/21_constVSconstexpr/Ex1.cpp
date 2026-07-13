#include <iostream>
using namespace std;

class SampleClass {
    private:
        int _private_member{10};
    public:
        int sampleConstFunction() const {
            privateSetter();
            return 0;
        }

        const int sampleConstFunction2
        void privateSetter() {
            _private_member = 50;
        }

        int privateGetter() {
            return _private_member;
        }
};

int main() {
    SampleClass sampleInstance;

    sampleInstance.sampleConstFunction();
    cout << sampleInstance.privateGetter();

    return 0;
}
