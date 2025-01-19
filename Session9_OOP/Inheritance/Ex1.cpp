#include <iostream>
using namespace std;

class Base {
private:
    // Composition relationship
    // Base class has a Element
    // ElementType sampleElement{};
    int samplePrivate{0};

protected:
    int sampleProtected{0};

public:
    int samplePublic{0};
    Base() {
        cout << "Constructor of base class is called" << endl;
    };
    ~Base() {
        // cout << "Destructor of base class is called" << endl;
    }
};

class PublicChild : public Base {
public:
    void getParent() {
        // Child cannot access parent's public
        // cout << samplePrivate << endl;
        cout << sampleProtected << endl;
        cout << samplePublic << endl;
    }
};

class ProtectedChild : protected Base {

};

class PrivateChild : private Base {

};

class PublicChild2 : public Base {
public:
    PublicChild2(int a) {
        cout << a << endl;
        cout << "Child class defines its own constructor, hence the constructor of base class would not be called automatically" << endl;
    };
};

int main() {
    Base sampleBase{};
    // Cannot access private and protected member outside the class
    // cout << sampleBase.samplePrivate << endl;
    // cout << sampleBase.sampleProtected << endl;

    // Only public members can be accessed outside the class
    cout << sampleBase.samplePublic << endl;

    PublicChild samplePublicChild{};
    samplePublicChild.getParent();

    ProtectedChild sampleProtectedChild{};

    PrivateChild samplePrivateChild{};
    cout << "Overloading constructor " << endl;
    PublicChild2 samplePrivateChild2{1};
    return 0;
}
