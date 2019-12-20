#include <iomanip>
#include <iostream>
int main() {
  int count = 0;
  int number;
  double game[number];
  std::cout << "Please input the number of game(s) you want to purchase: ";
  std::cin >> number;
  if (number > 0) {
    double sum = 0;
    double while_sum = 0;
    double purchase_price = 0;
    double discount = 0;
    for (int i = 0; i < number; i++) {
      std::cout << "Enter the price of game " << i + 1 << ": $";
      std::cin >> game[i];
      sum += game[i];
    }
    while (game[count] < 60 && count < number) {
      while_sum += game[count];
      count++;
    }
    if (while_sum == sum) {
      purchase_price = sum;
    } else {
      purchase_price = 0.8 * sum;
      discount = 0.2 * sum;
    }
    std::cout << std::fixed << std::setprecision(2) << "The total cost of "
              << number << " game(s) is $" << purchase_price << "\nYou saved $"
              << discount << '\n';
  } else {
    std::cout << "You need to purchase at least 1 game. Please rerun the program." << '\n';
}
  return 0;
}
