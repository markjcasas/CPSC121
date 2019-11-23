#include <iostream>
#ifndef BUBBLE_HPP
#define BUBBLE_HPP
class Bubble {
  double radius_;
public:
  void set_radius(double radius);
  double radius();
  double volume();
};
Bubble combine_bubble(Bubble a, Bubble b);
#endif
