#include <iostream>
int main(){
   char *str;
   char name[]="iostream";
   str=name;
   while(1)
      (*str++)='a';
}