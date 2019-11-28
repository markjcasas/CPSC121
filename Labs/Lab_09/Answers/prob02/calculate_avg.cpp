#include "calculate_avg.hpp"
#include <iomanip>
#include <iostream>
double calculate_avg(double* avg, int number) {
  if (number == 0) {
    return 0;
  } else {
    double sum = 0;
    for (int j = 0; j < number; j++) {
      sum += *(avg + j);
    }
    return sum / number;
  }
}
