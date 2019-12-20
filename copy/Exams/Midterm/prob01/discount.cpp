#include "discount.hpp"
#include <iomanip>
#include <iostream>

double discounted_sum(double price[], int count) {
  double sum = 0;
  for (int i = 0; i < count; i++) {
    if (price[i] < 50) {
      sum += price[i];
    } else {
      sum += 0.95 * price[i];
    }
  }
  return sum;
}
