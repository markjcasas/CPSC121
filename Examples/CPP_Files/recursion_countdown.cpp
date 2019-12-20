#include <iostream>

void count_down(int num) {     
  if (num == 0) {
      std::cout << "Blastoff!\n";
  } else { 
      std::cout << num << ". . .";
      count_down(num-1); // recursive
   }                    // call
}

int main() {
  count_down(5);
  return 0;
}
