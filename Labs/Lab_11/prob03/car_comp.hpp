#include <iostream>
#ifndef CAR_COMP_HPP
#define CAR_COMP_HPP
// Class used to identify cars
class Identifier {
private:
  std::string name_;
  int id_;
  std::string license_plate_;

public:
  Identifier() : Identifier("Ford", 1, "123456") {}

  Identifier(const std::string& name, int id, const std::string& license_plate)
      : name_(name), id_(id), license_plate_(license_plate) {}

  std::string name() const { return name_; }
  void set_name(const std::string& name) { name_ = name; }
  int id() const { return id_; }
  void set_id(int id) { id_ = id; }
  std::string license_plate() const { return license_plate_; }
  void set_license_plate(const std::string& license_plate) {
    license_plate_ = license_plate;
  }
};
// Class that represents dates
class Date {
private:
  int day_;
  int month_;
  int year_;

public:
  Date() : Date(1, 1, 1885) {}

  Date(int day, int month, int year) : day_(day), month_(month), year_(year) {}

  int day() const { return day_; }
  void set_day(int day) { day_ = day; }
  int month() const { return month_; }
  void set_month(int month) { month_ = month; }
  int year() const { return year_; }
  void set_year(int year) { year_ = year; }
};
class Car : public Identifier, public Date {
  Identifier identity_;
  Date release_date_;
public:
  Car() {}
  Car(Identifier ID) : identity_(ID) {}
  Car(Date rel_date) : release_date_(rel_date) {}
  Car(Identifier id, Date rd) : identity_(id), release_date_(rd) {}
  void set_identity(Identifier identity) { identity_ = identity; }
  void set_release_date(Date release_date) { release_date_ = release_date; }
  Identifier identity() { return identity_; }
  Date release_date() { return release_date_; }
  void print();
};
#endif
