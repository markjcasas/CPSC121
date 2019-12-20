#include "pair_class_template.hpp"
#include <iostream>
int main() {
  // Create an instance of `MyPair` object called `p1` using `int`
  // and passing in values `3` and `5`
  MyPair<int> p1(3,5);
  // *Start using `p1` to call methods*
  // Call the display method
  p1.display();
  std::cout << "\n";
  // Call the display_reverse method
  p1.display_reverse();
  std::cout << "\n";
  // Call the max_value method and print the value
  std::cout << p1.max_value() << "\n";
  // Call the min_value method and print the value
  std::cout << p1.min_value() << "\n";
  // Call the swap_value method;
  p1.swap_value();
  // Call the display method
  p1.display();
  std::cout << "\n";
  // Call the display_reverse method
  p1.display_reverse();
  std::cout << "\n";
  // Create an instance of `MyPair` object called `p2` using `double`
  // and passing in the values `9.7` and `6.4`
  MyPair<double> p2(9.7, 6.4);
  // *Start using `p2` to call methods*
  // Call the display method
  p2.display();
  std::cout << "\n";
  // Call the display_reverse method
  p2.display_reverse();
  std::cout << "\n";
  // Call the max_value method and print the value
  std::cout << p2.max_value() << "\n";
  // Call the min_value method and print the value
  std::cout << p2.min_value() << "\n";
  // Call the swap_value method;
  p2.swap_value();
  // Call the display method
  p2.display();
  std::cout << "\n";
  // Call the display_reverse method
  p2.display_reverse();
  std::cout << "\n";
  // Create an instance of `MyPair` object called `p3` using `char`
  // and passing in the values `a` and `z`
  MyPair<char> p3('a', 'z');
  // *Start using `p3` to call methods*
  // Call the display method
  p3.display();
  std::cout << "\n";
  // Call the display_reverse method
  p3.display_reverse();
  std::cout << "\n";
  // Call the max_value method and print the value
  std::cout << p3.max_value() << "\n";
  // Call the min_value method and print the value
  std::cout << p3.min_value() << "\n";
  // Call the swap_value method
  p3.swap_value();
  // Call the display method
  p3.display();
  std::cout << "\n";
  // Call the display_reverse method
  p3.display_reverse();
  std::cout << "\n";
  return 0;
}
