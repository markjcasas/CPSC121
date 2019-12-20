#include "route.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
void CheckedRoute::display() {
  std::cout << "Checked Route: " << name() << "\nDeparture time: "
            << departure_time() << "\nTake off time: " << take_off_time_
            << "\nArrival time: " << arrival_time() << '\n';
}
std::string CheckedRoute::save_string() {
  std::stringstream ss;
  ss << "[CheckedRoute]\n" << name() << '\n' << departure_time()
     << '\n' << take_off_time_ << '\n' << arrival_time() << '\n';
  return ss.str();
}
void RouteManager::add(Route* route) {
  route_[size_] = route;
  size_++;
}
void RouteManager::display_routes() {
  if (size_ == 0) {
    std::cout << "\nSorry, there are no routes available." << '\n';
  } else {
    std::cout << "\nAvailable Routes:\n" << '\n';
    for (int display_routes_count = 0; display_routes_count < size_; display_routes_count++) {
      route_[display_routes_count]->display();
      std::cout << '\n';
    }
  }
}
void RouteManager::find_route(unsigned short int find_time) {
  if (size_ == 0) {
    std::cout << "Sorry, there are no routes available.\n" << '\n';
  } else {
    int time_difference_count = 0;
    int time_difference[time_difference_count];
    Route* chosen_route;
    for (int time_array_count = 0; time_array_count < size_; time_array_count++) {
      if (route_[time_array_count]->departure_time() - find_time >= 0) {
        time_difference[time_difference_count] = route_[time_array_count]->departure_time();
        time_difference_count++;
      }
    }
    if (time_difference_count == 0) {
      std::cout << "Sorry, there is no route that leaves on or after the time you plan to leave.\n" << '\n';
    } else {
      int small = time_difference[0];
      for (int find_count = 1; find_count < time_difference_count; find_count++) {
        if (small > time_difference[find_count]) {
          small = time_difference[find_count];
        }
      }
      for (int chosen_route_count = 0; chosen_route_count < size_; chosen_route_count++) {
        if (small == route_[chosen_route_count]->departure_time()) {
          chosen_route = route_[chosen_route_count];
        }
      }
      std::cout << "We suggest you take this route:\n" << '\n';
      chosen_route->display();
      std::cout << '\n';
    }
  }
}
void RouteManager::save_routes(const std::string& out_filename) {
  std::ofstream outfile;
  outfile.open(out_filename);
  outfile << size_ << '\n';
  for (int save_count = 0; save_count < size_; save_count++) { outfile << route_[save_count]->save_string(); }
  outfile.close();
  std::cout << "File saved!\n" << '\n';
}
void RouteManager::load_routes(const std::string& in_filename) {
  ;
  std::ifstream infile;
  infile.open(in_filename);
  if (infile.is_open()) {
    int load_size;
    std::string ifstream_string;
    int ifstream_int;
    infile >> load_size;
    infile.seekg(1, infile.cur);
    for (int load_count = 0; load_count < load_size; load_count++) {
      std::getline(infile, ifstream_string);
      if (ifstream_string == "[Route]") {
        Route ifstream_route;
        std::getline(infile, ifstream_string);
        ifstream_route.set_name(ifstream_string);
        infile >> ifstream_int;
        ifstream_route.set_departure_time(ifstream_int);
        infile >> ifstream_int;
        ifstream_route.set_arrival_time(ifstream_int);
        add(&ifstream_route);
        infile.seekg(1, infile.cur);
      } else {
        CheckedRoute ifstream_checked_route;
        std::getline(infile, ifstream_string);
        ifstream_checked_route.set_name(ifstream_string);
        infile >> ifstream_int;
        ifstream_checked_route.set_departure_time(ifstream_int);
        infile >> ifstream_int;
        ifstream_checked_route.set_take_off_time(ifstream_int);
        infile >> ifstream_int;
        ifstream_checked_route.set_arrival_time(ifstream_int);
        add(&ifstream_checked_route);
        infile.seekg(1, infile.cur);
    }
  }
  infile.close();
  std::cout << "File loaded!\n" << '\n';
  } else {
    std::cout << "File does not exist." << '\n';
  }
}
Route* create_route() {
  Route* new_route = new Route;
  std::string new_route_name;
  int new_route_arrival_time;
  int new_route_departure_time;
  std::cout << "\nPlease enter the name of the route: ";
  std::getline(std::cin, new_route_name);
  new_route->set_name(new_route_name);
  std::cout << "Please enter the departure time of the route: ";
  std::cin >> new_route_departure_time;
  new_route->set_departure_time(new_route_departure_time);
  std::cout << "Please enter the arrival time of the route: ";
  std::cin >> new_route_arrival_time;
  new_route->set_arrival_time(new_route_arrival_time);
  std::cin.ignore();
  return new_route;
}
CheckedRoute* create_checked_route() {
  CheckedRoute* new_checked_route = new CheckedRoute;
  std::string new_checked_route_name;
  int new_checked_route_arrival_time;
  int new_checked_route_departure_time;
  int new_checked_route_take_off_time;
  std::cout << "\nPlease enter the name of the checked route: ";
  std::getline(std::cin, new_checked_route_name);
  new_checked_route->set_name(new_checked_route_name);
  std::cout << "Please enter the departure time of the checked route: ";
  std::cin >> new_checked_route_departure_time;
  new_checked_route->set_departure_time(new_checked_route_departure_time);
  std::cout << "Please enter the take off time of the checked route: ";
  std::cin >> new_checked_route_take_off_time;
  new_checked_route->set_take_off_time(new_checked_route_take_off_time);
  std::cout << "Please enter the arrival time of the route: ";
  std::cin >> new_checked_route_arrival_time;
  new_checked_route->set_arrival_time(new_checked_route_arrival_time);
  std::cin.ignore();
  return new_checked_route;
}
int get_time_to_leave() {
  int time_to_leave;
  std::cout << "Please enter the time you plan to leave: ";
  std::cin >> time_to_leave;
  return time_to_leave;
}
std::string get_filename() {
  std::string file_name;
  std::cout << "Please enter the filename: ";
  std::getline(std::cin, file_name);
  return file_name;
}
int tuffy_travel(RouteManager tuffy_travel_object) {
  char decision;
  std::cout << "What What do you want to do?\n"
            << "R - Create routes\n"
            << "C - Create checked routes\n"
            << "D - Display routes\n"
            << "F - Find Route\n"
            << "S - Save routes\n"
            << "L - Load routes\n"
            << "X - Exit\n"
            << "Action: ";
  std::cin >> decision;
  std::cin.ignore();
  if (decision == 'R' || decision == 'r') {
    tuffy_travel_object.add(create_route());
    std::cout << '\n';
    return tuffy_travel(tuffy_travel_object);
  } else if (decision == 'C' || decision == 'c') {
    std::cout << '\n';
    tuffy_travel_object.add(create_checked_route());
    return tuffy_travel(tuffy_travel_object);
  } else if (decision == 'D' || decision == 'd') {
    tuffy_travel_object.display_routes();
    return tuffy_travel(tuffy_travel_object);
  } else if (decision == 'F' || decision == 'f') {
    std::cout << '\n';
    tuffy_travel_object.find_route(get_time_to_leave());
    return tuffy_travel(tuffy_travel_object);
  } else if (decision == 'S' || decision == 's') {
    std::cout << '\n';
    tuffy_travel_object.save_routes(get_filename());
    return tuffy_travel(tuffy_travel_object);
  } else if (decision == 'L' || decision == 'l') {
    tuffy_travel_object.~RouteManager();
    std::cout << '\n';
    tuffy_travel_object.load_routes(get_filename());
    return tuffy_travel(tuffy_travel_object);
  } else if (decision == 'X' || decision == 'x') {
    return 0;
  }
  return 0;
}
