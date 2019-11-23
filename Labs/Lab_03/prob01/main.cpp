#include<iostream>

int main() {
  std::cout << "Welcome to HoliDeals at the Movies!" << '\n';
  std::cout << "Tickets tonight can only be bought in pairs" << '\n';
  std::cout << "Here are our movie ticket deals:" << '\n';
  std::cout << '\n';
  const float c = 10;
  const float m = 65;
  const float y = 13;
  const float d = 21;
  const float a = 15;
  const float s = 10;
  float u;
  float i;
  float f;
  float p;
  float j;
  std::cout << "Children - $10.00" << '\n';
  std::cout << "Young Adults - $13.00" << '\n';
  std::cout << "Adults - $15.00" << '\n';
  std::cout << "Seniors - $10.00" << '\n';
  std::cout << '\n';
  std::cout << "Please enter the age of the person for the first guest: ";
  std::cin >> u;
  std::cout << "Please enter the age of the person for the second guest: ";
  std::cin >> i;
  std::cout << '\n';
  if (u < y) {
    f = c;
  } else if ((y <= u) && (u < d)) {
    f = y;
  } else if ((d <= u) && (u < m)){
    f = a;
  } else {
    f = s;
  }
  if (i < y) {
    p = c;
  } else if ((y <= i) && (i < d)) {
    p = y;
  } else if ((d <= i) && (i < m)){
    p = a;
  } else {
    p = s;
  }
  j=f+p;
  std::cout.setf(std::ios::fixed);
  std::cout.precision(2);
  std::cout << "The Subtotal for the ticket cost is: $";
  std::cout << j << '\n';
  return 0;
}
