#pragma once
#include <iostream>
using namespace std;

class Integer {
    int *m_pInt;
public:
    Integer();
    Integer(int value);
    Integer(const Integer &obj);
    Integer(Integer &&obj); // Move semantic

    int GetValue() const;
    void SetValue(int value);
    ~Integer();
};