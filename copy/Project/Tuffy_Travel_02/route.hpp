#include <iostream>
#ifndef ROUTE_HPP
#define ROUTE_HPP
class Route {
private:
  int arrival_time_;
  int departure_time_;
  std::string name_;
public:
  void set_name(const std::string &name) { name_ = name; }
	void set_arrival_time(int arrival_time);
	void set_departure_time(int departure_time);
	int departure_time();
	int arrival_time();
	std::string name();
};
int array_min(int array[], int magnitude);
Route create_route();
Route best_route(Route a[], int n, int time);
#endif
