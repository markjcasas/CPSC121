#include <iostream>

int main() {
  int vals[] = {4, 7, 11};
  std::cout << "int vals[] = {4, 7, 11}\nvals: " << vals << "\n"; // why is this an address???
  std::cout << "vals[0]: " << vals[0] << "\n";
  std::cout << "*vals: " << *vals << "\n"; // the plot thickens ...
  std::cout << "vals + 1: " <<  vals + 1 << "\n";
  std::cout << "*(vals + 1): " <<  *(vals + 1) << "\n"; // @.@
  
  int* ptr_vals = vals; // take note there is no &
  std::cout << "int* ptr_vals = vals (no &)\nptr_vals[0]: " <<  ptr_vals[0] << "\n"; // only works on pointers to arrays
  
  return 0;
}







