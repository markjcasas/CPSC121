#include <iostream>
#include "header.hpp"
#include <string.h>
#include <stdio.h>

int main() {
  std::string text;
  std::cout << "Please enter header text: ";
  std::getline(std::cin, text);

  if (within_width(text, 80)) {
    display_header(text);
  } else {
    std::cout << text;
  }
  return 0;
}
