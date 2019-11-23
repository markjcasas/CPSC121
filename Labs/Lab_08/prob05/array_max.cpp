#include "array_max.hpp"
#include <iostream>

int array_max(int array[], int magnitude) {
  int position = magnitude - 1;
  if (magnitude <= 0) {
    return -1;
  } else if (magnitude == 1) {
    return array[0];
  } else {
    return std::max(array[position], array_max(array, position));
  }
}
