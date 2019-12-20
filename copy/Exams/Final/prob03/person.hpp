#include <iostream>
// TODO: Place the Person class here
class Person {
  std::string name_;
  std::string address_;
  std::string phone_number_;
public:
  Person(std::string name, std::string address, std::string phone_number)
      : name_(name), address_(address), phone_number_(phone_number) {}
  Person() : Person("Unidentified", "Somewhere", "1-800-000-0000") {}
/*  ~Person() {
    delete name_;
    delete address_;
    delete phone_number_;
  }*/
  void set_name(std::string name) { name_ = name; }
  void set_address(std::string address) { address_ = address; }
  void set_phone_number(std::string phone_number) { phone_number_ = phone_number; }
  std::string name() { return name_; }
  std::string address() { return address_; }
  std::string phone_number() { return phone_number_; }
  void display();
};
// TODO: Derive the class Student from the class Person here
class Student : public Person {
  int student_id_;
  std::string major_;
public:
  Student(std::string name, std::string address, std::string phone_num, int student_id, std::string major)
      : Person(name, address, phone_num), student_id_(student_id), major_(major) {}
  int student_id() { return student_id_; }
  std::string major() { return major_; }
/*  ~Student() {
    ~Person();
    delete student_id_;
    delete major_;
  }*/
  void set_student_id(int student_id) { student_id_ = student_id; }
  void set_major(std::string major) { major_ = major; }
  void display() {
    std::cout << name() << '\n' << address() << '\n' << phone_number() << '\n'
              << student_id_ << '\n' << major_ << '\n';
  }
};
