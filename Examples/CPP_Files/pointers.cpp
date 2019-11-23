#include <iostream>

int main() {
  int num = 10;
  std::cout << "The address of num in the memory is: " << &num << "\n";

  int* ptr_num = &num;
  std::cout << "The value of ptr_num is: " << ptr_num << "\n";

  // * is the indirection operator that "follows" the link
  // to the address pointed to by the pointer*
  std::cout << "The value of the address pointed to by ptr_num is: " << *ptr_num << "\n";

  num = 20;
  std::cout << "The value of the address pointed to by ptr_num is: " << *ptr_num << "\n";

  *ptr_num = 30;
  std::cout << "The value of the address pointed to by ptr_num is: " << *ptr_num << "\n";
  std::cout << "The value of num is: " << num << "\n";

  int num2 = 1000;
  ptr_num = &num2;
  std::cout << "The value of ptr_num is: " << ptr_num << "\n";
  std::cout << "The value of the address pointed to by ptr_num is: " << *ptr_num << "\n";

  return 0;
}
