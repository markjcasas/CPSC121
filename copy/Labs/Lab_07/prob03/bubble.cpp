#include "bubble.hpp"
#include <iomanip>
#include <iostream>

void Bubble::set_radius(double radius) {
  radius_ = radius;
}

double Bubble::radius() {
  return radius_;
}

double Bubble::volume() {
  double constants = 4.0 * 3.1415 / 3.0;
  return constants * radius_ * radius_ * radius_;
}

Bubble combine_bubble(Bubble x, Bubble y) {
  Bubble combine;
  double combine_radius = x.radius() + y.radius();
  combine.set_radius(combine_radius);
  return combine;
}
