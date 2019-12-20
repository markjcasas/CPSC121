#include <iostream>
#include "rectangle.hpp"

void draw_rectangle(int a, int b) {
  if (a <= 0) {
    std::cout << "Invalid length and/or width values." << '\n';
  } else if (b <= 0) {
    std::cout << "Invalid length and/or width values." << '\n';
  } else {
    for (int i = 0; i < a; i++) {
      std::cout << std::string(b, '*') << '\n';
    }
  }
}
