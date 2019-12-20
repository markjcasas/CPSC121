#include "weapons.hpp"
#include <iostream>
#include <random>
int Daggers::attack() {
  int initial_damage[2];
  int random_number[2];
  int sum = 0;
  for (int i = 0; i < 2; i++) {
    initial_damage[i] = rand() % (attack_max() - attack_min()) + attack_min();
    random_number[i] = rand() % 20 + 1;
    if (random_number[i] < crit_dice_) {
      sum += initial_damage[i];
    } else {
      sum += initial_damage[i] * crit_;
    }
  }
  return sum;
}
int ShortSword::attack() {
  int initial_damage = rand() % (attack_max() - attack_min()) + attack_min();
  int random_multiplier = rand() % multiplier_ + 1;
  return initial_damage * random_multiplier;
}
void Enemy::receive_attack(Weapon* weapon) {
  int damage = weapon->attack();
  health_ -= damage;
  std::cout << weapon->name() << " dealt " << damage << " damage to "
            << name_ << '\n';
  if (health_ <= 0) {
    std::cout << name_ << " has been slain!\n";
  }
}
