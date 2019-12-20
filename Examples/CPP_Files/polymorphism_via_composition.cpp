#include <iostream>
class Artist {
  public:
    virtual void draw(const std::string& text) const {
      std::cout << text << "\n";
    }
};
class Evelyn : public Artist {
  public:
    void draw(const std::string& text) const override {
      std::cout << "--------------------------\n";
      std::cout << text << "\n";
      std::cout << "--------------------------\n";
    }
};
class Aya : public Artist {
  public:
    void draw(const std::string& text) const override {
      std::cout << "==*==*==*==*==*==*==*==*\n";
      std::cout << text << "\n";
      std::cout << "==*==*==*==*==*==*==*==*\n";
    }
};
class Marcus : public Artist {
  public:
    void draw(const std::string& text) const override {
      std::cout << "[[[[" << text << "]]]]\n";
    }
};

void display(Artist* decorator, const std::string& text) {
  decorator->draw(text);
}

class Car {
  private:
    std::string make_;
    std::string model_;
    Artist* decorator_;
  public:
    Car(const std::string& make, const std::string& model,
        Artist* decorator)
        : make_(make), model_(model), decorator_(decorator) {}
    void set_decorator(Artist* decorator) { decorator_ = decorator; }
    void display() {
      std::string info = "Make: " + make_ + " | Model: " + model_;
      decorator_->draw(info);
    }
};

int main() {
  Aya a;
  Evelyn e;
  Marcus m;

  Car c("Honda", "CRV", &a);
  c.display();
  c.set_decorator(&e);
  c.display();
  c.set_decorator(&m);
  c.display();
  return 0;
}
