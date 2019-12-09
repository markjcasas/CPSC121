#include "car.hpp"
#include <iomanip>
#include <iostream>

bool ElectricCar::is_empty() {
  if (battery_percentage_ > 0) {
    return false;
  } else {
    return true;
  }
}

void ElectricCar::drive(double speed) {
  if (battery_percentage_ > 0) {
    Car::drive(speed);
    battery_percentage_ -= speed / 4;
    if (battery_percentage_ <= 0) {
      Car::drive(0);
    }
  }
}

bool GasolineCar::is_empty() {
  if (tank_ > 0) {
    return false;
  } else {
    return true;
  }
}

void GasolineCar::drive(double speed) {
  if (tank_ > 0) {
    Car::drive(speed);
    tank_ -= speed / mpg_;
    if (tank_ <= 0) {
      Car::drive(0);
    }
  }
}
