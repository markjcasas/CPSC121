#include <fstream>
#include <iostream>
#include <sstream>
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
  virtual void display() {
    std::cout << "Route: " << name_ << "\nDeparture time: " << departure_time_
              << "\nArrival time: " << arrival_time_ << '\n';
  }
  virtual std::string save_string() {
    std::stringstream ss;
    ss << "[Route]\n" << name_ << '\n' << departure_time_ << '\n'
       << arrival_time_ << '\n';
    return ss.str();
  }
};
class CheckedRoute : public Route {
  int take_off_time_;
public:
  void set_take_off_time(int take_off_time) { take_off_time_ = take_off_time; }
  int take_off_time() { return take_off_time_; }
  CheckedRoute() : CheckedRoute("Home", 2000, 2010, 2200) {}
  CheckedRoute(std::string name, int departure_time, int take_off_time, int arrival_time)
      : Route(name, departure_time, arrival_time), take_off_time_(take_off_time) {}
  void display() override;
  std::string save_string() override;
};
class RouteManager {
  Route* route_[100];
  int size_;
public:
  RouteManager() : route_{}, size_(0) {}
  ~RouteManager() {
    for (int destructor = 0; destructor < size_; destructor++) {
      delete route_[size_];
      size_ = 0;
    }
  }
  void add(Route* route);
  void display_routes();
  void save_routes(const std::string& out_filename);
  void load_routes(const std::string& in_filename);
  void find_route(unsigned short int find_time);
};
Route* create_route();
CheckedRoute* create_checked_route();
int get_time_to_leave();
int tuffy_travel(RouteManager tuffy_travel_object);
std::string get_filename();
#endif
