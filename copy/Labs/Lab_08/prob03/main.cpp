#include "power.hpp"
#include <iostream>

int main() {
  int base, exp;
  std::cout << "Enter a base: ";
  std::cin >> base;
  std::cout << "Enter an exponent: ";
  std::cin >> exp;
  int exponent_value;
  // Provide code that calls the recursive power function you created and pass
  // the base and exp that the user provided. The result of the function should
  // be stored in exponent_value.
  exponent_value = power(base, exp);

  std::cout << base << " ^ " << exp << " = " << exponent_value << "\n";
}
