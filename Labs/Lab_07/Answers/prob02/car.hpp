#include <iostream>
#ifndef CAR_HPP
#define CAR_HPP
class Car {
  std::string name_;
  double price_;
  unsigned int mileage_;
public:
  void set_name(const std::string &name) { name_ = name ; }
  void set_price(double price);
  void set_mileage(unsigned int mileage);
  std::string name();
  double price();
  unsigned int mileage();
};
Car lowest_price(Car x[], int y);
#endif
