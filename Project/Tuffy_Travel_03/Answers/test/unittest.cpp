#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"
#include "../route.hpp"

using ::testing::HasSubstr;
using ::testing::Not;
using ::testing::MatchesRegex;

class DisplayRoutes : public ::testing::Test {
protected:
  void SetUp() override {
    routes[0].set_name("57x Brea Mall Xpress");
    routes[0].set_departure_time(1623);
    routes[0].set_arrival_time(1637);

    routes[1].set_name("153 Brea Mall");
    routes[1].set_departure_time(1642);
    routes[1].set_arrival_time(1703);

    routes[2].set_name("57x Brea Mall Xpress");
    routes[2].set_departure_time(1648);
    routes[2].set_arrival_time(1702);
  }

  Route routes[100];
};

TEST(RouteClass, NameAccessorMutator) {
  Route your_route;
  std::string name = "57x Brea Mall Xpress";
  your_route.set_name(name);
  ASSERT_EQ(your_route.name(), "57x Brea Mall Xpress") << "Hint: The mutator was used to set the name to 57x Brea Mall Xpress so the accessor needs to return the same value.";
}

TEST(RouteClass, DepartureTimeAccessorMutator) {
  Route your_route;
  unsigned short int departure_time = 1623;
  your_route.set_departure_time(departure_time);
  ASSERT_EQ(your_route.departure_time(), 1623) << "Hint: The mutator was used to set the departure time to 1623 so the accessor needs to return the same value.";  
}

TEST(RouteClass, ArrivalTimeAccessorMutator) {
  Route your_route;
  unsigned short int arrival_time = 1637;
  your_route.set_arrival_time(arrival_time);
  ASSERT_EQ(your_route.arrival_time(), 1637) << "Hint: The mutator was used to set the arrival time to 1637 so the accessor needs to return the same value.";  
}

TEST(RouteClass, Display) {
  Route your_route;
  your_route.set_name("57x Brea Mall Xpress");
  your_route.set_departure_time(1623);
  your_route.set_arrival_time(1637);
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", your_route.display(), {
      ASSERT_THAT(your_output, HasSubstr("57x Brea Mall Xpress"))
        << "Hint: The member function should display the route's name, 57x Brea Mall Xpress, on the screen.";  
      ASSERT_THAT(your_output, HasSubstr("1623"))
        << "Hint: The member function should display the route's departure time, 1623, on the screen.";      
      ASSERT_THAT(your_output, HasSubstr("1637"))
        << "Hint: The member function should display the route's arrival time, 1637, on the screen.";          
    })
  })
}

TEST(CreateRoute, CheckName) {
  Route your_route;
  SIMULATE_CIN("57x Brea Mall Xpress\n1623\n1637\n", { 
    your_route = create_route();
  });
  ASSERT_EQ(your_route.name(), "57x Brea Mall Xpress") << "Hint: The function should assign 57x Brea Mall Xpress as the name for the Route object.";
}

TEST(CreateRoute, CheckDepartureTime) {
  Route your_route;
  SIMULATE_CIN("57x Brea Mall Xpress\n1623\n1637\n", { 
    your_route = create_route();
  });
  ASSERT_EQ(your_route.departure_time(), 1623) << "Hint: The function should assign 1623 as the departure time for the Route object.";
}

TEST(CreateRoute, CheckArrivalTime) {
  Route your_route;
  SIMULATE_CIN("57x Brea Mall Xpress\n1623\n1637\n", { 
    your_route = create_route();
  });
  ASSERT_EQ(your_route.arrival_time(), 1637) << "Hint: The function should assign 1637 as the arrival time for the Route object.";
}

TEST_F(DisplayRoutes, OneRoute) {
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", display_routes(routes, 1), {
      ASSERT_THAT(your_output, HasSubstr("57x Brea Mall Xpress"))
        << "Hint: The member function should display the first route's name, 57x Brea Mall Xpress, on the screen.";  
      ASSERT_THAT(your_output, HasSubstr("1623"))
        << "Hint: The member function should display the first route's departure time, 1623, on the screen.";      
      ASSERT_THAT(your_output, HasSubstr("1637"))
        << "Hint: The member function should display the first route's arrival time, 1637, on the screen.";          

      ASSERT_THAT(your_output, Not(HasSubstr("153 Brea Mall")))
        << "Hint: The member function should not display other routes' names.";  
      ASSERT_THAT(your_output, Not(HasSubstr("1642")))
        << "Hint: The member function should not display other routes' departure time.";      
      ASSERT_THAT(your_output, Not(HasSubstr("1703")))
        << "Hint: The member function should not display other routes' arrival time.";

      ASSERT_THAT(your_output, Not(HasSubstr("1648")))
        << "Hint: The member function should not display other routes' departure time.";      
      ASSERT_THAT(your_output, Not(HasSubstr("1702")))
        << "Hint: The member function should not display other routes' arrival time.";      
    })
  })
}


TEST(Input, CreateExit) {
	std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nX\n";
	ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST(Input, DisplayExit) {
  std::string user_input = "D\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST(Input, CreateDisplayExit) {
  std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nD\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST(Input, DisplayCreateExit) {
  std::string user_input = "D\nR\n57x Brea Mall Xpress\n1623\n1637\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST(Input, CreateDisplayCreateDisplayExit) {
  std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nD\nR\n57x Brea Mall Xpress\n1623\n1637\nD\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST(Driver, CreateDisplayExit) {
  std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nD\nX\n";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("57x Brea Mall Xpress"))
      << "Your program should show the created route's name 57x Brea Mall Xpress.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1623"))
    << "Your program should show the created route's departure time, 1623.";    
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1637"))
    << "Your program should show the created route's arrival time 1637.";
}

TEST(Driver, CreateCreateDisplayExit) {
  std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nR\n153 Brea Mall\n1642\n1703\nD\nX\n";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("57x Brea Mall Xpress"))
      << "Your program should show the first route's name 57x Brea Mall Xpress.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1623"))
    << "Your program should show the first route's departure time, 1623.";    
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1637"))
    << "Your program should show the first route's arrival time 1637.";
   ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("153 Brea Mall"))
      << "Your program should show the second route's name 153 Brea Mall.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1642"))
    << "Your program should show the second route's departure time, 1642.";    
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1703"))
    << "Your program should show the second route's arrival time 1703.";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);    
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
    return RUN_ALL_TESTS();
}
