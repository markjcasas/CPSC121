#include "rectangle.hpp"
#include <iostream>

void Rectangle::set_length(int length) {
  length_ = length;
}

void Rectangle::set_width(int width) {
  width_ = width;
}

int Rectangle::length() {
  return length_;
}

int Rectangle::width() {
  return width_;
}

int Rectangle::area() {
  return length_ * width_;
}

Rectangle longest_rectangle(Rectangle r1, Rectangle r2) {
  Rectangle l;
  if (r1.length() > r2.length()) {
    l.set_length(r1.length());
    l.set_width(r1.width());
  } else {
    l.set_length(r2.length());
    l.set_width(r2.width());
  }
  return l;
}
