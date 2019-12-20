#include "radio.hpp"
#include <iostream>

int main() {
  // Create a Radio object
  Radio radio;
  int v;
  v = 3;
  double st;
  st = 98.3;
  // Change the radio object's volume to 3
  radio.set_vol(v);
  // Change the radio station to 98.3
  radio.set_stat(st);
  // Turn the radio on.
  radio.set_onof("on");

  std::cout << "The radio is currently ";
  // Display "on" if the radio is on or "off" if the
  // radio is off.
  std::cout << radio.is_on();

  std::cout << ".\nYou are currently listening to ";
  // Display the radio station.
  std::cout << radio.station();

  std::cout << " at a volume of ";
  // Display the volume.

  std::cout << radio.volume() << ".\n";
}
