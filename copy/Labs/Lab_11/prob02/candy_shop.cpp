#include "candy_shop.hpp"
#include <iomanip>
#include <iostream>

void CandyShop::add(Candy add_object) {
  if (size_ < 10) {
    candy_[size_] = add_object;
    size_++;
  } else {
    std::cout << "Error, bag is full!" << '\n';
  }
}

void CandyShop::print() {
  std::cout << "Contents of bag:" << '\n';
  for (int i = 0; i < size_; i++) {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << "Candy " << i + 1 << '\n';
    std::cout << "   Brand: " << candy_[i].brand();
    std::cout << "\n   Flavor: " << candy_[i].flavor();
    std::cout << "\n   Cost: " << candy_[i].cost() << '\n';

  }
}

double CandyShop::total_price() {
  double sum = 0;
  for (int j = 0; j < size_; j++) {
    sum += candy_[j].cost();
  }
  return sum;
}
