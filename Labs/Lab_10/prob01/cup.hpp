#include <iomanip>
#include <iostream>
#ifndef CUP_HPP
#define CUP_HPP
class Cup {
  std::string drink_type_;
  double fluid_oz_;
public:
  Cup() :drink_type_("Water"),fluid_oz_(16.0) {}
  Cup(std::string drink_type, double fluid_oz) : drink_type_(drink_type), fluid_oz_(fluid_oz) {}

  void set_drink_type(std::string &drink_type) {
    drink_type_ = drink_type;
  }
  void set_fluid_oz(double fluid_oz) {
    fluid_oz_ = fluid_oz;
  }
  std::string drink_type() {
    return drink_type_;
  }
  double fluid_oz() {
    return fluid_oz_;
  }
  void drink(double drinkamount) {
    if (drinkamount >= fluid_oz_) {
      fluid_oz_ = 0;
    } else {
      fluid_oz_ -= drinkamount;
    }
  }
  void refill(double refillamount) {
    fluid_oz_ += refillamount;
  }
  void new_drink(std::string newdrink, double newamount) {
    drink_type_ = newdrink;
    fluid_oz_ = newamount;
  }
  void empty() {
    fluid_oz_ = 0;
    drink_type_ = "nothing";
  }
};
#endif
