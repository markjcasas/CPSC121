#include <iostream>
// TODO: Place your Person class here
class Person {
  std::string name_;
  std::string address_;
  std::string phone_number_;
public:
  Person(std::string name, std::string address, std::string phone_number)
      : name_(name), address_(address), phone_number_(phone_number) {}
  Person() : Person("Unidentified", "Somewhere", "1-800-000-0000") {}
  void set_name(std::string name) { name_ = name; }
  void set_address(std::string address) { address_ = address; }
  void set_phone_number(std::string phone_number) { phone_number_ = phone_number; }
  std::string name() { return name_; }
  std::string address() { return address_; }
  std::string phone_number() { return phone_number_; }
  void display();
};
// TODO: Place your Organization class here
class Organization {
  std::string name_;
  Person president_;
  Person vice_president_;
  Person treasurer_;
public:
  void set_name(std::string name) { name_ = name; }
  void set_president(Person president) { president_ = president; }
  void set_vice_president(Person vice_president) { vice_president_ = vice_president; }
  void set_treasurer(Person treasurer) { treasurer_ = treasurer; }
  std::string name() { return name_; }
  Person president() { return president_; }
  Person vice_president() { return vice_president_; }
  Person treasurer() { return treasurer_; }
  Organization(std::string name)
      : name_(name) {}
  std::string get_position(std::string name);
};
