#include <iostream>

class TediousSquare {
  private:
    int side_;
  public:
    int side() const { return side_; }
    void set_side(int side) { side_ = side; }
};

class Square {
  private:
    int side_;
  public:
    Square() : side_(5) { }
    int side() const { return side_; }
    void set_side(int side) { side_ = side; }
};

int main() {
  TediousSquare lot1;
  lot1.set_side(5);

  Square lot2;

  std::cout << "Lot 1 side: " << lot1.side() << "\n";
  std::cout << "Lot 2 side: " << lot2.side() << "\n";
  return 0;
}
