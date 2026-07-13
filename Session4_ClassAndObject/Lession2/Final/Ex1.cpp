struct Base2 {
    virtual void f() final;
};

struct Derived2 : Base2 {
    void f(); // ill-formed because the virtual function Base2::f has 
              // been marked final
};
/*
Ex1.cpp:6:10: error: virtual function ‘virtual void Derived2::f()’ overriding final function
    6 |     void f(); // ill-formed because the virtual function Base2::f has
      |          ^
Ex1.cpp:2:18: note: overridden function is ‘virtual void Base2::f()’
    2 |     virtual void f() final;
      |
*/