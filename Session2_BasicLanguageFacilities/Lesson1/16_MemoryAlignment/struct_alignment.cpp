# include <iostream>

int main(){
    struct {
        int int_element;
        char char_element;
    } sample_struct1;
    // sample_struct1.int_element = 1;
    // sample_struct1.char_element = 'a';
    std::cout << sizeof(sample_struct1) << std::endl; // 8

    struct {
        int int_element1;
        int int_element2;
    } sample_struct2;
    std::cout << sizeof(sample_struct2) << std::endl; // 8

    struct {
        char int_element;
        char char_element;
    } sample_struct3;
    std::cout << sizeof(sample_struct3) << std::endl; // 2

    // Ineffective alignment
    struct {
        char char_element1;
        int int_element;
        char char_element2;
    } sample_struct4;
    std::cout << sizeof(sample_struct4) << std::endl; // 12

    // Effective alignment
    struct {
        char char_element1;
        char char_element2;
        int int_element;
    } sample_struct5;
    std::cout << sizeof(sample_struct5) << std::endl; // 8

    return 0;
}