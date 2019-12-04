#include <iostream>
class Artist {
  public:
    virtual void draw(const std::string& text) const {
      std::cout << text << "\n";
    }
};
class Amanda : public Artist {
  public:
    void draw(const std::string& text) const override {
      std::cout << "-------------\n";
      std::cout << text << "\n";
      std::cout << "-------------\n";
    }
};
class Zach : public Artist {
  public:
    void draw(const std::string& text) const override {
      std::cout << "[[[[" << text << "]]]]\n";
    }
};

void display(Artist* writer, const std::string& text) {
  writer->draw(text);
}
int main() {
  Amanda a;
  Zach z;
  display(&a, "Hello world");
  display(&z, "I love C++");
  return 0;
}
