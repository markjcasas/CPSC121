#include "add_array.hpp"
#include <iostream>

void add_array(int* a1, int* a2, int number) {
  for (int i = 0; i < number; i++) {
    *(a1 + i) += *(a2 + i);
  }
}
