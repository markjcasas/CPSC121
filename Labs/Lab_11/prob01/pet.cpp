#include "pet.hpp"
#include <iostream>

void Pet::print() {
    std::cout << "Name: " << name_;
    std::cout << "\nSpecies: " << species();
    std::cout << "\nBreed: " << Breed::name();
    std::cout << "\nColor: " << color();
    std::cout << "\nWeight: " << weight_ << " lbs\n";
}

void Pet::set_breed(std::string bs, std::string bn, std::string bc) {
    set_species(bs);
    Breed::set_name(bn);
    set_color(bc);
}
