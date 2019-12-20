#include <iostream>

// Function with no return and no parameter
void draw_line() {
  std::cout << "================\n";
}

// Function with no return, but with a parameter
void write(std::string text) {
  std::cout << text << "\n";
}

// Function with a return, but no parameter
// It generates and returns a random number between 0 and 100
int rand_num() {
  int random_number = rand() % 101;
}

// Function with a return and with a parameter
bool guess_number(int guess) {
  // Calling a function with a return, but no parameter
  int the_number = rand_num();
  if (guess == the_number) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int user_guess = 0;
  
  // Calling functions with no return and no parameters
  draw_line();
  write("Guess my number!");
  draw_line();
  
  // Calling functions with no return, but with a parameter
  write("Enter your guess (number between 0 and 100)");
  std::cin >> user_guess;
  // assume user types in 30
  user_guess = 30;
  
  // Calling functions with a return and with a parameter
  bool correct_guess = guess_number(user_guess);
  if (correct_guess) {
    write("That's correct!");
  } else {
    write("That's incorrect :(");
  }
  
  draw_line();
  write("Goodbye");
  draw_line();
  return 0;
}
