#include "evens_array.hpp"
#include <iostream>


void find_evens(int* ptr_a1,bool* ptr_a2, int number) {
  for (int j = 0; j < number; j++) {
    if (*(ptr_a1 + j) % 2 == 0) {
      *(ptr_a2 + j) = { 1 };
    } else {
      *(ptr_a2 + j) = { 0 };
    }
  }
}
