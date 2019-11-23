#include <iostream>

class Square {
  private:
    int side_;
  public:
    Square() : side_(5) { }
    Square(int side) : side_(side) { }
    int side() { return side_; }
    void set_side(int side) { side_ = side; }
};

int main() {
  Square lot1;
  Square lot2(10);

  std::cout << "Lot 1 side: " << lot1.side() << "\n";
  std::cout << "Lot 2 side: " << lot2.side() << "\n";
  return 0;
}
