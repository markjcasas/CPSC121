#include <fstream>
#include <iostream>
#include <string>
int main() {
  std::string name;
  std::cout << "Please provide the file name for your phone book: ";
  std::getline(std::cin, name);
  std::string contact;
  std::string number;
  std::ofstream outfile;
  outfile.open(name);
    for (int i = 1; contact != "Done"; i++) {
      std::cout << "Contact ";
      std::cout << i;
      std::cout << ": " << '\n';
      std::cout << "Please provide the name: ";
      std::getline(std::cin, contact);
      if (contact != "Done" ) {
        outfile << contact << '\n';
        std::cout << "Please provide their number: ";
        std::getline(std::cin, number);
        std::cout << '\n';
        outfile << number << '\n';
      } else {
        outfile.close();
        std::cout << '\n';
        std::cout << "Saving phonebook into ";
        std::cout << name;
        std::cout << '\n';
        std::cout << "Done!" << '\n';
      }
    }
  return 0;
}
