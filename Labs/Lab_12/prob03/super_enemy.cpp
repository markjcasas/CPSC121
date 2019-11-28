#include "super_enemy.hpp"
#include <iostream>

void Enemy::level_up() {
  health_ += 2;
  strength_++;
  defense_++;
}

void Enemy::display() {
  std::cout << "Enemy" << "\nCoordinates: (" << xpos_ << ", " << ypos_ << ")\n"
            << "Health: " << health_ << "\nStrength: " << strength_
            << "\nDefense: " << defense_ << '\n';
}

void SuperEnemy::level_up() {
  set_health(health() + 5);
  set_strength(strength() + 3);
  set_defense(defense() + 2);
}

void SuperEnemy::display() {
  std::cout << "Super Enemy" << "\nCoordinates: (" << xpos() << ", " << ypos() << ")\n"
            << "Health: " << health() << "\nStrength: " << strength()
            << "\nDefense: " << defense() << '\n';
}
