#include <cmath>
#include <iostream>
int main() {
  const float endinput = 13;
  double input;
  double sum = 0;
  const float h = 100;
  const float t = 12;
  double avg;
  std::cout << "Annual sales report" << '\n';
  std::cout << "===================" << '\n';
  std::cout << "Please provide the monthly sales for the year." << '\n';
  std::cout << '\n';
  std::cout.setf(std::ios::fixed);
  std::cout.precision(2);
  for (int i = 1; i < endinput; i++) {
    std::cout << "Month ";
    std::cout << i;
    std::cout << ": $";
    std::cin >> input;
    sum += h*input;
  }
  avg = sum/t;
  std::cout << '\n';
  std::cout << "Total sales: $";
  std::cout << std::round(sum)/h;
  std::cout << '\n';
  std::cout << "Average monthly sale: $";
  std::cout << std::round(avg)/h;
  std::cout << '\n';




  return 0;
}
