#include "car.hpp"
#include <iomanip>
#include <iostream>

int main() {
int a = 3;
Car cars[a];
  for (int i = 0; i < a; i++) {
    std::string n;
    double p;
    int m;
    std::cout << "Car #" << i + 1 << "\n";
    std::cout << "Please enter the name: ";
    std::getline(std::cin, n);
    cars[i].set_name(n);
    std::cout << "Please enter the milage: ";
    std::cin >> m;
    cars[i].set_mileage(m);
    std::cout << "Please enter the price: $";
    std::cin >> p;
    cars[i].set_price(p);
    std::cin.ignore();
    // Set the name, price and mileage of the corresponding Car
    // object based on user input.
  }

  // Create a Car object whose name is lowest.
  // Call the lowerst_price function to get the Car object with the lowest price from
  // the array then assign it to the Car object called lowest.
  Car lowest;

  lowest = lowest_price(cars, a);

  std::cout << std::fixed << std::setprecision(2);

  std::cout << "\nThe car with the lowest price is " << lowest.name();
  // Display the name of the car with the lowest price (use the lowest variable)

  std::cout << " with a mileage of " << lowest.mileage();
  // Display the mileage of the car with the lowest price (use the lowest
  // variable)

  std::cout << " and a price of $" << lowest.price();

  // Display the price of the car with the lowest price (use the lowest
  // variable)

  std::cout << "\n";

  return 0;
}
