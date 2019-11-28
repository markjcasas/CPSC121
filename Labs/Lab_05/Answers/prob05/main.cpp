#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
int main() {
  std::string file;
  std::cout << "Please provide the file name for your report file: ";
  std::cin >> file;
  std::ifstream infile;
  infile.open(file);
  if (infile.is_open()) {
    int number;
    float amount;
    infile.seekg(0, infile.beg);
    std::cout << "Please provide the number of months to consolidate: ";
    std::cin >> number;
    if (number == 1) {
      for (int i = 1; infile >> amount; i++) {
        std::cout << "Month " << i << " sales : $";
        std::cout.setf(std::ios::fixed);
        std::cout.precision(2);
        std::cout << amount << '\n';
      }
    } else if (number == 2) {
      float sum1 = 0;
      float sum2 = 0;
      for (int i = 1; i <= 2; i++) {
        infile >> amount;
        sum1 += amount;
      }
      std::cout << "Month 1 2 sales: $" << sum1 << '\n';
      for (int i = 0; infile >> amount; i++) {
        sum2 += amount;
      }
      std::cout << "Month 3 4 sales: $" << sum2 << '\n';
    } else if (number == 3) {
      float sum = 0;
      for (int i = 1; i <= 3; i++) {
        infile >> amount;
        sum += amount;
      }
      std::cout << "Month 1 2 3 sales: $" << sum << '\n';
    } else if (number == 4) {
      float sum = 0;
      while (infile >> amount) {
        sum += amount;
      }
      std::cout << "Month 1 2 3 4 sales: $" << sum << '\n';
    }
    infile.close();
  } else {
    std::cout << "Invalid report file!\n";
  }
  return 0;
}
