#include <iostream>

int sum(int num1, int num2){
  int result = num1 + num2;
  return result;
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
