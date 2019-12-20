#include <iostream>
#include <iomanip>
#ifndef CAR_HPP
#define CAR_HPP
// Car history references:
// https://www.loc.gov/rr/scitech/mysteries/auto.html
// https://www.mercedes-benz.com/en/mercedes-benz/classic/history/benz-patent-motor-car/

class Car {
private:
  std::string name_;
  int year_;
  double speed_;

public:
  Car() : Car("Steam automobile", 1769) {}
  Car(const std::string& name, int year)
      : name_(name), year_(year), speed_(0) {}
  virtual ~Car() {}
  void set_name(const std::string& name) { name_ = name; }
  void set_year(int year) { year_ = year; }
  std::string name() const { return name_; }
  int year() const { return year_; }
  double speed() const { return speed_; }
  // Create the virtual functions as described in the readme
  // drive()
  // and
  // is_empty()
  virtual void drive(double speed) { speed_ = speed; }
  virtual bool is_empty() { return false; }
};

//Implement the ElectricCar and GasolineCar classes below.
class ElectricCar : public Car {
  double battery_percentage_;
public:
  ElectricCar() : ElectricCar("Electric carriage", 1832) {}
  ElectricCar(const std::string& name, int year)
      :  Car(name, year), battery_percentage_(100.0) {}
  bool is_empty() override;
  void drive(double speed) override;
};
class GasolineCar : public Car {
  double tank_;
  double mpg_;
public:
  GasolineCar() : GasolineCar("Gasoline car", 1885, 12, 24) {}
  GasolineCar(const std::string& name, int year, double tank, double MPG)
      : Car(name ,year), tank_(tank), mpg_(MPG) {}
  bool is_empty() override;
  void drive(double speed) override;
};
#endif
