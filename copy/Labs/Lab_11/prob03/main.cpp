#include "car_comp.hpp"
#include <iostream>
int main() {
  // Create four instances of a `Car` object using the different
  // constructors
  Car c1;
  // Create a Car object using the default constructor and call it c1
  Identifier i1("Honda", 3, "7B319X4");
  // Create an `Identifier` object with the following information:
  // Name - Honda, ID - 3, License plate - 7B319X4
  Car c2(i1);
  // Create a `Car` object using the constructor that accepts an `Identifier`
  // object and pass in the `Identifier` object you just created; call it c2
  Date d1(4, 11, 2018);
  // Create a `Date` object with the following information:
  // Day - 4, Month - 11, Year - 2018
  Car c3(d1);
  // Create a `Car` object using the constructor that accepts a `Date` object
  // and pass in the `Date` object you just created; call it c3
  Car c4(i1, d1);
  // Create a `Car` object using the constructor that accepts an `Identifier`
  // and `Date` object then pass in the `Identifier` and `Date` objects you
  // created previously; call it c4

  // Call the print member function for `c1`
  c1.print();
  std::cout << "\n";

  // Call the print member function for `c2`
  c2.print();
  std::cout << "\n";

  // Call the print member function for `c3`
  c3.print();
  std::cout << "\n";

  // Call the print member function for `c4`
  c4.print();
  std::cout << "\n";

  // Create an instance of the `Identifier` object using the default constructor
  Identifier i2;
  // Create an instance of the `Date` object using the default constructor
  Date d2;
  // Call the `set_identity` member function on `c4` and pass in the identifier you just created
  c4.set_identity(i2);
  // Call the `set_release_date` member function on `c4` and pass in the date object you just created
  c4.set_release_date(d2);
  // Call the print member function for `c4`
  c4.print();
  return 0;
}
