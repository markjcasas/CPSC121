#include "weapons.hpp"
#include <iostream>
#include <random>
int main() {
  srand(time(NULL));
  std::string e_name;
  int e_health;
  std::cout << "Please enter the name of an enemy: ";
  std::getline(std::cin, e_name);
  std::cout << "Please enter the enemy's health: ";
  std::cin >> e_health;
  // Create an Enemy object using the name and health provided by the user.
  Enemy enemy(e_name, e_health);
  // Dynamically create a Dagger object in the heap and store it in a Weapon pointer
  Daggers* daggers = new Daggers;
  Weapon* dagger = daggers;
  // Dynamically create a ShortSword object  in the heap and store it in a Weapon pointer
  ShortSword* shortsword = new ShortSword;
  // Call the enemy object's receive_attack method and pass the first weapon as
  // the argument
  enemy.receive_attack(daggers);
  // Call the enemy object's receive_attack method and pass the second weapon as
  // the argument
  enemy.receive_attack(shortsword);
  // Delete all dynamically created objects in the heap
  delete shortsword;
  delete daggers;
  return 0;
}
