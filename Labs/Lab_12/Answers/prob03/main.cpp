#include "super_enemy.hpp"
#include <iostream>

int main() {
  // Create an instance of the enemy class
  Enemy enemy;
  // Create an instance of the super_enemy class
  SuperEnemy super_enemy;
  // Call the enemy's display method
  enemy.display();
  std::cout << "\n";
  // Call the super_enemy's display method
  super_enemy.display();
  std::cout << "\n";
  // Have both instances call their respective move_up and move_right...
  // ...methods 10 times
  for (int i = 0; i < 10; i++) {
    // place codes here
    enemy.move_up();
    enemy.move_right();
    super_enemy.move_up();
    super_enemy.move_right();
  }
  // Have both instances call their respective move_down and move_left...
  // ...methods 5 times
  for (int i = 0; i < 5; i++) {
    // place codes here
    enemy.move_down();
    enemy.move_left();
    super_enemy.move_down();
    super_enemy.move_left();
  }
  // Call the enemy's level_up method
  enemy.level_up();
  // Call the super_enemy's level_up method
  super_enemy.level_up();
  // Call the enemy's display method
  enemy.display();
  std::cout << "\n";
  // Call the super_enemy's display method
  super_enemy.display();
  return 0;
}
