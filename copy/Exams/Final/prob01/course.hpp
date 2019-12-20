// TODO: implement the Course class

#include <iomanip>
#include <iostream>
class Course {
  int course_num_;
  std::string course_name_;
  std::string department_;
public:
  void set_course_num(int course_num){ course_num_ = course_num; }
  void set_course_name(std::string course_name){ course_name_ = course_name; }
  void set_department(std::string department){ department_ = department; }
  ~Course() {}
  Course() : Course(121, "Object oriented programming", "Computer Science") {}
  Course(int course_num, std::string course_name, std::string department)
	: course_num_(course_num), course_name_(course_name),
	department_(department) {}
  void display() {
    std::cout << "Course number: " << course_num_ << "\nCourse name: "
              << course_name_ << "\nDepartment: " << department_ << '\n';
  }
}; 
