#include <iostream>
#include <string>
int main() {
char o;
int input1;
int input2;
int add;
int subtract;
int multiply;
int divide;
do {
  std::cout << "Please enter the operation (+, -, *, /) or x to exit the program: ";
  std::cin >> o;
  std::cout << '\n';
  if (o=='x') {
    std::cout << " " << '\n';
  } else {
      if (o == '+') {
        std::cout << "Please input the first number: ";
        std::cin >> input1;
        std::cout << "Please input the second number: ";
        std::cin >> input2;
        add = input1 + input2;
        std::cout << "You chose to add: ";
        std::cout << input1;
        std::cout << " + ";
        std::cout << input2;
        std::cout << " = ";
        std::cout << add << '\n';
      } else if (o == '-') {
        std::cout << "Please input the first number: ";
        std::cin >> input1;
        std::cout << "Please input the second number: ";
        std::cin >> input2;
        subtract = input1 - input2;
        std::cout << "You chose to subtract: ";
        std::cout << input1;
        std::cout << " - ";
        std::cout << input2;
        std::cout << " = ";
        std::cout << subtract << '\n';
      } else if (o == '*') {
        std::cout << "Please input the first number: ";
        std::cin >> input1;
        std::cout << "Please input the second number: ";
        std::cin >> input2;
        multiply = input1 * input2;
        std::cout << "You chose to multiply: ";
        std::cout << input1;
        std::cout << " * ";
        std::cout << input2;
        std::cout << " = ";
        std::cout << multiply << '\n';
      } else if (o == '/') {
        std::cout << "Please input the first number: ";
        std::cin >> input1;
        std::cout << "Please input the second number: ";
        std::cin >> input2;
        divide = input1 / input2;
        std::cout << "You chose to divide: ";
        std::cout << input1;
        std::cout << " / ";
        std::cout << input2;
        std::cout << " = ";
        std::cout << divide << '\n';
      } else {
        std::cout << "Invalid operation" << '\n';
      }
  }
} while(o != 'x');



  return 0;
}
