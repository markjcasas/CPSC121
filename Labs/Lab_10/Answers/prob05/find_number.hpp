#include <iostream>
#ifndef FIND_NUMBER_HPP
#define FIND_NUMBER_HPP
class Numbers {
  int* values_;
  int capacity_;
  void init();
public:
  int capacity() {
    return capacity_;
  }
  void display_array();
  void find_number(int number);
  Numbers() : Numbers(10) { init(); }
  Numbers(int capacity) :values_(new int[capacity]), capacity_(capacity) { init(); }
  ~Numbers() {
    delete[] values_;
    values_ = nullptr;
  }
};
#endif
