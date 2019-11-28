#include "count-odd.hpp"
#include <iostream>

int count_odd(int input) {
  if (input == 0) {
    return input;
  } else if (input % 2 == 0) {
    return count_odd(input - 1);
  } else {
    return input % 2 + count_odd(input - 1);
  }
}
