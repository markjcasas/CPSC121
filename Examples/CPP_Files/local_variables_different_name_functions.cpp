#include <iostream>

int sum(int x, int y) {
  int output = x + y;
  return output;
}
int main() {
  int num1, num2, result;
  std::cout << "Please input 2 integer values: ";
  std::cin >> num1 >> num2;
  num1 = 3; // assume user inputted 3
  num2 = 5; // assume user inputted 5
  result = sum(num1 , num2);
  std::cout << "Sum result: " << result;
  return 0;
}
