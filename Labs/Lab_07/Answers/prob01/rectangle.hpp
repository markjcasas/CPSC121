#include <iostream>
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
class Rectangle {
  int length_;
  int width_;
public:
  void set_length(int l);
  void set_width(int w);
  int length();
  int width();
  int area();
};
Rectangle longest_rectangle(Rectangle x, Rectangle y);
#endif
