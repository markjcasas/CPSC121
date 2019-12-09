#include "weapons.hpp"
#include <iostream>
#include <random>

int Weapon::attack() {
  srand(time(NULL));
  return rand() % (attack_max_ + attack_min_) + attack_min_;
}

int Daggers::attack() {
  int sum = 0;
  int damage_dagger[2], random_dagger[2];
  for (int i = 0; i < 2; i++) {
    srand(time(NULL));
    damage_dagger[i] = rand() % (attack_max() + attack_min()) + attack_min();
    srand(time(NULL));
    random_dagger[i] = rand() % 20 + 1;
    if (random_dagger[i] < crit_dice_) {
      sum += damage_dagger[i];
    } else {
      sum += damage_dagger[i] * random_dagger[i];
    }
  }
  return sum;
}

int ShortSword::attack() {
  srand(time(NULL));
  int damage_sword = rand() % (attack_max() + attack_min()) + attack_min();
  int random_sword = rand() % multiplier_ + 1;
  return damage_sword * random_sword;
}

void Enemy::receive_attack(Weapon* weapon) {
  int damage = weapon->attack();
  health_ -= damage;
  if (health_ > 0) {
    std::cout << weapon->name() << " dealt " << damage << " damage to "
              << name_ << '\n';
  } else {
    std::cout << name_ << " has been slain!" << '\n';
  }
}
