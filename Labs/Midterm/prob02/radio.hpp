#include <iostream>
#ifndef RADIO_HPP
#define RADIO_HPP
class Radio {
  int vol;
  double stat;
  std::string onof;
public:
  void set_vol(int volume) {
    vol = volume;
  }
  void set_stat(double station) {
    stat = station;
  }
  void set_onof(std::string is_on) {
    onof = is_on;
  }
  int volume() { return vol; }
  double station() { return stat; }
  std::string is_on() { return onof; }
};
#endif
