#include <iostream>
int main() {
  int u;
  std::cout << "Thank you for applying for the Tuffy Credit card. Please enter your credit score." << '\n';
  std::cout << "Credit Score: ";
  std::cin >> u;
  if ((0 <= u) && (u <= 579)) {
    std::cout << "Unfortunately, you are ineligible for Tuffy credit cards at the moment. Please try again at a later date." << '\n';
    std::cout << "Thank you for using our program, please come again!";
  } else if ((580 <= u) && (u <= 669)) {
    std::cout << "You are eligible for the Silver Tuffy Card." << '\n';
    std::cout << "Thank you for using our program, please come again!";
  } else if ((670 <= u) && (u <= 799)) {
    std::cout << "You are eligible for the Gold Tuffy Card." << '\n';
    std::cout << "Thank you for using our program, please come again!";
  } else if ((800 <= u) && (u <= 850)) {
    std::cout << "You are eligible for the Platinum Tuffy Card." << '\n';
    std::cout << "Thank you for using our program, please come again!";
  } else {
    std::cout << "That is an invalid credit score. Please run the program again and provide a valid credit score.";
  }
  std::cout << '\n';
  return 0;
}
