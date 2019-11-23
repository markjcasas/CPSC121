#include <iostream>
#include "header.hpp"
#include <string.h>
#include <stdio.h>



void display_header(std::string str) {
  int length;
  int l;
  length = str.size();
  l = length + 4;
  std::cout << std::string(l, '*') << '\n';
  std::cout << "* " << str << " *"<< '\n';
  std::cout << std::string(l, '*') << '\n';
}

bool within_width(std::string s, unsigned short int x) {
  int width;
  width = s.size();
  if (width < x) {
    return true;
  } else {
    return false;
  }
}
