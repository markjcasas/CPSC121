#include "add_array.hpp"
#include <iostream>

int main() {
  int array_1[10];
  int array_2[10];
  int SIZE = 10;

  std::cout << "Inputs for the first array:\n";
  for (int i = 0; i < 10; i++) {
    std::cout << "Enter the integer for index " << i << ": ";
    std::cin >> array_1[i];
  }
  std::cout << "\nInputs for the second array:\n";
  for (int i = 0; i < 10; i++) {
    std::cout << "Enter the integer for index " << i << ": ";
    std::cin >> array_2[i];
  }

  std::cout << "\nThe first array contains:\n";
  for (int i = 0; i < 10; i++) {
    std::cout << array_1[i] << " ";
  }
  std::cout << "\n";

  std::cout << "\nThe second array contains:\n";
  for (int i = 0; i < 10; i++) {
    std::cout << array_2[i] << " ";
  }
  std::cout << "\n";

  std::cout << "\nCalling add_array using the first and second array ...\n";

  // Call your add_array function and pass necessary parameters

  add_array(array_1, array_2, SIZE);

  std::cout << "\nAfter calling add_array, the first array now contains:\n";
  for (int i = 0; i < 10; i++) {
    std::cout << array_1[i] << ' ';
  }
  std::cout << "\n";
  return 0;
}
