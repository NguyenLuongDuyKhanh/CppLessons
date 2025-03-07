#include <iostream>
#include <string.h>
int factorial(int num){
   if(num==0)
      return 1;
   else
      return(factorial(num));
}
int main(){
   int n=10;
   int fact=factorial(n);
   std::cout<<fact;
}