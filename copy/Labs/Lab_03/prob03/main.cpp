#include <iostream>
int main() {
  float w;
  float t;
  float p;
  float s;
  const float f = 40;
  const float o = 25;
  const float v = 2;
  const float g = 1.5;
  const float d = 65;
  std::cout << "Hourly wage: ";
  std::cin >> w;
  std::cout << "Hours worked: ";
  std::cin >> t;
  if (t <= f) {
    s = w*t;
  } else if ((f < t) && (t <= d)) {
    s = w*f+(t-f)*w*g;
  } else {
    s = (w*f)+(w*g*o)+((t-d)*w*v);
  }
  std::cout.setf(std::ios::fixed);
  std::cout.precision(2);
  std::cout << "Total Salary Owed: $";
  std::cout << s;
  std::cout << '\n';

  return 0;
}
