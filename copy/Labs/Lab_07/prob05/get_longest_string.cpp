#include "get_longest_string.hpp"
#include <iostream>

std::string String::str() {
  return str_;
}




std::string get_longest_string(std::string x[], int y) {
  int j = y;
  std::string big = x[0];
for (int j = 1; j < y; j++) {
    if (big.length() < x[j].length()) {
      big = x[j];
    }
  }
  return big;
}
