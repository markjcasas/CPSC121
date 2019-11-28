#include "find_number.hpp"
#include <iostream>

void Numbers::init() {
  for (int i = 0; i < capacity_; i++) {
    *(values_ + i) = i * 2 + 2;
  }
}

void Numbers::display_array() {
  for (int j = 0; j < capacity_; j++) {
    std::cout << *(values_ + j) << " ";
  }
  std::cout << '\n';
}



void Numbers::find_number(int number) {
  for (int k = 0; k < capacity_; k++) {
    if (number == *(values_ + k)) {
      std::cout << number << " is in the array" << '\n';
      break;
    }
  }
}
