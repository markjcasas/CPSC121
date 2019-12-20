#include "organization.hpp"
#include <iostream>
// TODO: Provide implementations here, if needed
void Person::display() {
  std::cout << name_ << '\n' << address_ << '\n' << phone_number_;
}

std::string Organization::get_position(std::string name) {
  if (name == president_.name()) {
    return "president";
  } else if (name == vice_president_.name()) {
    return "vice president";
  } else if (name == treasurer_.name()) {
    return "treasurer";
  } else {
    return "not an officer";
  }
}
