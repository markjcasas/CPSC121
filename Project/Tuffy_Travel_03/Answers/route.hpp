#include <iostream>
#ifndef ROUTE_HPP
#define ROUTE_HPP
class Route {
  std::string name_;
  int departure_time_;
  int arrival_time_;
public:
  void set_name(const std::string &name) { name_ = name;}
  void set_departure_time(int departure_time);
  void set_arrival_time(int arrival_time);
  std::string name();
  int departure_time();
  int arrival_time();
  void display();
};
Route create_route();
void display_routes(Route route[], int n);
std::string action(Route arr[], int cnt);
#endif
