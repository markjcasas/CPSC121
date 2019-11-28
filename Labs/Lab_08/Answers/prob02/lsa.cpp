#include "lsa.hpp"
#include <iostream>

int linear_search(int arr[], int input, int magnitude) {
  if (magnitude == 0) {
    return -1;
  } else {
    int position = magnitude - 1;
    if (arr[position] != input) {
      return linear_search(arr, input, position);
    } else if (position == -1) {
      return position;
    } else {
      return position;
    }
  }
}
