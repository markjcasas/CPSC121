#include <iostream>
#include "rectangle.hpp"

int main() {
  int length;
  int width;
  std::cout << "Please enter the length: ";
  std::cin >> length;
  std::cout << "Please enter the width: ";
  std::cin >> width;
  // Add the code here to call the appropriate functions
  // and  display the correctly formatted output on the
  // screen.
  draw_rectangle(length, width);
  return 0;
}
