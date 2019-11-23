#include <iostream>

void arr_manip(int* vals) {
  vals[0] = 2;
  *(vals + 1) = 4;
  vals[2] = 8;
}

int main() {
  int vals[3] = {1, 2, 3};
  std::cout << "Values: ";
  for(int i = 0; i < 3; i++) {
    std::cout << vals[i] << " ";
  }
  std::cout << "\nManipulating values ...\n";
  arr_manip(vals);
  std::cout << "Values: ";
  for(int i = 0; i < 3; i++) {
    std::cout << vals[i] << " ";
  }
  std::cout << '\n';
  return 0;
}
