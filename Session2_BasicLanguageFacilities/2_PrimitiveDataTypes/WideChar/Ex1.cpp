#include <iostream>
using namespace std;


int main() {
    // 'L' prefix for wide-character literals and wide string literals 

    wchar_t* var = L"Привет мир\n"; // hello world in russian
    wchar_t s[] {L"Привет мир\n"};
    
    wchar_t wide_char {L'A'};
    char16_t char_16bit {u'A'}; // UTF-16 
    char32_t char_32bit {U'A'}; // UTF-32

    cout << sizeof(wide_char) << endl; // 4 bytes
    cout << sizeof(char_16bit) << endl; // 2 bytes
    cout << sizeof(char_32bit) << endl; // 4 bytes
    return 0;
}