#include "min.hpp"
#include <iostream>

int min(int* a, int number) {
  int index = number - 1;
  if (number == 1) {
    return *a;
  } else {
    return std::min(*(a + index), min(a, index));
  }
}
