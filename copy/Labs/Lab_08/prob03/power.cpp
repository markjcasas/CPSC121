#include "power.hpp"
#include <iostream>

int power(int number, int exponent) {
  if (exponent == 0) {
    return 1;
  } else if (exponent == 1) {
    return number;
  } else {
    return number * power(number, exponent - 1);
  }
}
