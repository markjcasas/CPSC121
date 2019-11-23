#include <iostream>
#include <cstdio>
#include <cmath>
int main() {
  char u;
  float i;
  char g;
  const float a = 0.1;
  const float b = 0.05;
  const float c = 0.02;
  const float n = 0;
  const float h =100;
  char y;
  char r;
  float t;
  std::cout << "Please enter type of card ('g' = green, 'y' = yellow, 'r' = red): ";
  std::cin >> u;
  std::cout << "Please enter amount of money spent: $";
  std::cin >> i;
  if (u == 'g') {
    t = i * a;
  } else if (u == 'y') {
    t = i * b;
  } else if (u == 'r') {
    t = i* c;
  } else {
    t = n;
  }
  if (t == n) {
    std::cout << "Invalid card type.";
  } else {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::cout << "Amount of cash back received: $";
    std::cout << round(t*h)/h;
  }
  std::cout << '\n';
  return 0;
}
