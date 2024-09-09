struct Base1 final { };

struct Derived1 : Base1 { }; // ill-formed because the class Base1 
                             // has been marked final

                             