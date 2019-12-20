#include "evens_array.hpp"
#include <iostream>

int main() {
  // Declare initial size of array
  int SIZE = 5;

  // Create integer array with initial values
  int a1[] = {15, 60, 7, 98, 48};

  // Create boolean array using the given SIZE
  bool a2[SIZE];

  // Call the find_evens function and provide necessary
  // parameters


  find_evens(a1, a2, SIZE);





  // Print contents of the array
  for (int i = 0; i < SIZE; i++) {
    std::cout << a2[i];
  }
  std::cout << "\n";
  return 0;
}
