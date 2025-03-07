#include <iostream>
#include <string.h>
int main(){
   int num=100;
   std::cout<<"\nValue for num:"<<num;
   char c[2];
   try {
    strcpy(c,"abcdefghijklmnopqrstuvwxyz");
   } catch (...) {
    std::cout << "An exception";
   }
   std::cout<<"\nValue for c:"<<c;
   return 0;
}