#include <iomanip>
#include <iostream>
#include <vector>
#ifndef STATISTICS_CALCULATOR_HPP
#define STATISTICS_CALCULATOR_HPP
class StatisticsCalculator {
  std::vector<double> data_set_;
public:
  void add_data(double data) { data_set_.push_back(data); }
  double data_at(int index) { return data_set_[index]; }
  int size_of_data() { return data_set_.size(); }
  double mean();
};
#endif