#include "pet.hpp"
#include <iostream>

int main() {
  // Create an array of 100 pet objects called `pet_arr`
  Pet pet_arr[100];
  int num_pet = 0;
  std::string name;
  std::string breed;
  std::string species;
  std::string color;
  double weight;
  do {
    std::cout << "Please enter the pet's name (q to quit): ";
    std::getline(std::cin, name);
    if (name != "q") {
      std::cout << "Please enter the pet's species: ";
      std::getline(std::cin, species);
      std::cout << "Please enter the pet's breed: ";
      std::getline(std::cin, breed);
      std::cout << "Please enter the pet's color: ";
      std::getline(std::cin, color);
      std::cout << "Please enter the pet's weight (lbs): ";
      std::cin >> weight;
      std::cin.ignore();



      // Create a pet object using the input from the user
      Pet user_input(name, species, breed, color, weight);
      // Store the newly-created pet object into the array. Use `num_pet` to
      // control the index where the pet object is placed and update it
      // accordingly
      pet_arr[num_pet] = user_input;
      num_pet++;
    }
  } while (name != "q");
  std::cout << "Printing Pets:\n";
  for (int i = 0; i < num_pet; i++) {
    std::cout << "Pet " << i + 1 << "\n";
    // Print information about the `i`th pet object
  pet_arr[i].print();
  }
  return 0;
}
