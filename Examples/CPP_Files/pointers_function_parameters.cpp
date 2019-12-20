#include <iostream>
using namespace std;

void square(int num) {    
    num = num * num;
}

void square_with_pointer(int* ptr_num) {    
    *ptr_num = *ptr_num * *ptr_num;
}

int main() {
  int num = 5;
  std::cout << "num is " << num << endl;
  std::cout << "Calling square()" << endl;
  square(num);
  std::cout << "num is " << num << endl;
  
  std::cout << "====" << endl;
  std::cout << "num is " << num << endl;
  std::cout << "Calling square_with_pointer()" << endl;
  square_with_pointer(&num);
  std::cout << "num is " << num  << endl;
  return 0;
}
