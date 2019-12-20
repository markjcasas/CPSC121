#include "array_max.hpp"
#include <iostream>

int main() {
  int size_ = 10;
  int arr[10] = {10, 9, 6, 1, 2, 4, 16, 8, 7, 5};
  int max_value;
  // Provide code that calls the array_max function and passes the array and its size
  // as arguments. Store the result in the variable called max_value
  max_value = array_max(arr,size_);

  std::cout << "The largest number in the array is " << max_value << "\n";
  return 0;
}
