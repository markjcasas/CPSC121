#include <iostream>

class Rectangle {
  private:
    int length_, width_;
  public:
    Rectangle(int length, int width) : length_(length), width_(width) { }
    Rectangle() : Rectangle(5, 10) { }

    int length() { return length_; }
    void set_length(int length) { length_ = length; }
    int width() { return width_; }
    void set_width(int width) { width_ = width; }
};

int main() {
  Rectangle wall1;
  Rectangle wall2(15, 23);

  std::cout << "Wall 1 length: " << wall1.length() << "\n";
  std::cout << "Wall 1 width: " << wall1.width() << "\n";
  std::cout << "Wall 2 length: " << wall2.length() << "\n";
  std::cout << "Wall 2 width: " << wall2.width() << "\n";
  return 0;
}
