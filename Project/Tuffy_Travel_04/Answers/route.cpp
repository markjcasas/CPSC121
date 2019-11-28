#include "route.hpp"
#include <iostream>

int time_min(int timemin[], int min_number) {
  int min_position = min_number - 1;
  if (min_number == 1) {
    return timemin[0];
  } else {
    return std::min(timemin[min_position], time_min(timemin, min_position));
  }
}

int time_max(int timemax[], int max_number) {
  int max_position = max_number - 1;
  if (max_number == 1) {
    return timemax[0];
  } else {
    return std::max(timemax[max_position], time_max(timemax, max_position));
  }
}

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
  Route new_route;
  std::string new_name;
  int new_arrival_time;
  int new_departure_time;
  std::cout << "Please enter the name of the route: ";
  std::getline(std::cin, new_name);
  new_route.set_name(new_name);
  std::cout << "Please enter the departure time of the route: ";
  std::cin >> new_departure_time;
  new_route.set_departure_time(new_departure_time);
  std::cout << "Please enter the arrival time of the route: ";
  std::cin >> new_arrival_time;
  new_route.set_arrival_time(new_arrival_time);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return new_route;
}

int get_time_to_leave() {
  int time_to_leave;
  std::cout << "Please enter the time you plan to leave: ";
  std::cin >> time_to_leave;
  return time_to_leave;
}

void find_route(Route routes[], int magnitude, int time_leaving) {
  if (magnitude == 0) {
    std::cout << "Sorry, there are no routes available.";
  } else {
    int time[magnitude + 1];
    for (int k = 0; k < magnitude + 1; k++) {
      time[k] = routes[k].departure_time();
    }
    time[magnitude] = time_leaving;
    if (time_leaving == time_max(time, magnitude +1)) {
      std::cout << "Sorry, there is no route that leaves on or after the time you plan to leave." << '\n';
    } else {
      int count = 0;
      int difference[magnitude];
      for (int i = 0; i < magnitude; i++) {
        difference[i] = routes[i].departure_time() - time_leaving;
      }
      int positive_differences[count];
      for (int j = 0; j < magnitude; j++) {
        if (difference[j] > 0) {
          positive_differences[count] = difference[j] + time_leaving;
          count++;
        }
      }
      Route chosen_route;
      for (int l = 0; l < magnitude; l++) {
        if ((routes[l].departure_time() > time_leaving) && (routes[l].departure_time() == time_min(positive_differences, count))) {
          chosen_route = routes[l];
        }
      }
      std::cout << "We suggest you take this route:\n\n";
      chosen_route.display();
    }
  }
}

std::string action(Route routearray[], int number = 0) {
  char decision;
  std::cout << "\nWhat What do you want to do?" << '\n';
  std::cout << "R - Create routes\n" << "D - Display routes\n" << "F - Find Route\n";
  std::cout << "X - Exit\n" << "Action: ";
  std::cin >> decision;
  std::cout << '\n';
  if (decision == 'R' || decision == 'r') {
    number++;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    routearray[number - 1] = create_route();
    return action(routearray, number);
  } else if (decision == 'D' || decision == 'd') {
    std::cout << "Available Routes:\n\n";
    display_routes(routearray, number);
    return action(routearray, number);
  } else if (decision == 'F' || decision == 'f') {
    find_route(routearray, number, get_time_to_leave());
    return action(routearray, number);
  } else if (decision == 'X' || decision == 'x') {
    return "  ";
  }
}

void display_routes(Route route[], int display_number) {
    for (int h = 0; h < display_number; h++) {
      route[h].display();
      std::cout << '\n' << '\n';
    }
  }
