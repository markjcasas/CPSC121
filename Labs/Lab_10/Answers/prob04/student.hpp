#include <iomanip>
#include <iostream>
#include <string>
#ifndef STUDENT_HPP
#define STUDENT_HPP
class Student {
  std::string name_;
  int id_;
  int grades_[10];
  int num_grades_;
public:
  void set_name(const std::string &name) {
    name_ = name;
  }
  void set_id(int id) {
    id_ = id;
  }
  void set_num_grades(int num_grades) {
    num_grades_ = num_grades;
  }
  std::string name() {
    return name_;
  }
  int id() {
    return id_;
  }
  int num_grades() {
    return num_grades_;
  }
  Student() :name_("Stu Dent"), id_(123456789), grades_{}, num_grades_(0) {}
  Student(std::string name, int id) :name_(name), id_(id), grades_{}, num_grades_(0) {}
  void add_grade(int grade);
  double calculate_grade();
  void print_student();
};
#endif
