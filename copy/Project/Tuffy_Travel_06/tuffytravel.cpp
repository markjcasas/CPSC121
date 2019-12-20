#include "route.hpp"
#include <fstream>
#include <iostream>

int main() {
  RouteManager main_object;
  std::cout << "Welcome to TuffyTravel!\n\n";
  action(main_object);
  std::cout << "\nThank you for using TuffyTravel!" << '\n';
  return 0;
}
