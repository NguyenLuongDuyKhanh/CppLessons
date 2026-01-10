#include <iostream>
using namespace std;


struct bien1
{
   int b1i;
   float b1f;
   char cha;
} __attribute__ (( packed ));

int main()
{
   bien1 bien1;

   cout << sizeof( bien1 ) << "\t" << sizeof( bien1.b1i ) << "\t" << sizeof( bien1.b1f ) << "\t" << sizeof( bien1.cha ) << endl;

   return 0;
}
