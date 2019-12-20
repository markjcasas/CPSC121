#include "discount.hpp"
#include <iomanip>
#include <iostream>

int main() {
  double prices[5];
  std::cout << std::setprecision(2) << std::fixed;
  std::cout << "Please enter the prices of the five items you purchased\n";
  for (int i = 0; i < 5; i++) {
    std::cout << "Item " << i + 1 << " price: $";
    std::cin >> prices[i];
  }

  double total;
  total = discounted_sum(prices, 5);
  // Call your discounted_sum function and pass in the array of prices
  // with the number of elements it contains. Store its results in the
  // total variable.

  std::cout << "Total price: $" << total << "\n";

  return 0;
}



//Create a function called discounted_sum. This function receives two parameters,
//an array that contains item prices, and the total number of items inside that array.
//The function will go through each price in the array and compute the total price.
//However, whenever a price is over $50.00, that price will get a 5% discount.
//Take note, it is only that item that gets the discount, not the total amount.
//The function should return the total price.
//Even though the main function uses an array of five elements, your
//discounted_sum function should be able to handle any number of elements.
