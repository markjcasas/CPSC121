#include "student.hpp"
#include <iomanip>
#include <iostream>
#include <string>

void Student::add_grade(int grade) {
  if (num_grades_ + 1 < 10) {
    grades_[num_grades_] = grade;
    num_grades_++;
  } else {
    std::cout << "Array full, unable to add grade" << '\n';
  }
}

double Student::calculate_grade() {
  double sum = 0;
  for (int i = 0; i < num_grades_; i++) {
    sum += grades_[i];
  }
  return sum / num_grades_;
}

void Student::print_student() {
  std::cout << name_ << " " << id_ << "\nTest Grades:" << '\n';
  for (int j = 0; j < num_grades_; j++) {
    std::cout << grades_[j] << '\n';
  }
}
