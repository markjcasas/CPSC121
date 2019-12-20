#include <iostream>
#include "time.hpp"
#include <sstream>
#include <string>



std::string mil_to_reg(unsigned short int q) {
  int length = 0;
  int hour;
  int minute;
  int t = q;
  for(; q != 0; q /= 10, length++);
  if (length == 3) {
    minute = t % 100;
    hour = t / 100 % 10;
  } else {
    minute = t % 100;
    hour = t / 100 % 100;
  }
  std::stringstream ss1;
  if (minute < 10) {
    ss1 << "0" << minute;
  } else {
    ss1 << minute;
  }
  std::string min = ss1.str();
  std::stringstream ss;
  if (hour == 0) {
    ss << hour + 12 << ":" << min << " am";
  } else if (hour < 12) {
    ss << hour << ":" << min << " am";
  } else if (hour == 12) {
    ss << hour << ":" << min << " pm";
  } else if ((hour > 12) && (hour <= 24)) {
    ss << hour - 12 << ":" << min << " pm";
  }
  std::string reg = ss.str();
  return reg;
}
