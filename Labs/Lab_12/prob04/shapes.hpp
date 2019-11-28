#include <iomanip>
#include <iostream>
#ifndef SHAPES_HPP
#define SHAPES_HPP
class Shape {
  int width_, height_;
public:
  Shape() : Shape(1, 1) {}
  Shape(int width, int height) : width_(width), height_(height) {}
  void set_width(int width) { width_ = width; }
  void set_height(int height) { height_ = height; }
  int width() { return width_; }
  int height() { return height_; }
};
class Rectangle : public Shape {
public:
  Rectangle() : Shape() {}
  Rectangle(int width, int height) : Shape(width, height) {}
  int calc_area() { return height() * width(); }
};
class Triangle : public Shape {
public:
  Triangle() : Shape() {}
  Triangle(int width, int height) : Shape(width, height) {}
  int calc_area() { return height() * width() * 0.5; }
};
#endif
