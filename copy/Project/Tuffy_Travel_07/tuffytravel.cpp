#include "route.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
int main() {
  RouteManager object;
  std::cout << "Welcome to TuffyTravel!\n\n";
  tuffy_travel(object);
  std::cout << "\nThank you for using TuffyTravel!" << '\n';
  return 0;
}
