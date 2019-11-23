#include "player.hpp"
#include <iostream>

int Player::xpos() {
  return xpos_;
}

int Player::ypos() {
  return ypos_;
}

int Player::health() {
  return health_;
}

int Player::defense() {
  return defense_;
}

void Player::display_stat() {
  std::cout << "Player: " << name_ << "\nHealth: " << health_ << "\nStrength: ";
  std::cout << strength_ << "\nDefense: " << defense_ << "\nAt position: (";
  std::cout << xpos_ << ", " << ypos_ << ")\n";
}

void Player::player_move() {
  xpos_ += 1;
  ypos_ += 1;
}

bool Player::is_player_dead() {
  if (health_ > 0) {
    return false;
  } else {
    health_ = 0;
    return true;
  }
}
