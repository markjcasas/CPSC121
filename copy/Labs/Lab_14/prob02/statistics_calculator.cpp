#include "statistics_calculator.hpp"
#include <iomanip>
#include <iostream>
#include <vector>

double StatisticsCalculator::mean() {
  double sum = 0;
  if (data_set_.empty()) {
    return sum;
  } else {
    for (int i = 0; i < size_of_data(); i++) {
      sum += data_set_[i];
    }
    return sum / size_of_data();
  }
}
