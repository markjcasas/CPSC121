#include <iostream>
#ifndef PLAYER_HPP
#define PLAYER_HPP
class Player {
  std::string name_;
  int health_;
  int strength_;
  int defense_;
  int xpos_;
  int ypos_;
public:
  Player() :name_("Ash"), health_(10), strength_(5), defense_(2), xpos_(0), ypos_(0) {}
  Player(std::string name, int health, int strength, int defense, int xpos, int ypos) :name_(name), health_(health), strength_(strength), defense_(defense), xpos_(xpos), ypos_(ypos) {}
  int xpos();
  int ypos();
  void set_xpos(int xpos) {
    xpos_ = xpos;
  }
  void set_ypos(int ypos) {
    ypos_ = ypos;
  }
  void set_name(const std::string &name) {
    name_ = name;
  }
  void set_health(int health) {
    health_ = health;
  }
  void set_defense(int defense) {
    defense_ = defense;
  }
  void set_strength(int strength) {
    strength_ = strength;
  }
  std::string name() {
    return name_;
  }
  int health();
  int strength() {
    return strength_;
  }
  int defense();
  void display_stat();
  void player_move();
  bool is_player_dead();
  void take_damage(int damage) {
    health_ -= damage;
    std::cout << name_ << " took " << damage << " damage" << '\n';
    bool dead = is_player_dead();
    if (dead == true) {
      std::cout << name_ << " is dead" << '\n';
    }
  }
};
#endif
