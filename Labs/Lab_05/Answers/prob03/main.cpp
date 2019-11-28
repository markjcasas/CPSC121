#include <fstream>
#include <iostream>
#include <string>
int main() {
  int donor;
  float donation;
  std::string file;
  std::cout << "Please provide the number of donors: ";
  std::cin >> donor;

  if (donor <= 0) {
    std::cout << "You need to have at least one donor for your cause to save ";
    std::cout << "donation information.\n";
  } else {
    std::cout << "Please provide the name of the donations file: ";
    std::cin >> file;
    std::ofstream outfile;
    outfile.open(file);
    outfile << donor << '\n';
    for (int i = 1; i <= donor; i++) {
      std::cout << "Donor ";
      std::cout << i;
      std::cout << ": $";
      std::cin >> donation;
      outfile << donation << '\n';
    }
    std::cout << '\n';
    std::cout << "Thank you for donating!" << '\n';
  }
  return 0;
}
