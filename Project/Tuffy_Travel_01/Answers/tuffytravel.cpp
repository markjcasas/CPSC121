#include <iostream>

int main() {
  std::string route[3];
  int departure_time[3];
  int time_to_leave;
  std::string preffered_route;
  int preffered_time;
  std::cout << "Welcome to TuffyTravel!\n\n";
  std::cout << "Please enter the name of the 1st route: ";
  std::getline(std::cin,route[0]);
  std::cout << "Please enter the departure time of the 1st route: ";
  std::cin >> departure_time[0];
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << '\n';
  std::cout << "Please enter the name of the 2nd route: ";
  std::getline(std::cin,route[1]);
  std::cout << "Please enter the departure time of the 2nd route: ";
  std::cin >> departure_time[1];
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << '\n';
  std::cout << "Please enter the name of the 3rd route: ";
  std::getline(std::cin,route[2]);
  std::cout << "Please enter the departure time of the 3rd route: ";
  std::cin >> departure_time[2];
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << '\n';
  std::cout << "Please enter the time you wish to leave: ";
  std::cin >> time_to_leave;
  std::cout << '\n';
  if (departure_time[0] - time_to_leave > 0 && departure_time[0] < departure_time[1] && departure_time[0] < departure_time[2]) {
    preffered_time = departure_time[0];
    preffered_route = route[0];
  } else if (departure_time[1] - time_to_leave > 0 && departure_time[1] < departure_time[2]) {
    preffered_time = departure_time[1];
    preffered_route = route[1];
  } else {
    preffered_time = departure_time[2];
    preffered_route = route[2];
  }
  std::cout << "You should probably take the " << preffered_route << " route that leaves at " << preffered_time << '\n';
  return 0;
}
