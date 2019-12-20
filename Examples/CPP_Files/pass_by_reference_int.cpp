#include <iostream>

void increment_by_five(int &base_value) {
  base_value += 5;
}

int main() {
  int num = 23;
  std::cout << "Number: " << num << "\n";
  increment_by_five(num);
  std::cout << "Number: " << num << "\n";
  return 0;
}
