#include <fstream>
#include <iostream>
#ifndef ROUTE_HPP
#define ROUTE_HPP
class Route {
  std::string name_;
  int departure_time_;
  int arrival_time_;
public:
  Route() : Route("Home", 2000, 2200) {}
  Route(std::string name, int departure_time, int arrival_time)
      : name_(name), departure_time_(departure_time),
        arrival_time_(arrival_time) {}
  void set_name(const std::string& name) { name_ = name; }
  void set_arrival_time(int arrival_time) { arrival_time_ = arrival_time; }
  void set_departure_time(int departure_time) { departure_time_ = departure_time; }
  std::string name() { return name_; }
  int arrival_time() { return arrival_time_; }
  int departure_time() { return departure_time_; }
  void display() {
    std::cout << "Route: " << name_ << "\nDeparture time: " << departure_time_
              << "\nArrival time: " << arrival_time_ << '\n';
  }
};
class RouteManager {
  Route route_[100];
  int size_;
public:
  RouteManager() : route_{}, size_(0) {}
  void add(const Route& route);
  void display_routes();
  void find_route(unsigned short int find_time);
  void save_routes(const std::string& out_filename);
  void load_routes(const std::string& in_filename);
};
Route create_route();
int get_time_to_leave();
int action(RouteManager action_object);
std::string get_filename();
#endif
