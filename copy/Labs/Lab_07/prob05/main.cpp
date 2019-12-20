#include "get_longest_string.hpp"
#include <iostream>

int main() {
  const int ARRAY_SIZE = 5;
  String string[ARRAY_SIZE];
  std::string input;
  std::string array[ARRAY_SIZE];
  // Create an array called inputs that can store 5 string values

  for (int i = 0; i < ARRAY_SIZE; i++) {
    std::cout << "Please enter string #" << i + 1 << ": ";
    std::getline(std::cin, input);
    string[i].set_str(input);
    array[i] = string[i].str();
  }
  std::string longest = get_longest_string(array, ARRAY_SIZE);
      // Store the user's input into the right location in the array


  // Call the get_longest_string function and store the longest string from the
  // array into the variable called longest

  std::cout << "The longest string is: " << longest << std::endl;

  return 0;
}
