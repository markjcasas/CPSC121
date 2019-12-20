#include "organization.hpp"
#include <iostream>

int main() {
  // TODO: Create three person objects with the following information
  Person mary("Marry Barra", "100 Renaissance Center, Detroit, Michigan", "(313) 567-3126");
  // Name: Mary Barra; Address: 100 Renaissance Center, Detroit, Michigan; Phone number: (313) 567-3126
  Person ursula("Ursula Burns", "Claude Debussylaan 88, 1082 MD, Amsterdam, the Netherlands", "+31 20 797 7200");
  // Name: Ursula Burns; Address: Claude Debussylaan 88, 1082 MD, Amsterdam, the Netherlands; Phone number: +31 20 797 7200
  Person luis("Luis Von Ahn", "5900 Penn Ave, Pittsburgh, PA 15206", "(412) 567-6602");
  // Name: Luis Von Ahn; Address: 5900 Penn Ave, Pittsburgh, PA 15206; Phone number: (412) 567-6602
  Organization Tech_Club("Tech Club");
  // TODO: Create an organization called Tech club
  Tech_Club.set_president(mary);
  // TODO: Assign Mary Barra to be the president
  Tech_Club.set_vice_president(ursula);
  // TODO: Assign Ursula Burns to be the vice president
  Tech_Club.set_treasurer(luis);
  // TODO: Assign Luis Von Ahn to be the treasurer
  std::string org_name = Tech_Club.name();
  // TODO: Retrieve the name of the organization and store it in a std::string
  // called org_name


  // TODO: Retrieve the position of Mary Barra and store into a std::string called
  // mary_position
  std::string mary_position = Tech_Club.get_position(mary.name());
    // TODO: Retrieve the position of Linus Torvalds and store into a std::string called
  // linus_position
  std::string linus_position = Tech_Club.get_position("Linus Torvalds");

  std::cout << "Mary Barra is currently " << mary_position << " of " << org_name << "\n";
  std::cout << "Linus Torvalds is currently " << linus_position << " of " << org_name << "\n";
  return 0;
}
