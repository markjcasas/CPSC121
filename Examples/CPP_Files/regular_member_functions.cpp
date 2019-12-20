#include <iostream>

// store in header file (e.g., square.hpp)
class Square {
  private:
    int side_;
  public:
    Square() : side_(5) { }
    Square(int side) : side_(side) { }
    int side() { return side_; }
    void set_side(int side) { side_ = side; }
    void display();
};

// store in implementation file (e.g., square.cpp)
void Square::display() {
  for (int i = 0; i < side_; i++) {
    for (int j = 0; j < side_; j++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
}

int main() {
  Square lot1;
  Square lot2(3);

  std::cout << "Lot 1 side: " << lot1.side() << "\n";
  lot1.display();
  std::cout << "Lot 2 side: " << lot2.side() << "\n";
  lot2.display();

  return 0;
}
