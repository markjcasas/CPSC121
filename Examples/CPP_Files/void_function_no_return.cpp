#include <iostream>

void print_banner() {    
  std::cout << "----------------\n";
  std::cout << "Tuffy accounting\n";
  std::cout << "----------------\n";
}


int main() {
  double balance = 0, deposit = 0;
  print_banner();
  std::cout << "Please enter a starting balance: ";
  std::cin >> balance;
  // Pythontutor doesn't allow user input so let's
  // assume the user typed in 300 and presses enter
  balance = 300;
  std::cout << "\n";
  while (balance < 1000) {
    std::cout << "Please enter a deposit amount: ";
    std::cin >> deposit;
    // Pythontutor doesn't allow user input so let's
    // assume the user typed in 250 and presses enter
    deposit = 250; 
    std::cout << "\n";
    
    balance += deposit;
  }
  std::cout << "Congratulations, your balance has reached over $100! You now "
               "qualify for an additional 0.1% interest rate.\n";
  print_banner();
  return 0;
}
