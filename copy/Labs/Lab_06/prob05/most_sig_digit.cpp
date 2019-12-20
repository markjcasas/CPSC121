#include <iostream>
#include "most_sig_digit.hpp"
#include <math.h>
#include <string>
#include <sstream>


int most_significant_digit(int q) {
  int result;
  if (q < 0) {
    std::stringstream ss;
    ss << q;
    std::string str = ss.str();
    std::string substr = str.substr(1,3);
    int res = substr.front() - '0';
    result = (-1) * res;
  } else {
    std::stringstream ss;
    ss << q;
    std::string str = ss.str();
    char f = str.front();
    result = f -'0';
  }
  return result;
}
