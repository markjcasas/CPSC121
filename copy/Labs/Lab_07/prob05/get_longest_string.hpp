#include <iostream>
#ifndef GET_LONGEST_STRING_HPP
#define GET_LONGEST_STRING_HPP
class String {
  std::string str_;
public:
  void set_str(const std::string &str) { str_ = str; }
  std::string str();
};

std::string get_longest_string(std::string a[], int b);
#endif
