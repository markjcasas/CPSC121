#include <fstream>
#include <iostream>
#include <string>
int main() {
  std::string file;
  std::cout << "Please provide the file name for your phone book: ";
  std::getline(std::cin, file);
  std::ifstream infile;
  infile.open(file);
  if (infile.is_open()) {
    infile.seekg(0,infile.end);
    int size = infile.tellg();
    infile.seekg(0, infile.beg);
    if (size != 0) {
      std::string line;
      for (int i = 1; std::getline(infile, line); i++) {
        std::cout << "Contact ";
        std::cout << i;
        std::cout << ":" << '\n';
        std::cout << "Name: ";
        std::cout << line << '\n';
          while (std::getline(infile, line)) {
            std::cout << "Number: " << line << '\n';
            break;
          }
      }
    } else {
      std::cout << "Phone book does not contain any contacts!" << '\n';
    }
    infile.close();
  } else {
    std::cout << "Invalid phonebook file!" << '\n';
  }
  return 0;
}
