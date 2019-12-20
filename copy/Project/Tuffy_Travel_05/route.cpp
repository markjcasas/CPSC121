#include "route.hpp"
#include <fstream>
#include <iostream>

int time_min(int min_time[], int min_number) {
  int min_position = min_number - 1;
  if (min_number == 1) {
    return min_time[0];
  } else {
    return std::min(min_time[min_position], time_min(min_time, min_position));
  }
}
int time_max(int max_time[], int max_number) {
  int max_position = max_number - 1;
  if (max_number == 1) {
    return max_time[0];
  } else {
    return std::max(max_time[max_position], time_max(max_time, max_position));
  }
}

int get_time_to_leave() {
  int time_to_leave;
  std::cout << "Please enter the time you plan to leave: ";
  std::cin >> time_to_leave;
  return time_to_leave;
}
void display_routes(Route display_array[], int display_number) {
  if (display_number == 0) {
    std::cout << "Sorry, there are no routes available.\n";
  } else {
    std::cout << "Available Routes:\n\n";
    for (int h = 0; h < display_number; h++) {
      display_array[h].display();
      std::cout << '\n' << '\n';
    }
  }
}
std::string get_filename() {
  std::string file_name;
  std::cout << "Please enter the filename: ";
  std::getline(std::cin, file_name);
  return file_name;
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
  std::cin.ignore();
  return new_route;
}

void find_route(Route find_array[], int find_number, int find_time) {
  if (find_number == 0) {
    std::cout << "Sorry, there are no routes available.\n";
  } else {
    int time[find_number + 1];
    for (int k = 0; k < find_number + 1; k++) {
      time[k] = find_array[k].departure_time();
    }
    time[find_number] = find_time;
    if (find_time == time_max(time, find_number +1)) {
      std::cout << "Sorry, there is no route that leaves on or after the time you plan to leave.\n\n";
    } else {
      int positive_differences_count = 0;
      int difference[find_number];
      for (int i = 0; i < find_number; i++) {
        difference[i] = find_array[i].departure_time() - find_time;
      }
      int positive_differences[positive_differences_count];
      for (int j = 0; j < find_number; j++) {
        if (difference[j] > 0) {
          positive_differences[positive_differences_count] = difference[j] + find_time;
          positive_differences_count++;
        }
      }
      Route chosen_route;
      for (int l = 0; l < find_number; l++) {
        if ((find_array[l].departure_time() > find_time) && (find_array[l].departure_time() == time_min(positive_differences, positive_differences_count))) {
          chosen_route = find_array[l];
        }
      }
      std::cout << "We suggest you take this route:\n\n";
      chosen_route.display();
      std::cout << '\n';
    }
  }
}

void save_routes(Route save_array[], int save_number, std::string out_filename) {
  std::ofstream outfile;
  outfile.open(out_filename);
  outfile << save_number << '\n';
  for (int save_count = 0; save_count < save_number; save_count++) {
    outfile << save_array[save_count].name() << '\n';
    outfile << save_array[save_count].departure_time() << '\n';
    outfile << save_array[save_count].arrival_time() << '\n';
  }
  outfile.close();
  std::cout << "File saved!" << '\n';
}

void load_routes(Route load_array[], unsigned int &load_number, std::string in_filename) {
  std::ifstream infile;
  infile.open(in_filename);
  if (infile.is_open()) {
    std::string route_name;
    int time_at_stop;
    infile >> load_number;
    infile.seekg(1, infile.cur);
    for (int load_count = 0; load_count < load_number; load_count++) {
      std::getline(infile, route_name);
      load_array[load_count].set_name(route_name);
      infile >> time_at_stop;
      load_array[load_count].set_departure_time(time_at_stop);
      infile >> time_at_stop;
      load_array[load_count].set_arrival_time(time_at_stop);
      infile.seekg(1, infile.cur);
    }
    infile.close();
    std::cout << "File loaded!" << '\n';
  } else {
    std::cout << "File does not exist." << '\n';
  }
}

int action(Route action_array[], int action_number = 0) {
  char decision;
  std::cout << "\nWhat What do you want to do?\n"
            << "R - Create routes\n"
            << "D - Display routes\n"
            << "F - Find Route\n"
            << "S - Save routes\n"
            << "L - Load routes\n"
            << "X - Exit\n"
            << "Action: ";
  std::cin >> decision;
  std::cin.ignore();
  std::cout << '\n';
  if (decision == 'R' || decision == 'r') {
    action_number++;
    action_array[action_number - 1] = create_route();
    return action(action_array, action_number);
  } else if (decision == 'D' || decision == 'd') {
    display_routes(action_array, action_number);
    return action(action_array, action_number);
  } else if (decision == 'F' || decision == 'f') {
    find_route(action_array, action_number, get_time_to_leave());
    return action(action_array, action_number);
  } else if (decision == 'S' || decision == 's') {
    save_routes(action_array, action_number, get_filename());
    return action(action_array, action_number);
  } else if (decision == 'L' || decision == 'l') {
    Route ifstream_array[100];
    unsigned int ifstream_number = 0;
    load_routes(ifstream_array, ifstream_number, get_filename());
    return action(ifstream_array, ifstream_number);
  } else if (decision == 'X' || decision == 'x') {
    return 0;
  }
  return 0;
}
