#include <cmath>
#include <iostream>
int main() {
  int number;
  int power;
  int result;
  const int zero = 0;
  std::cout << "Please enter a number: ";
  std::cin >> number;
  std::cout << "Please enter the power: ";
  std::cin >> power;
  if (power >= zero) {
    result = std::pow(number,power);
    std::cout << number;
    std::cout << " ^ ";
    std::cout << power;
    std::cout << " = ";
    std::cout << result;
    std::cout << '\n';
  } else {
    std::cout << "Negative powers are currently unsupported." << '\n';
  }
  return 0;
}
