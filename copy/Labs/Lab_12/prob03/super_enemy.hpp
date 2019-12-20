#include <iostream>
#ifndef SUPER_ENEMY_HPP
#define SUPER_ENEMY_HPP
class Enemy {
  int xpos_, ypos_, health_, strength_, defense_;
public:
  Enemy() : Enemy(0, 0, 5, 3, 1) {}
  Enemy(int xpos, int ypos, int health, int strength, int defense)
    : xpos_(xpos), ypos_(ypos), health_(health), strength_(strength), defense_(defense) {}
  void set_xpos(int xpos) { xpos_ = xpos; }
  void set_ypos(int ypos) { ypos_ = ypos; }
  void set_health(int health) { health_ = health; }
  void set_strength(int strength) { strength_ = strength; }
  void set_defense(int defense) { defense_ = defense; }
  int xpos() { return xpos_; }
  int ypos() { return ypos_; }
  int health() { return health_; }
  int strength() { return strength_; }
  int defense() { return defense_; }
  void move_up() { ypos_++; }
  void move_down() { ypos_--; }
  void move_right() { xpos_++; }
  void move_left() { xpos_--; }
  void level_up();
  void display();
};
class SuperEnemy : public Enemy {
public:
  SuperEnemy() : Enemy(0, 0, 7, 5, 3) {}
  SuperEnemy(int xpos, int ypos, int health, int strength, int defense)
    : Enemy(xpos, ypos, health, strength, defense) {}
    void move_up() { set_ypos(ypos() + 2); }
    void move_down() { set_ypos(ypos() - 2); }
    void move_right() { set_xpos(xpos() + 2); }
    void move_left() { set_xpos(xpos() - 2); }
    void level_up();
    void display();
};
#endif
