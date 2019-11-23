#include <iostream>
#ifndef STUDENT_PROFILE_HPP
#define STUDENT_PROFILE_HPP
class Student {
  std::string name_;
  std::string cmajor_;
  unsigned int cwid_;
  double gpa_;
public:
  void set_name(const std::string &name) { name_ = name ;}
  void set_cmajor(const std::string& cmajor) { cmajor_ = cmajor; }
  void set_cwid(unsigned int cwid);
  void set_gpa(double gpa);
  std::string name();
  std::string cmajor();
  unsigned int cwid();
  double gpa();
};
double average_gpa(Student object[], int n);
#endif
