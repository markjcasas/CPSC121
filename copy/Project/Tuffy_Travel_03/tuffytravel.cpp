#include "route.hpp"
#include <iostream>

int main() {
  Route route_array[100];
  int count = 0;
  std::cout << "Welcome to TuffyTravel!" << '\n';
  action(route_array, count);
  std::cout << "\nThank you for using TuffyTravel!" << '\n';
  return 0;
}
