#include <iostream>

using namespace std;

union test

{
   int i;  
   double d;
   float f;
   short int e;
   int t;
} test2;

int test_function() {
   int a;
   char b;
   double c;
   float d;

   cout << &a << "\t" << &b << "\t" << &c << "\t" << &d << "\t" <<endl;

   return 0;
}

int main()
{
   int a;
   double c;
   float b;
   short int e;
   int t;
    
   cout << &a << "\t" << &c << "\t" << &b << "\t" << &e << "\t" << &t << endl;
   /*
      0x7eea22fc      0x7eea22f0      0x7eea22ec      0x7eea22ea      0x7eea22e4
      Order of ellement in memory => int t -> short int e -> float b -> double c -> int a
   */ 

   cout << &test2.i << "\t" << &test2.d << "\t" << &test2.f << "\t" << &test2.e << "\t" << &test2.t << endl;
   /*
      0x210d0 0x210d0 0x210d0 0x210d0 0x210d0
      Only one address for all ellement
   */ 

   test_function();
   return 0;
}
