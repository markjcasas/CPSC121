#include <iostream>
#ifndef PAIR_CLASS_TEMPLATE_HPP
#define PAIR_CLASS_TEMPLATE_HPP
template <class T>
class MyPair {
  T value1_;
  T value2_;
public:
  MyPair(T value1, T value2) : value1_(value1), value2_(value2) {}
  void set_value1(T value1) { value1_ = value1; }
  void set_value2(T value2) { value2_ = value2; }
  T value1() { return value1_; }
  T value2() { return value2_; }
  void display() { std::cout << '[' << value1_ << ", " << value2_ << "]"; }
  void display_reverse() { std::cout << '[' << value2_ << ", " << value1_ << "]"; }
  T max_value() {
    if (value1_ > value2_) { return value1_; }
    else { return value2_; }
  }
  T min_value() {
    if (value1_ < value2_) { return value1_; }
    else { return value2_; }
  }
  void swap_value() {
    T tmp = value1_;
    value1_ = value2_;
    value2_ = tmp;
  }
};
#endif
