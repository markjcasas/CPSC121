#include <iostream>
#include "most_sig_digit.hpp"
#include <math.h>

int main() {
  int input = 0;
  int most_significant = 0;
  std::cout << "Please enter an integer, this program will produce it's more "
               "significant digit: ";
  std::cin >> input;

  // Add the code here to store the most significant digit into
  // the most_significant variable
  most_significant = most_significant_digit(input);
  std::cout << "The most significant digit is " << most_significant << "\n";

  return 0;
}
