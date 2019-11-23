#include <iostream>

class Phone {
private:
  std::string number_;
  std::string provider_;
public:
  void set_number(std::string number) {
    number_ = number;
  }
  void set_provider(std::string provider) {
    provider_ = provider;
  }
  std::string number() {
    return number_;
  }
  std::string provider() {
    return provider_;
  }
  void call(std::string other_number) {
    std::cout << "You are connected to: " << provider_ << "\n";
    std::cout << "Outgoing call from: " << number_ << " to: " << other_number << "\n";
  }
};

int main() {
  Phone tuffy_phone;
  tuffy_phone.set_number("(657) 872-1283");
  tuffy_phone.set_provider("AT&T");
  tuffy_phone.call("(657) 278-3821");
  return 0;
}
