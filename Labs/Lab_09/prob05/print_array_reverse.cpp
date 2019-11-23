#include "print_array_reverse.hpp"
#include <iostream>

void print_array_reverse(int* a, int number) {
  int index = number - 1;
  if (number <= 0) {
    std::cout << "There are no contents in this array!" << '\n';
  } else {
    int b[number];
    for (int j = 0; j < number; j++) {
      b[j] = *(a + index - j);
    }
    std::cout << "The contents of the array in reverse are:" << '\n';
    for (int k = 0; k < number; k++) {
      std::cout << b[k] << " ";
    }
    std::cout << '\n';
  }
}
