#include <fstream>
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
  void set_departure_time(int departure_time) {
    departure_time_ = departure_time;
  }
  void set_arrival_time(int arrival_time) {
    arrival_time_ = arrival_time;
  }
  std::string name() {
    return name_;
  }
  int departure_time() {
    return departure_time_;
  }
  int arrival_time() {
    return arrival_time_;
  }
  void display() {
    std::cout << "Route: " << name_ << '\n';
    std::cout << "Departure time: " << departure_time_ << '\n';
    std::cout << "Arrival time: " << arrival_time_;
  }
};
int time_min(int min_time[], int min_number);
int time_max(int max_time[], int max_number);
Route create_route();
int get_time_to_leave();
void find_route(Route find_array[], int find_number, int find_time);
void display_routes(Route display_array[], int display_number);
int action(Route action_array[], int action_number);
std::string get_filename();
void save_routes(Route save_array[], int save_number, std::string out_filename);
void load_routes(Route load_array[], unsigned int &load_number, std::string in_filename);
#endif
