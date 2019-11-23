#include "route.hpp"
#include <iostream>

int array_min(int array[], int magnitude) {
  int position = magnitude - 1;
  if (magnitude == 1) {
    return array[0];
  } else {
    return std::min(array[position], array_min(array, position));
  }
}

void Route::set_arrival_time(int arrival_time) {
  arrival_time_ = arrival_time;
}


void Route::set_departure_time(int departure_time) {
  departure_time_ = departure_time;
}

int Route::departure_time() {
  return departure_time_;
}

int Route::arrival_time() {
  return arrival_time_;
}

std::string Route::name() {
  return name_;
}

Route create_route() {
  Route rte;
  int d;
  int a;
  std::string n;
  std::cout << "Please enter the name of the route: ";
  std::getline(std::cin, n);
  rte.set_name(n);
  std::cout << "Please enter the departure time of the route: ";
  std::cin >> d;
  rte.set_departure_time(d);
  std::cout << "Please enter the arrival time of the route: ";
  std::cin >> a;
  rte.set_arrival_time(a);
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << '\n';
  return rte;
}

Route best_route(Route a[], int n, int time) {
  int count = 0;
  int s[n];
  for (int i = 0; i < n; i++) {
    s[i]=a[i].departure_time() - time;
  }
  int b[count];
  for (int j = 0; j < n; j++) {
    if (s[j] > 0) {
      b[count] = s[j] + time;
      count++;
    }
  }
  Route best;
  for (int k = 0; k < n; k++) {
    if ((a[k].departure_time() > time) && (a[k].departure_time() == array_min(b, count))) {
      best = a[k];
    }
  }
  return best;
}
