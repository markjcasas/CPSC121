#include "gcd.hpp"
#include <iostream>
int gcd(int x, int y) {
  if (x == 0) {
    return y;
  } else {
    return gcd(y % x, x);
  }
}
