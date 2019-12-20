#include "person.hpp"
#include <iostream>


int main() {
  // TODO: Create a Student object using the non-default constructor with the
  // information shown in the example in README.md
  // Extra points if you dynamically allocate the Student object in the heap
  Student student("Joan Smith", "123 N. Main St. Orange, CA 92874", "562-744-8524", 12345, "Computer Science");
  // TODO: Call the display member function of your Student object
  student.display();
  // TODO: If you allocated the Student object in the heap, make sure to
  // deallocate it
  return 0;
}
