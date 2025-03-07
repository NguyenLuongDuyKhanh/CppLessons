#include <iostream>
int main() {
  int num1 = 10;
  int num2 = 0;
  try {
    int quotient = num1 / num2;
    printf("\n Quotient is: %d", quotient);
    if (quotient == 0)
      throw quotient;
  } catch (...) {
    std::cout << "exception";
  }

  return 0;
}