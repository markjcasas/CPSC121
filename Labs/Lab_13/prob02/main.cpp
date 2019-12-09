#include "weapons.hpp"
#include <iostream>
#include <random>
int main() {
  std::string e_name;
  int e_health;
  std::cout << "Please enter the name of an enemy: ";
  std::getline(std::cin, e_name);
  std::cout << "Please enter the enemy's health: ";
  std::cin >> e_health;
  // Create an Enemy object using the name and health provided by the user.
  Enemy enemy(e_name, e_health);
  // Dynamically create a Dagger object in the heap and store it in a Weapon pointer
  // Dynamically create a ShortSword object  in the heap and store it in a Weapon pointer
  Weapon* dagger = new Daggers;
  Weapon* shortsword = new ShortSword;
  // Call the enemy object's receive_attack method and pass the first weapon as
  // the argument
  enemy.receive_attack(dagger);
  // Call the enemy object's receive_attack method and pass the second weapon as
  // the argument
  enemy.receive_attack(shortsword);
  // Delete all dynamically created objects in the heap
  delete dagger;
  delete shortsword;
  return 0;
}
