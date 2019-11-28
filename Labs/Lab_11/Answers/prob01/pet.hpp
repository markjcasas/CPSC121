#include <iostream>
#ifndef PET_HPP
#define PET_HPP
class Breed {
    std::string species_;
    std::string name_;
    std::string color_;
  public:
    Breed() : species_("Dog"), name_("Pug"), color_("Fawn") {}
    Breed(std::string sp, std::string nm, std::string cl) : species_(sp), name_(nm), color_(cl) {}
    void set_species(const std::string &species) { species_ = species; }
    void set_name(const std::string &name) { name_ = name; }
    void set_color(const std::string &color) { color_ = color; }
    std::string species() { return species_; }
    std::string name() { return name_; }
    std::string color() { return color_; }
};

class Pet : public Breed {
    std::string name_;
    Breed breed_;
    double weight_;
  public:
    void set_name(const std::string &name) { name_ = name; }
    void set_breed(Breed breed) { breed_ = breed; }
    void set_weight(double weight) { weight_ = weight; }
    std::string name() { return name_; }
    Breed breed() { return breed_; }
    double weight() { return weight_ ; }
    Pet() : Breed() {
        Pet::set_name("Doug");
        set_weight(15.6);
        set_breed(Breed());
    }
    Pet(std::string pnm, std::string bsp, std::string bnm, std::string bcl, double pwt) : Breed(bsp, bnm, bcl) {
        Pet::set_name(pnm);
        set_weight(pwt);
        set_breed(Breed(bsp, bnm, bcl));
    }
    Pet(std::string nmp, Breed brdp, double wtp) : name_(nmp), breed_(brdp), weight_(wtp) {}
    void print();
    void set_breed(std::string bs, std::string bn, std::string bc);
};
#endif
