#include "shapes.hpp"
#include <iomanip>
#include <iostream>

int main() {
  int h;
  int w;
  std::cout << "Please enter the width for shape: ";
  std::cin >> w;
  std::cout << "Please enter the height for shape: ";
  std::cin >> h;
  // Create an instance of the `Shape` object and set the width and height
  // according to the user's input
  Shape shape(w, h);
  std::cout << "Please enter the width for rectangle: ";
  std::cin >> w;
  std::cout << "Please enter the height for rectangle: ";
  std::cin >> h;
  // Create an instance of the `Rectangle` object and set its width and height
  // according to the user's input
  Rectangle rectangle(w, h);
  std::cout << "Please enter the width for triangle: ";
  std::cin >> w;
  std::cout << "Please enter the height for triangle: ";
  std::cin >> h;
  // Create an instance of the `Triangle` object and set its width and height
  // according to the user's input
  Triangle triangle(w, h);
  // Assign the value of the `Shape` object's width and height to these
  // variables
  int shape_width = shape.width();
  int shape_height = shape.height();

  // Assign the value of the `Rectangle` object's width, height and area to
  // these variables
  int rectangle_width = rectangle.width();
  int rectangle_height = rectangle.height();
  int rectangle_area = rectangle.calc_area();

  // Assign the value of the `Triangle` object's width, height and area to
  // these variables
  int triangle_width = triangle.width();
  int triangle_height = triangle.height();
  int triangle_area = triangle.calc_area();

  std::cout << "Printing shape:\n"
            << "Width: " << std::setw(3) << std::left << shape_width
            << "Height: " << shape_height << "\n"
            << "Printing rectangle:\n"
            << "Width: " << std::setw(3) << std::left << rectangle_width
            << "Height: " << std::setw(3) << std::left << rectangle_height
            << "Area: " << rectangle_area << "\n"
            << "Printing triangle:\n"
            << "Width: " << std::setw(3) << std::left << triangle_width
            << "Height: " << std::setw(3) << std::left << triangle_height
            << "Area: " << triangle_area << "\n";
  return 0;
}
