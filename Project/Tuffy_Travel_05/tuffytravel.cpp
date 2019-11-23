#include "route.hpp"
#include <fstream>
#include <iostream>

int main() {
  Route main_array[100];
  int main_number = 0;
  std::cout << "Welcome to TuffyTravel!" << '\n';
  action(main_array, main_number);
  std::cout << "\nThank you for using TuffyTravel!" << '\n';
  return 0;
}
