#include "route.hpp"
#include <iostream>

int main() {
  int t;
  Route r[3];
  std::cout << "Welcome to TuffyTravel!" << '\n';
  std::cout << '\n';
  for (int h = 0; h < 3; h++) {
    std::cout << "Route ";
    std::cout << h + 1 << ":" << '\n';
    r[h] = create_route();
  }
  std::cout << "Please enter the time you wish to leave: ";
  std::cin >> t;
  std::cout << '\n';
  Route pick;
  pick = best_route(r, 3, t);
  std::cout << "You should probably take the " << pick.name();
  std::cout << " that leaves at " << pick.departure_time();
  std::cout << " and arrives at " << pick. arrival_time();
  std::cout << " which fits your preferred time to leave, " << t << '\n';
  return 0;
}
