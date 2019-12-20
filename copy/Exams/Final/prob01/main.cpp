#include "course.hpp"
#include <iomanip>
#include <iostream>

int main() {
  int course_count;
  int course_num;
  std::string course_name;
  std::string department;

  std::cout << "Please enter the number of courses you wish to register for: ";
  std::cin >> course_count;
  std::cin.ignore();
  Course courses[course_count];
  // TODO: create a dynamic array in the heap to store the Course objects. The
  // size of the array is based on the value provided by the user

  for (int i = 0; i < course_count; i++) {
    std::cout << "Please enter the course number: ";
    // TODO: handle the user input to assign the course number of the Course
    // object in the corresponding position in the array
    std::cin >> course_num;
    std::cin.ignore();
    courses[i].set_course_num(course_num);
    std::cout << "Please enter the course name: ";
    // TODO: handle the user input to assign the course name of the Course
    // object in the corresponding position in the array
    std::getline(std::cin, course_name);
    courses[i].set_course_name(course_name);
    std::cout << "Please enter the department name: ";
    std::getline(std::cin, department);
    courses[i].set_department(department);
    // TODO: handle the user input to assign the departnment name of the Course
    // object in the corresponding position in the array
  }

  for (int i = 0; i < course_count; i++) {
    // TODO: display information about each Course object in the dynamic array
    // to the console
    courses[i].display();
  }
  // TODO: deallocate the dynamically alocated array
//  for (int q = 0; q < course_count; q++) { delete courses[q]; }
  return 0;
}
