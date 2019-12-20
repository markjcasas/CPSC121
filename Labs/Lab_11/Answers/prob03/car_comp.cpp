#include "car_comp.hpp"
#include <iostream>

void Car::print() {
  std::cout << "The name of the car is: " << identity_.name()
            << "\nThe id of the car is: " << identity_.id()
            << "\nThe license plate of the car is: " << identity_.license_plate()
            << "\nThe release date of the car is: " << release_date_.month()
            << '/' << release_date_.day() << '/' << release_date_.year() << '\n';
}
