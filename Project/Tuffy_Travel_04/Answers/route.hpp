#include <iostream>
#ifndef ROUTE_HPP
#define ROUTE_HPP
class Route {
  std::string name_;
  int departure_time_;
  int arrival_time_;
public:
  void set_name(const std::string &name) {
    name_ = name;
  }
  void set_departure_time(int departure_time);
  void set_arrival_time(int arrival_time);
  std::string name();
  int departure_time();
  int arrival_time();
  void display();
};
int time_min(int timemin[], int min_number);
int time_max(int timemax[], int max_number);
Route create_route();
int get_time_to_leave();
void find_route(Route routes[], int magnitude, int time_leaving);
void display_routes(Route route[], int display_number);
std::string action(Route routearray[], int number);
#endif
