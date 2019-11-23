#include <iostream>
#include <string>

int main() {
  std::string name = "olive";
  std::cout << name << "\n";
  name.insert(0, "taco");
  std::cout << name << "\n";
  int loc = name.find("cool");
  std::cout << "Cool found in: " << loc << "\n";
  std::cout << name.substr(2, 4) << "\n";
  return 0;
}
