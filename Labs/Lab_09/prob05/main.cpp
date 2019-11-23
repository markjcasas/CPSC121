#include "print_array_reverse.hpp"
#include <iostream>

int main() {

  int size;
  int array[10];

  std::cout << "Enter an integer for the size of the array(Must be less than "
               "or equal to 10): ";
  std::cin >> size;
  std::cout << "Inputs for the array:\n";
  for (int i = 0; i < size; i++) {
    std::cout << "Enter the integer for index " << i << ": ";
     // Assign values from cin into indicies of the array.
     int input;
     std::cin >> input;
     array[i] = input;
  }
  // Call your print_array_reverse function and pass the necessary
  // parameters
  print_array_reverse(array, size);

  return 0;
}
