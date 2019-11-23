#include <iostream>
int main() {
  int count = 0;
  while(count < 5) {
    count++;
    if(count == 3) {
      break;
    }
    std::cout << count << " ";
  }
  return 0;
}
