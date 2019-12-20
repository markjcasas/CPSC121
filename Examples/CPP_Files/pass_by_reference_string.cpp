#include <iostream>

void decorate(std::string &text) {
  text = "-o-o-o-o-o-o-o-o-o-o\n" + text + "\n-o-o-o-o-o-o-o-o-o-o\n";
}

int main() {
  std::string my_string = "Hello world!";
  std::cout << my_string << "\n\n";
  decorate(my_string);
  std::cout << my_string << "\n";
  return 0;
}
