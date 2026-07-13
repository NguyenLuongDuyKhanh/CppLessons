#include <iostream>

using namespace std;
struct sample1 {
    char a;
    int b;
    char c;
} __attribute__((packed));;

struct sample2 {
    char a;
    char c;
    int b;
};

int main() {
    struct sample1 sample1_obj{'a', 1, 'c'};
    struct sample2 sample2_obj{'a', 'c', 1};
    cout << sizeof(sample1_obj) << endl;
    cout << sizeof(sample2_obj) << endl;
    int a;
    cin >> a;
    int b;
    b = 10/a;

    cout << "End.";
    return 0;
}