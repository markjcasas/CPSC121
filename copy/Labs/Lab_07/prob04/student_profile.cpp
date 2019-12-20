#include "student_profile.hpp"
#include <iomanip>
#include <iostream>

void Student::set_cwid(unsigned int cwid) {
  cwid_ = cwid;
}

void Student::set_gpa(double gpa) {
  gpa_ = gpa;
}

std::string Student::name() {
  return name_;
}

std::string Student::cmajor() {
  return cmajor_;
}

unsigned int Student::cwid() {
  return cwid_;
}

double Student::gpa() {
  return gpa_;
}

double average_gpa(Student object[], int n) {
  double sum = 0;
  for (int j = 0; j < n; j++) {
    sum += object[j].gpa();
  }
  return sum / n;
}
