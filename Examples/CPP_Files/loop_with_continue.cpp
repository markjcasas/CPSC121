#include <iostream>

int main() {
  int count = 0;
  while (count < 5) {
    count++;
    if (count == 3) {
      continue;
    }
    std::cout << count << " ";
  }
  return 0;
}
