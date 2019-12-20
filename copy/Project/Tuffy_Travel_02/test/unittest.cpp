#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"
#include "../route.hpp"

using ::testing::HasSubstr;

TEST(RouteClass, NameAccessorMutator) {
  Route your_route;
  std::string name = "57x Brea Mall Xpress";
  your_route.set_name(name);
  ASSERT_EQ(your_route.name(), "57x Brea Mall Xpress") << "Hint: The mutator was used to set the name to 57x Brea Mall Xpress so the accessor needs to return the same value.";
}

TEST(CreateRoute, CheckName) {
  Route your_route;
  SIMULATE_CIN("57x Brea Mall Xpress\n1623\n1637\n", { 
    your_route = create_route();
  });
  ASSERT_EQ(your_route.name(), "57x Brea Mall Xpress") << "Hint: The function should assign 57x Brea Mall Xpress as the name for the Route object.";
}

TEST(Input, RetrieveRoutesAndTimes) {
	std::string user_input = "57x Brea Mall Xpress\n1623\n1637\n153 Brea Mall\n1642\n1703\n57x Brea Mall Xpress\n1648\n1702\n1630";
	ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST(Output, ShowBestRoute) {
  std::string user_input = "57x Brea Mall Xpress\n1623\n1637\n153 Brea Mall\n1642\n1703\n57x Brea Mall Xpress\n1648\n1702\n1630";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("153 Brea Mall"))
      << "Your program should select 153 Brea Mall as the best route.";
}

TEST(Output, ShowBestRouteDepartureTime) {
  std::string user_input = "57x Brea Mall Xpress\n1623\n1637\n153 Brea Mall\n1642\n1703\n57x Brea Mall Xpress\n1648\n1702\n1630";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1642"))
      << "Your program should display the departure time of the best route, 1642.";
}

TEST(Output, ShowBestRouteArrivalTime) {
  std::string user_input = "57x Brea Mall Xpress\n1623\n1637\n153 Brea Mall\n1642\n1703\n57x Brea Mall Xpress\n1648\n1702\n1630";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1703"))
      << "Your program should display the arrival time of the best route, 1703.";
}

TEST(Output, DisplayPreferredTimeToLeave) {
  std::string user_input = "57x Brea Mall Xpress\n1623\n1637\n153 Brea Mall\n1642\n1703\n57x Brea Mall Xpress\n1648\n1702\n1630";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1630"))
      << "Your program should remind the user about their preferred time to leave, 1630.";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);    
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
    return RUN_ALL_TESTS();
}
