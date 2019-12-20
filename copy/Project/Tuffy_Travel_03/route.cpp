#include "route.hpp"
#include <iostream>

void Route::set_departure_time(int departure_time) {
  departure_time_ = departure_time;
}

void Route::set_arrival_time(int arrival_time) {
  arrival_time_ = arrival_time;
}

void Route::display() {
  std::cout << "Route: " << name_ << '\n';
  std::cout << "Departure time: " << departure_time_ << '\n';
  std::cout << "Arrival time: " << arrival_time_;
}

std::string Route::name() {
  return name_;
}

int Route::departure_time() {
  return departure_time_;
}

int Route::arrival_time() {
  return arrival_time_;
}

Route create_route() {
  Route r;
  std::string nm;
  int at;
  int dt;
  std::cout << "Please enter the name of the route: ";
  std::getline(std::cin, nm);
  r.set_name(nm);
  std::cout << "Please enter the departure time of the route: ";
  std::cin >> dt;
  r.set_departure_time(dt);
  std::cout << "Please enter the arrival time of the route: ";
  std::cin >> at;
  r.set_arrival_time(at);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return r;
}

std::string action(Route arr[], int cnt) {
  char decision;
  std::cout << "\nWhat What do you want to do?" << '\n';
  std::cout << "R - Create routes" << '\n';
  std::cout << "D - Display routes" << '\n';
  std::cout << "X - Exit" << '\n';
  std::cout << "Action: ";
  std::cin >> decision;
  std::cout << '\n';
  if (decision == 'R') {
    cnt++;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    arr[cnt - 1]= create_route();
    return action(arr, cnt);
  } else if (decision == 'D') {
    std::cout << "Available Routes:\n\n";
    display_routes(arr, cnt);
    return action(arr, cnt);
  } else {
    return "Hi";
  }
}

void display_routes(Route route[], int n) {
    for (int i = 0; i < n; i++) {
      route[i].display();
      std::cout << '\n' << '\n';
    }
  }
