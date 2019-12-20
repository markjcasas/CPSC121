#include <iostream>
int main() {
  int number;
  int multiple;
  int result;
  const int zero = 0;
  std::cout << "Please enter a number: ";
  std::cin >> number;
  std::cout << "Number of times to be added: ";
  std::cin >> multiple;
  if (multiple >= zero) {
    result = number * multiple;
    std::cout << "The sum is ";
    std::cout << result;
    std::cout << '\n';
  } else {
    std::cout << "Repetitions can't be negative" << '\n';
  }
  return 0;
}
