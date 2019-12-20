#include "route.hpp"
#include <fstream>
#include <iostream>

void RouteManager::add(const Route& route) {
  route_[size_] = route;
  size_++;
}
void RouteManager::display_routes() {
  if (size_ == 0) {
    std::cout << "\nSorry, there are no routes available." << '\n';
  } else {
    std::cout << "\nAvailable Routes:\n" << '\n';
    for (int display_routes_count = 0; display_routes_count < size_; display_routes_count++) {
      route_[display_routes_count].display();
      std::cout << '\n';
    }
  }
}
Route create_route() {
  Route new_route;
  std::string new_name;
  int new_arrival_time;
  int new_departure_time;
  std::cout << "\nPlease enter the name of the route: ";
  std::getline(std::cin, new_name);
  new_route.set_name(new_name);
  std::cout << "Please enter the departure time of the route: ";
  std::cin >> new_departure_time;
  new_route.set_departure_time(new_departure_time);
  std::cout << "Please enter the arrival time of the route: ";
  std::cin >> new_arrival_time;
  new_route.set_arrival_time(new_arrival_time);
  std::cin.ignore();
  return new_route;
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
void RouteManager::find_route(unsigned short int find_time) {
  if (size_ == 0) {
    std::cout << "Sorry, there are no routes available.\n" << '\n';
  } else {
    int time_difference_count = 0;
    int time_difference[time_difference_count];
    Route chosen_route;
    for (int time_array_count = 0; time_array_count < size_; time_array_count++) {
      if (route_[time_array_count].departure_time() - find_time >= 0) {
        time_difference[time_difference_count] = route_[time_array_count].departure_time();
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
      for (int i = 0; i < size_; i++) {
        if (small == route_[i].departure_time()) {
          chosen_route = route_[i];
        }
      }
      std::cout << "We suggest you take this route:\n" << '\n';
      chosen_route.display();
      std::cout << '\n';
    }
  }
}
void RouteManager::save_routes(const std::string& out_filename) {
  std::ofstream outfile;
  outfile.open(out_filename);
  outfile << size_ << '\n';
  for (int save_count = 0; save_count < size_; save_count++) {
    outfile << route_[save_count].name() << '\n';
    outfile << route_[save_count].departure_time() << '\n';
    outfile << route_[save_count].arrival_time() << '\n';
  }
  outfile.close();
  std::cout << "File saved!\n" << '\n';
}
void RouteManager::load_routes(const std::string& in_filename) {
  std::ifstream infile;
  infile.open(in_filename);
  if (infile.is_open()) {
    std::string route_name;
    int time_at_stop;
    infile >> size_;
    infile.seekg(1, infile.cur);
    for (int load_count = 0; load_count < size_; load_count++) {
      std::getline(infile, route_name);
      route_[load_count].set_name(route_name);
      infile >> time_at_stop;
      route_[load_count].set_departure_time(time_at_stop);
      infile >> time_at_stop;
      route_[load_count].set_arrival_time(time_at_stop);
      infile.seekg(1, infile.cur);
    }
    infile.close();
    std::cout << "File loaded!\n" << '\n';
  } else {
    std::cout << "File does not exist." << '\n';
  }
}
int action(RouteManager action_object) {
  char decision;
  std::cout << "What What do you want to do?\n"
            << "R - Create routes\n"
            << "D - Display routes\n"
            << "F - Find Route\n"
            << "S - Save routes\n"
            << "L - Load routes\n"
            << "X - Exit\n"
            << "Action: ";
  std::cin >> decision;
  std::cin.ignore();
  if (decision == 'R' || decision == 'r') {
    Route create;
    create = create_route();
    action_object.add(create);
    std::cout << '\n';
    return action(action_object);
  } else if (decision == 'D' || decision == 'd') {
    action_object.display_routes();
    return action(action_object);
  } else if (decision == 'F' || decision == 'f') {
    std::cout << '\n';
    action_object.find_route(get_time_to_leave());
    return action(action_object);
  } else if (decision == 'S' || decision == 's') {
    std::cout << '\n';
    action_object.save_routes(get_filename());
    return action(action_object);
  } else if (decision == 'L' || decision == 'l') {
    std::cout << '\n';
    action_object.load_routes(get_filename());
    return action(action_object);
  } else if (decision == 'X' || decision == 'x') {
    return 0;
  }
  return 0;
}
