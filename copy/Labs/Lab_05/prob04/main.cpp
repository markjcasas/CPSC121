#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
int main() {
  std::string file;
  std::cout << "Please provide the file name for your donation file: ";
  std::cin >> file;
  std::ifstream infile;
  infile.open(file);
  if (infile.is_open()) {
    int number;
    infile >> number;
    infile.seekg(1, infile.beg);
    float line;
    float sum = 0;
    for (int i = 1; i <= number; i++) {
      std::cout << "Donation " << i << ": $";
      infile >> line;
      std::cout.setf(std::ios::fixed);
      std::cout.precision(2);
      std::cout << line << '\n';
      sum += line;
    }
    infile.close();
    std::cout << "Total donation: $" << sum << '\n';
  } else {
    std::cout << "Invalid donation file!\n";
  }
  return 0;
}
