#include <iostream>

int sum(int num1, int num2){    
  int sum_of_numbers = num1 + num2;
  return sum_of_numbers;
  
  // you can also return an expression to make
  // code shorter
  // return num1 + num2;
}


int main() {
  std::cout << "Calling sum()\n";
  int val1 = 5;
  int val2 = 6;
  int sum_of_vals = sum(val1, val2);
  std::cout << "Sum of " << val1 << " + " << val2 << " is "
            << sum_of_vals << "\n";
  std::cout << "Done calling sum()\n";
  return 0;
}
