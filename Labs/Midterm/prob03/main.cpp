#include <fstream>
#include <iostream>

int main() {
  std::string full_name;
  int cwid;
  std::ifstream input_file;
  input_file.open("students.txt");

  for (int i = 0; i < 3; i++) {
    std::getline(input_file, full_name);
    input_file >> cwid;
    std::cout << "\nName: " << full_name << "\nCWID: " << cwid << '\n';
    input_file.seekg(1, input_file.cur);
  }
  input_file.close();
  std::cout << '\n';
  return 0;
}
