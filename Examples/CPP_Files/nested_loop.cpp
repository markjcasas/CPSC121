#include <iostream>

int main() {
  for (int row = 1; row <= 3; row++) {                           
    for (int col = 1; col <= 3; col++) {  
      std::cout << row * col << "\n";
    }
  }

  return 0;
}
