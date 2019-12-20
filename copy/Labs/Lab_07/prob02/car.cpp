#include "car.hpp"
#include <iomanip>
#include <iostream>

void Car::set_price(double price) {
  price_ = price;
}

void Car::set_mileage(unsigned int mileage) {
  mileage_ = mileage;
}

std::string Car::name() {
  return name_;
}

double Car::price() {
  return price_;
}

unsigned int Car::mileage() {
  return mileage_;
}


Car lowest_price(Car x[], int y) {
  Car l = x[0];
  for (int j = 1; j < y; j++) {
    if (l.price() > x[j].price()) {
        l = x[j];
      }
    }
    return l;
  }
