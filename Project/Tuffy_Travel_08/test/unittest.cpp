#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../route.hpp"
#include "gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::Not;

class SaveFile : public UnitTestFileManager {
protected:
  SaveFile() : UnitTestFileManager("save.txt") {}
  void SetUp() override {
    UnitTestFileManager::SetUp();

    routes[0] = new Route("57x Brea Mall Xpress", 1623, 1637);
    routes[1] = new CheckedRoute("Delta LAX-ATL", 1642, 1742, 2250);
    routes[2] = new Route("57x Brea Mall Xpress", 1648, 1702);
  }
  Route* routes[3];
};

class DriverSaveFile : public SaveFile {};

class LoadFile : public UnitTestFileManager {
protected:
  LoadFile() : UnitTestFileManager("load.txt") {}
  void SetUp() override {
    UnitTestFileManager::SetUp();

    routes[0] = new Route("57x Brea Mall Xpress", 1623, 1637);
    routes[1] = new CheckedRoute("Delta LAX-ATL", 1642, 1742, 2250);
    routes[2] = new Route("57x Brea Mall Xpress", 1648, 1702);
  }
  Route* routes[3];
};

class DriverLoadFile : public LoadFile {
protected:
  void SetUp() override {
    LoadFile::SetUp();
    std::ofstream out_file("load.txt");
    out_file << 3 << "\n";
    for (int i = 0; i < 3; i++) {
      if (i == 0 || i == 2) {
        out_file << "[Route]\n";
        out_file << routes[i]->name() << "\n";
        out_file << routes[i]->departure_time() << "\n";
        out_file << routes[i]->arrival_time() << "\n";
      } else {
        out_file << "[CheckedRoute]\n";
        out_file << routes[i]->name() << "\n";
        out_file << routes[i]->departure_time() << "\n";
        out_file << ((CheckedRoute*)routes[i])->take_off_time() << "\n";
        out_file << routes[i]->arrival_time() << "\n";
      }
    }
    out_file.close();
  }
};

class DisplayRoutes : public ::testing::Test {
protected:
  void SetUp() override {
    routes[0] = new Route("57x Brea Mall Xpress", 1623, 1637);
    routes[1] = new CheckedRoute("Delta LAX-ATL", 1642, 1742, 2250);
    routes[2] = new Route("57x Brea Mall Xpress", 1648, 1702);
  }

  Route* routes[3];
};

class FindRoute : public DisplayRoutes {
protected:
  void SetUp() override {
    DisplayRoutes::SetUp();
    best_first[0] = routes[1];
    best_first[1] = routes[0];
    best_first[2] = routes[2];

    best_second[0] = routes[2];
    best_second[1] = routes[1];
    best_second[2] = routes[0];

    best_last[0] = routes[0];
    best_last[1] = routes[2];
    best_last[2] = routes[1];
  }

  Route* best_first[3];
  Route* best_second[3];
  Route* best_last[3];
};

TEST(Route, NameAccessorMutator) {
  Route your_route;
  std::string name = "57x Brea Mall Xpress";
  your_route.set_name(name);
  ASSERT_EQ(your_route.name(), "57x Brea Mall Xpress")
      << "Hint: The mutator was used to set the name to 57x Brea Mall Xpress "
         "so the accessor needs to return the same value.";
}

TEST(Route, DepartureTimeAccessorMutator) {
  Route your_route;
  unsigned short int departure_time = 1623;
  your_route.set_departure_time(departure_time);
  ASSERT_EQ(your_route.departure_time(), 1623)
      << "Hint: The mutator was used to set the departure time to 1623 so the "
         "accessor needs to return the same value.";
}

TEST(Route, ArrivalTimeAccessorMutator) {
  Route your_route;
  unsigned short int arrival_time = 1637;
  your_route.set_arrival_time(arrival_time);
  ASSERT_EQ(your_route.arrival_time(), 1637)
      << "Hint: The mutator was used to set the arrival time to 1637 so the "
         "accessor needs to return the same value.";
}

TEST(Route, DefaultConstructor) {
  Route your_route;
  ASSERT_EQ(your_route.name(), "Home")
      << "Hint: The default name of the route should be Home.";
  ASSERT_EQ(your_route.departure_time(), 2000)
      << "Hint: The default departure time of the route should be 2000";
  ASSERT_EQ(your_route.arrival_time(), 2200)
      << "Hint: The default arrival time of the route should be 2200";
}

TEST(Route, NonDefaultConstructor) {
  Route your_route("26 Fullerton Park", 1622, 1636);
  ASSERT_EQ(your_route.name(), "26 Fullerton Park")
      << "Hint: The nondefault constructor should have set the name of the "
         "route to 26 Fullerton Park.";
  ASSERT_EQ(your_route.departure_time(), 1622)
      << "Hint: The nondefault constructor should have set the departure time "
         "of the route to 1622";
  ASSERT_EQ(your_route.arrival_time(), 1636)
      << "Hint: The nondefault constructor should have set the arrival time of "
         "the route to 1636";
}

TEST(CheckedRoute, Inheritance) {
  CheckedRoute your_checked_route;
  Route* your_route = dynamic_cast<Route*>(&your_checked_route);
  ASSERT_NE(your_route, nullptr)
      << "The CheckedRoute class should inherit from the Route class.";
}

TEST(CheckedRoute, AccessorsMutators) {
  CheckedRoute your_checked_route;
  your_checked_route.set_take_off_time(1111);
  ASSERT_EQ(your_checked_route.take_off_time(), 1111)
      << "Hint: The mutator was used to set the take off time to 1111 so the "
         "accessor needs to return the same value.";
}

TEST(CheckedRoute, NonDefaultConstructor) {
  CheckedRoute your_checked_route("Delta LAX-ATL", 535, 635, 1101);
  ASSERT_EQ(your_checked_route.name(), "Delta LAX-ATL")
      << "Hint: The nondefault constructor should have set the name of the "
         "route to Delta LAX-ATL.";
  ASSERT_EQ(your_checked_route.departure_time(), 535)
      << "Hint: The nondefault constructor should have set the departure time "
         "of the route to 535";
  ASSERT_EQ(your_checked_route.take_off_time(), 635)
      << "Hint: The nondefault constructor should have set the take off time "
         "of the route to 635";
  ASSERT_EQ(your_checked_route.arrival_time(), 1101)
      << "Hint: The nondefault constructor should have set the arrival time of "
         "the route to 1101";
}

TEST(CheckedRoute, DefaultConstructor) {
  CheckedRoute your_checked_route;
  ASSERT_EQ(your_checked_route.name(), "Home")
      << "Hint: The default name of the route should be Home.";
  ASSERT_EQ(your_checked_route.departure_time(), 2000)
      << "Hint: The default departure time of the route should be 2000";
  ASSERT_EQ(your_checked_route.take_off_time(), 2010)
      << "Hint: The default constructor should have set the take off time of "
         "the route to 2010";
  ASSERT_EQ(your_checked_route.arrival_time(), 2200)
      << "Hint: The default arrival time of the route should be 2200";
}

TEST(CheckedRoute, Display) {
  CheckedRoute* your_checked_route =
      new CheckedRoute("Delta LAX-ATL", 535, 635, 1101);
  ASSERT_DURATION_LE(
      3, {SIMULATE_SIO("", your_checked_route->display(), {
        ASSERT_THAT(your_output, HasSubstr("Delta LAX-ATL"))
            << "Hint: The member function should display the checked route's "
               "name, Delta LAX-ATL, on the screen.";
        ASSERT_THAT(your_output, HasSubstr("535"))
            << "Hint: The member function should display the checked route's "
               "departure time, 535, on the screen.";
        ASSERT_THAT(your_output, HasSubstr("635"))
            << "Hint: The member function should display the checked route's "
               "take off time, 635, on the screen.";
        ASSERT_THAT(your_output, HasSubstr("1101"))
            << "Hint: The member function should display the checked route's "
               "arrival time, 1101, on the screen.";
      })})
  delete your_checked_route;
}

TEST(CheckedRoute, SaveString) {
  CheckedRoute* your_checked_route =
      new CheckedRoute("Delta LAX-ATL", 535, 635, 1101);
  ASSERT_THAT(your_checked_route->save_string(), HasSubstr("[CheckedRoute]"))
      << "Hint: The member function should return the type of the route, "
         "[CheckedRoute].";
  ASSERT_THAT(your_checked_route->save_string(), HasSubstr("Delta LAX-ATL"))
      << "Hint: The member function should return the checked route's name, "
         "Delta LAX-ATL, on the screen.";
  ASSERT_THAT(your_checked_route->save_string(), HasSubstr("535"))
      << "Hint: The member function should return the checked route's "
         "departure time, 535, on the screen.";
  ASSERT_THAT(your_checked_route->save_string(), HasSubstr("635"))
      << "Hint: The member function should return the checked route's take off "
         "time, 635, on the screen.";
  ASSERT_THAT(your_checked_route->save_string(), HasSubstr("1101"))
      << "Hint: The member function should return the checked route's arrival "
         "time, 1101, on the screen.";
  delete your_checked_route;
}

TEST(ConnectionRoute, Inheritance) {
  ConnectionRoute your_connection_route;
  Route* your_route = dynamic_cast<Route*>(&your_connection_route);
  ASSERT_NE(your_route, nullptr)
      << "The ConnectionRoute class should inherit from the Route class.";
}

TEST(ConnectionRoute, AccessorsMutators) {
  ConnectionRoute your_connection_route;
  your_connection_route.set_source_route("G Shuttle to LAX Terminals");
  your_connection_route.set_destination_route("Delta LAX-ATL");
  ASSERT_EQ(your_connection_route.source_route(), "G Shuttle to LAX Terminals")
      << "Hint: The mutator was used to set the source to G Shuttle to LAX "
         "Terminals so the accessor needs to return the same value.";
  ASSERT_EQ(your_connection_route.destination_route(), "Delta LAX-ATL")
      << "Hint: The mutator was used to set the destination to Delta LAX-ATL "
         "so the accessor needs to return the same value.";
}

TEST(ConnectionRoute, NonDefaultConstructor) {
  ConnectionRoute your_connection_route("Walk to LAX airport",
                                        "G Shuttle to LAX Terminals",
                                        "Delta LAX-ATL", 1523, 1524);
  ASSERT_EQ(your_connection_route.name(), "Walk to LAX airport")
      << "Hint: The nondefault constructor should have set the name of the "
         "route to Walk to LAX airport";
  ASSERT_EQ(your_connection_route.source_route(), "G Shuttle to LAX Terminals")
      << "Hint: The nondefault constructor should have set the source to G "
         "Shuttle to LAX Terminals.";
  ASSERT_EQ(your_connection_route.destination_route(), "Delta LAX-ATL")
      << "Hint: The nondefault constructor should have set the destination to "
         "Delta LAX-ATL.";
  ASSERT_EQ(your_connection_route.departure_time(), 1523)
      << "Hint: The nondefault constructor should have set the departure time "
         "of the route to 1523";
  ASSERT_EQ(your_connection_route.arrival_time(), 1524)
      << "Hint: The nondefault constructor should have set the arrival time of "
         "the route to 1524";
}

TEST(ConnectionRoute, DefaultConstructor) {
  ConnectionRoute your_connection_route;
  ASSERT_EQ(your_connection_route.name(), "Walk to bus")
      << "Hint: The default constructor should have set the name of the route "
         "to Walk to bus";
  ASSERT_EQ(your_connection_route.source_route(), "Home")
      << "Hint: The default constructor should have set the source to Home.";
  ASSERT_EQ(your_connection_route.destination_route(), "Bus stop")
      << "Hint: The default constructor should have set the destination to Bus "
         "stop.";
  ASSERT_EQ(your_connection_route.departure_time(), 800)
      << "Hint: The default constructor should have set the departure time of "
         "the route to 800";
  ASSERT_EQ(your_connection_route.arrival_time(), 805)
      << "Hint: The default constructor should have set the arrival time of "
         "the route to 805";
}

TEST(ConnectionRoute, Display) {
  ConnectionRoute* your_connection_route =
      new ConnectionRoute("Walk to LAX airport", "G Shuttle to LAX Terminals",
                          "Delta LAX-ATL", 1523, 1524);
  ASSERT_DURATION_LE(
      3, {SIMULATE_SIO("", your_connection_route->display(), {
        ASSERT_THAT(your_output, HasSubstr("Walk to LAX airport"))
            << "Hint: The member function should display the connection "
               "route's name, Walk to LAX airport, on the screen.";
        ASSERT_THAT(your_output, HasSubstr("G Shuttle to LAX Terminals"))
            << "Hint: The member function should display the connection "
               "route's source, G Shuttle to LAX Terminals, on the screen.";
        ASSERT_THAT(your_output, HasSubstr("Delta LAX-ATL"))
            << "Hint: The member function should display the connection "
               "route's destination, Delta LAX-ATL, on the screen.";
        ASSERT_THAT(your_output, HasSubstr("1523"))
            << "Hint: The member function should display the connection "
               "route's departure time, 1523, on the screen.";
        ASSERT_THAT(your_output, HasSubstr("1524"))
            << "Hint: The member function should display the connection "
               "route's arrival time, 1524, on the screen.";
      })})
  delete your_connection_route;
}

TEST(ConnectionRoute, SaveString) {
  ConnectionRoute* your_connection_route =
      new ConnectionRoute("Walk to LAX airport", "G Shuttle to LAX Terminals",
                          "Delta LAX-ATL", 1523, 1524);
  ASSERT_THAT(your_connection_route->save_string(),
              HasSubstr("[ConnectionRoute]"))
      << "Hint: The member function should return the type of the route, "
         "[ConnectionRoute].";
  ASSERT_THAT(your_connection_route->save_string(), HasSubstr("Delta LAX-ATL"))
      << "Hint: The member function should return the connection route's "
         "source, G Shuttle to LAX Terminals, on the screen.";
  ASSERT_THAT(your_connection_route->save_string(), HasSubstr("Delta LAX-ATL"))
      << "Hint: The member function should return the connection route's "
         "destination, Delta LAX-ATL, on the screen.";
  ASSERT_THAT(your_connection_route->save_string(), HasSubstr("1523"))
      << "Hint: The member function should return the connection route's "
         "departure time, 1523, on the screen.";
  ASSERT_THAT(your_connection_route->save_string(), HasSubstr("1524"))
      << "Hint: The member function should return the connection route's "
         "arrival time, 1524, on the screen.";
  delete your_connection_route;
}

TEST(RouteManager, DefaultConstructor) { RouteManager your_route_manager; }

TEST(RouteManager, AddRoute) {
  RouteManager your_route_manager;
  Route* your_route = new Route;
  your_route_manager.add(your_route);
}

TEST(RouteManager, AddCheckedRoute) {
  RouteManager your_route_manager;
  CheckedRoute* your_checked_route = new CheckedRoute;
  your_route_manager.add(your_checked_route);
}

TEST(Route, Display) {
  Route* your_route = new Route("57x Brea Mall Xpress", 1623, 1637);
  ASSERT_DURATION_LE(
      3, {SIMULATE_SIO("", your_route->display(), {
        ASSERT_THAT(your_output, HasSubstr("57x Brea Mall Xpress"))
            << "Hint: The member function should display the route's name, 57x "
               "Brea Mall Xpress, on the screen.";
        ASSERT_THAT(your_output, HasSubstr("1623"))
            << "Hint: The member function should display the route's departure "
               "time, 1623, on the screen.";
        ASSERT_THAT(your_output, HasSubstr("1637"))
            << "Hint: The member function should display the route's arrival "
               "time, 1637, on the screen.";
      })})
  delete your_route;
}

TEST(Route, SaveString) {
  Route* your_route = new Route("57x Brea Mall Xpress", 1623, 1637);
  ASSERT_THAT(your_route->save_string(), HasSubstr("[Route]"))
      << "Hint: The member function should return the type of the route, "
         "[Route].";
  ASSERT_THAT(your_route->save_string(), HasSubstr("57x Brea Mall Xpress"))
      << "Hint: The member function should return the route's name, 57x Brea "
         "Mall Xpress, on the screen.";
  ASSERT_THAT(your_route->save_string(), HasSubstr("1623"))
      << "Hint: The member function should return the route's departure time, "
         "1623, on the screen.";
  ASSERT_THAT(your_route->save_string(), HasSubstr("1637"))
      << "Hint: The member function should return the route's arrival time, "
         "1637, on the screen.";
  delete your_route;
}

TEST(CreateCheckedRoute, CheckName) {
  CheckedRoute* your_checked_route;
  SIMULATE_CIN("Delta LAX-ATL\n535\n635\n\n1101\n",
               { your_checked_route = create_checked_route(); });
  ASSERT_EQ(your_checked_route->name(), "Delta LAX-ATL")
      << "Hint: The function should assign Delta LAX-ATL as the name for the "
         "CheckedRoute object.";
  delete your_checked_route;
}

TEST(CreateCheckedRoute, CheckDepartureTime) {
  CheckedRoute* your_checked_route;
  SIMULATE_CIN("Delta LAX-ATL\n535\n635\n\n1101\n",
               { your_checked_route = create_checked_route(); });
  ASSERT_EQ(your_checked_route->departure_time(), 535)
      << "Hint: The function should assign 535 as the departure time for the "
         "CheckedRoute object.";
  delete your_checked_route;
}

TEST(CreateCheckedRoute, CheckTakeOffTime) {
  CheckedRoute* your_checked_route;
  SIMULATE_CIN("Delta LAX-ATL\n535\n635\n\n1101\n",
               { your_checked_route = create_checked_route(); });
  ASSERT_EQ(your_checked_route->take_off_time(), 635)
      << "Hint: The function should assign 635 as the arrival time for the "
         "CheckedRoute object.";
  delete your_checked_route;
}

TEST(CreateCheckedRoute, CheckArrivalTime) {
  CheckedRoute* your_checked_route;
  SIMULATE_CIN("Delta LAX-ATL\n535\n635\n\n1101\n",
               { your_checked_route = create_checked_route(); });
  ASSERT_EQ(your_checked_route->arrival_time(), 1101)
      << "Hint: The function should assign 1101 as the take off time for the "
         "CheckedRoute object.";
  delete your_checked_route;
}

TEST(CreateConnectionRoute, CheckSource) {
  ConnectionRoute* your_connection_route;
  SIMULATE_CIN("Walk to LAX airport\nG Shuttle to LAX Terminals\nDelta "
               "LAX-ATL\n1523\n1524\n",
               { your_connection_route = create_connection_route(); });
  ASSERT_EQ(your_connection_route->source_route(), "G Shuttle to LAX Terminals")
      << "Hint: The function should assign Delta G Shuttle to LAX Terminals as "
         "the source for the "
         "ConnectionRoute object.";
  delete your_connection_route;
}

TEST(CreateConnectionRoute, CheckDestination) {
  ConnectionRoute* your_connection_route;
  SIMULATE_CIN("Walk to LAX airport\nG Shuttle to LAX Terminals\nDelta "
               "LAX-ATL\n1523\n1524\n",
               { your_connection_route = create_connection_route(); });
  ASSERT_EQ(your_connection_route->destination_route(), "Delta LAX-ATL")
      << "Hint: The function should assign Delta LAX-ATL as the destination "
         "for the ConnectionRoute object.";
  delete your_connection_route;
}

TEST_F(DisplayRoutes, OneRoute) {
  RouteManager your_route_manager;
  your_route_manager.add(routes[0]);

  ASSERT_DURATION_LE(
      3, {SIMULATE_SIO("", your_route_manager.display_routes(), {
        ASSERT_THAT(your_output, HasSubstr("57x Brea Mall Xpress"))
            << "Hint: The member function should display the first route's "
               "name, 57x Brea Mall Xpress, on the screen.";
        ASSERT_THAT(your_output, HasSubstr("1623"))
            << "Hint: The member function should display the first route's "
               "departure time, 1623, on the screen.";
        ASSERT_THAT(your_output, HasSubstr("1637"))
            << "Hint: The member function should display the first route's "
               "arrival time, 1637, on the screen.";

        ASSERT_THAT(your_output, Not(HasSubstr("153 Brea Mall")))
            << "Hint: The member function should not display other routes' "
               "names.";
        ASSERT_THAT(your_output, Not(HasSubstr("1642")))
            << "Hint: The member function should not display other routes' "
               "departure time.";
        ASSERT_THAT(your_output, Not(HasSubstr("1703")))
            << "Hint: The member function should not display other routes' "
               "arrival time.";

        ASSERT_THAT(your_output, Not(HasSubstr("1648")))
            << "Hint: The member function should not display other routes' "
               "departure time.";
        ASSERT_THAT(your_output, Not(HasSubstr("1702")))
            << "Hint: The member function should not display other routes' "
               "arrival time.";
      })})
}

TEST_F(DisplayRoutes, MultipleRoutes) {
  RouteManager your_route_manager;
  your_route_manager.add(routes[0]);
  your_route_manager.add(routes[1]);
  your_route_manager.add(routes[2]);

  ASSERT_DURATION_LE(
      3, {SIMULATE_SIO("", your_route_manager.display_routes(), {
        ASSERT_THAT(your_output, HasSubstr("57x Brea Mall Xpress"))
            << "Hint: The member function should display the first route's "
               "name, 57x Brea Mall Xpress, on the screen.";
        ASSERT_THAT(your_output, HasSubstr("1623"))
            << "Hint: The member function should display the first route's "
               "departure time, 1623, on the screen.";
        ASSERT_THAT(your_output, HasSubstr("1637"))
            << "Hint: The member function should display the first route's "
               "arrival time, 1637, on the screen.";

        ASSERT_THAT(your_output, HasSubstr("Delta LAX-ATL"))
            << "Hint: The member function should display the second routes' "
               "name";
        ASSERT_THAT(your_output, HasSubstr("1642"))
            << "Hint: The member function should display the second routes' "
               "departure time.";
        ASSERT_THAT(your_output, HasSubstr("1742"))
            << "Hint: The member function should display the second routes' "
               "take off time.";
        ASSERT_THAT(your_output, HasSubstr("2250"))
            << "Hint: The member function should display the second routes' "
               "arrival time.";

        ASSERT_THAT(your_output, HasSubstr("1648"))
            << "Hint: The member function should display the third routes' "
               "departure time.";
        ASSERT_THAT(your_output, HasSubstr("1702"))
            << "Hint: The member function should display the third routes' "
               "arrival time.";
      })})
}

TEST(GetTimeToLeave, Time1) {
  unsigned short int your_result = 0;
  SIMULATE_SIO("1100", your_result = get_time_to_leave(), {
    ASSERT_THAT(your_result, 1100)
        << "Hint: The function should return the value provided by the user.";
  })
}

TEST(GetTimeToLeave, Time2) {
  unsigned short int your_result = 0;
  SIMULATE_SIO("2200", your_result = get_time_to_leave(), {
    ASSERT_THAT(your_result, 2200)
        << "Hint: The function should return the value provided by the user.";
  })
}

TEST_F(FindRoute, NoRoutes) {
  RouteManager your_route_manager;
  SIMULATE_SIO("", your_route_manager.find_route(1000), {
    ASSERT_THAT(
        your_output,
        MatchesRegex(R"(.*(no routes available|No routes available).*)"))
        << "Hint: The function should say that no routes are available if the "
           "routes array is empty.";
  })
}

TEST_F(FindRoute, OneRouteNoMatch) {
  RouteManager your_route_manager;
  your_route_manager.add(routes[0]);
  SIMULATE_SIO("", your_route_manager.find_route(1800), {
    ASSERT_THAT(
        your_output,
        MatchesRegex(
            R"(.*(no route that leaves on or after|No route that leaves on or after).*)"))
        << "Hint: The function should tell the user that no routes leave on or "
           "after their intended time to leave.";
  })
}

TEST_F(FindRoute, TwoRoutesNoMatch) {
  RouteManager your_route_manager;
  your_route_manager.add(routes[0]);
  your_route_manager.add(routes[1]);
  SIMULATE_SIO("", your_route_manager.find_route(1800), {
    ASSERT_THAT(
        your_output,
        MatchesRegex(
            R"(.*(no route that leaves on or after|No route that leaves on or after).*)"))
        << "Hint: The function should tell the user that no routes leave on or "
           "after their intended time to leave.";
  })
}

TEST_F(FindRoute, MultipleRoutesNoMatch) {
  RouteManager your_route_manager;
  your_route_manager.add(routes[0]);
  your_route_manager.add(routes[1]);
  your_route_manager.add(routes[2]);
  SIMULATE_SIO("", your_route_manager.find_route(1800), {
    ASSERT_THAT(
        your_output,
        MatchesRegex(
            R"(.*(no route that leaves on or after|No route that leaves on or after).*)"))
        << "Hint: The function should tell the user that no routes leave on or "
           "after their intended time to leave.";
  })
}

TEST(Input, CreateExit) {
  std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(FindRoute, OneRouteMatch) {
  RouteManager your_route_manager;
  your_route_manager.add(routes[0]);
  SIMULATE_SIO("", your_route_manager.find_route(1600), {
    ASSERT_THAT(your_output, HasSubstr("57x Brea Mall Xpress"))
        << "Your program should show the best route's name 57x Brea Mall "
           "Xpress.";
    ASSERT_THAT(your_output, HasSubstr("1623"))
        << "Your program should show the best route's departure time, 1623.";
    ASSERT_THAT(your_output, HasSubstr("1637"))
        << "Your program should show the best route's arrival time 1637.";
  })
}

TEST_F(FindRoute, MultipleRoutesBestFirst) {
  RouteManager your_route_manager;
  your_route_manager.add(best_first[0]);
  your_route_manager.add(best_first[1]);
  your_route_manager.add(best_first[2]);
  SIMULATE_SIO("", your_route_manager.find_route(1630), {
    ASSERT_THAT(your_output, HasSubstr("Delta LAX-ATL"))
        << "Your program should show the best route's name 153 Brea Mall.";
    ASSERT_THAT(your_output, HasSubstr("1642"))
        << "Your program should show the best route's departure time, 1642.";
    ASSERT_THAT(your_output, HasSubstr("1742"))
        << "Your program should show the best route's take off time, 1742.";
    ASSERT_THAT(your_output, HasSubstr("2250"))
        << "Your program should show the best route's arrival time 2250.";
  })
}

TEST_F(FindRoute, MultipleRoutesBestSecond) {
  RouteManager your_route_manager;
  your_route_manager.add(best_second[0]);
  your_route_manager.add(best_second[1]);
  your_route_manager.add(best_second[2]);
  SIMULATE_SIO("", your_route_manager.find_route(1630), {
    ASSERT_THAT(your_output, HasSubstr("Delta LAX-ATL"))
        << "Your program should show the best route's name 153 Brea Mall.";
    ASSERT_THAT(your_output, HasSubstr("1642"))
        << "Your program should show the best route's departure time, 1642.";
    ASSERT_THAT(your_output, HasSubstr("1742"))
        << "Your program should show the best route's take off time, 1742.";
    ASSERT_THAT(your_output, HasSubstr("2250"))
        << "Your program should show the best route's arrival time 2250.";
  })
}

TEST_F(FindRoute, MultipleRoutesBestLast) {
  RouteManager your_route_manager;
  your_route_manager.add(best_last[0]);
  your_route_manager.add(best_last[1]);
  your_route_manager.add(best_last[2]);
  SIMULATE_SIO("", your_route_manager.find_route(1630), {
    ASSERT_THAT(your_output, HasSubstr("Delta LAX-ATL"))
        << "Your program should show the best route's name 153 Brea Mall.";
    ASSERT_THAT(your_output, HasSubstr("1642"))
        << "Your program should show the best route's departure time, 1642.";
    ASSERT_THAT(your_output, HasSubstr("1742"))
        << "Your program should show the best route's take off time, 1742.";
    ASSERT_THAT(your_output, HasSubstr("2250"))
        << "Your program should show the best route's arrival time 2250.";
  })
}

TEST(GetFilename, Filename1) {
  std::string your_filename;
  SIMULATE_SIO(
      "routes.txt", { your_filename = get_filename(); },
      {
        ASSERT_THAT(your_filename, "routes.txt")
            << "The filename should be the string that the user input, "
               "routes.txt.";
      })
}

TEST(GetFilename, Filename2) {
  std::string your_filename;
  SIMULATE_SIO(
      "data.txt", { your_filename = get_filename(); },
      {
        ASSERT_THAT(your_filename, "data.txt")
            << "The filename should be the string that the user input, "
               "data.txt.";
      })
}

TEST_F(SaveFile, CreateFile) {
  RouteManager your_route_manager;
  your_route_manager.add(routes[0]);
  your_route_manager.add(routes[1]);
  your_route_manager.add(routes[2]);
  ASSERT_DURATION_LE(
      3,
      {SIMULATE_SIO("", { your_route_manager.save_routes("save.txt"); }, {})})
  std::ifstream your_file;
  your_file.open("save.txt");
  ASSERT_TRUE(your_file.good())
      << "      The function should create a file using the filename provided "
         "by the user. In this case, save.txt.";
}

TEST_F(SaveFile, OneRoute) {
  RouteManager your_route_manager;
  your_route_manager.add(routes[0]);
  ASSERT_DURATION_LE(
      3,
      {SIMULATE_SIO("", { your_route_manager.save_routes("save.txt"); }, {})})

  std::ifstream your_file;
  your_file.open("save.txt");

  ASSERT_TRUE(your_file.good())
      << "      The function should create a file using the filename provided "
         "by the user. In this case, save.txt.";

  int your_file_size = 0;

  your_file >> your_file_size;
  your_file.ignore();

  ASSERT_EQ(your_file_size, 1) << "      The function should store 1 for the "
                                  "number of routes in the file.";

  std::string your_file_route_type;
  std::string your_file_route_name;
  unsigned short int your_file_departure_time;
  unsigned short int your_file_arrival_time;

  std::getline(your_file, your_file_route_type);

  ASSERT_EQ(your_file_route_type, "[Route]")
      << "      The function should save the type of the first route to be "
         "[Route]";

  std::getline(your_file, your_file_route_name);

  ASSERT_EQ(your_file_route_name, "57x Brea Mall Xpress")
      << "      The function should save the name of the first route, 57x Brea "
         "Mall Xpress";

  your_file >> your_file_departure_time;

  ASSERT_EQ(your_file_departure_time, 1623)
      << "      The function should save the departure time of the first "
         "route, 1623";

  your_file >> your_file_arrival_time;

  ASSERT_EQ(your_file_arrival_time, 1637)
      << "      The function should save the arrival time of the first route, "
         "1637";

  your_file.close();
}

TEST_F(SaveFile, ThreeRoutes) {
  RouteManager your_route_manager;
  your_route_manager.add(routes[0]);
  your_route_manager.add(routes[1]);
  your_route_manager.add(routes[2]);
  ASSERT_DURATION_LE(
      3,
      {SIMULATE_SIO("", { your_route_manager.save_routes("save.txt"); }, {})})

  std::ifstream your_file;
  your_file.open("save.txt");

  ASSERT_TRUE(your_file.good())
      << "      The function should create a file using the filename provided "
         "by the user. In this case, save.txt.";

  int your_file_size = 0;

  your_file >> your_file_size;
  your_file.ignore();

  ASSERT_EQ(your_file_size, 3) << "      The function should store 3 for the "
                                  "number of routes in the file.";

  std::string your_file_route_type;
  std::string your_file_route_name;
  unsigned short int your_file_departure_time;
  unsigned short int your_file_takeoff_time;
  unsigned short int your_file_arrival_time;

  std::getline(your_file, your_file_route_type);
  ASSERT_EQ(your_file_route_type, "[Route]")
      << "      The function should save the type of the first route to be "
         "[Route]";

  // first route
  std::getline(your_file, your_file_route_name);

  ASSERT_EQ(your_file_route_name, "57x Brea Mall Xpress")
      << "      The function should save the name of the first route, 57x Brea "
         "Mall Xpress";

  your_file >> your_file_departure_time;

  ASSERT_EQ(your_file_departure_time, 1623)
      << "      The function should save the departure time of the first "
         "route, 1623";

  your_file >> your_file_arrival_time;
  your_file.ignore();

  ASSERT_EQ(your_file_arrival_time, 1637)
      << "      The function should save the arrival time of the first route, "
         "1637";

  // second route
  std::getline(your_file, your_file_route_type);
  ASSERT_EQ(your_file_route_type, "[CheckedRoute]")
      << "      The function should save the type of the first route to be "
         "[CheckedRoute]";

  std::getline(your_file, your_file_route_name);

  ASSERT_EQ(your_file_route_name, "Delta LAX-ATL")
      << "      The function should save the name of the second route, Delta "
         "LAX-ATL";

  your_file >> your_file_departure_time;

  ASSERT_EQ(your_file_departure_time, 1642)
      << "      The function should save the departure time of the second "
         "route, 1642";

  your_file >> your_file_takeoff_time;
  your_file.ignore();

  ASSERT_EQ(your_file_takeoff_time, 1742)
      << "      The function should save the take off time of the second "
         "route, 1742";

  your_file >> your_file_arrival_time;
  your_file.ignore();

  ASSERT_EQ(your_file_arrival_time, 2250)
      << "      The function should save the arrival time of the second route, "
         "2250";

  // third route
  std::getline(your_file, your_file_route_type);
  ASSERT_EQ(your_file_route_type, "[Route]")
      << "      The function should save the type of the first route to be "
         "[Route]";

  std::getline(your_file, your_file_route_name);

  ASSERT_EQ(your_file_route_name, "57x Brea Mall Xpress")
      << "      The function should save the name of the third route, 57x Brea "
         "Mall Xpress";

  your_file >> your_file_departure_time;

  ASSERT_EQ(your_file_departure_time, 1648)
      << "      The function should save the departure time of the third "
         "route, 1648";

  your_file >> your_file_arrival_time;

  ASSERT_EQ(your_file_arrival_time, 1702)
      << "      The function should save the arrival time of the third route, "
         "1702";

  your_file.close();
}

TEST(LoadFile_, NoFile) {
  RouteManager your_route_manager;

  SIMULATE_SIO(
      "", { your_route_manager.load_routes("nonexistentfile.txt"); },
      {
        ASSERT_THAT(your_output, HasSubstr("does not exist"))
            << "      The function should show an error if the file to be "
               "loaded does not exist.";
      })
}

TEST_F(LoadFile, OneRoute) {
  std::ofstream your_file;
  your_file.open("load.txt");
  your_file << "1\n[Route]\n57x Brea Mall Xpress\n1623\n1637";
  your_file.close();

  RouteManager your_route_manager;

  ASSERT_DURATION_LE(
      3, {SIMULATE_SIO(
             "",
             {
               your_route_manager.load_routes("load.txt");
               your_route_manager.display_routes();
             },
             {
               ASSERT_THAT(your_output, HasSubstr("57x Brea Mall Xpress"))
                   << "Hint: The member function should display the first "
                      "route's name, 57x Brea Mall Xpress, on the screen.";
               ASSERT_THAT(your_output, HasSubstr("1623"))
                   << "Hint: The member function should display the first "
                      "route's departure time, 1623, on the screen.";
               ASSERT_THAT(your_output, HasSubstr("1637"))
                   << "Hint: The member function should display the first "
                      "route's arrival time, 1637, on the screen.";

               ASSERT_THAT(your_output, Not(HasSubstr("153 Brea Mall")))
                   << "Hint: The member function should not display other "
                      "routes' names.";
               ASSERT_THAT(your_output, Not(HasSubstr("1642")))
                   << "Hint: The member function should not display other "
                      "routes' departure time.";
               ASSERT_THAT(your_output, Not(HasSubstr("1703")))
                   << "Hint: The member function should not display other "
                      "routes' arrival time.";

               ASSERT_THAT(your_output, Not(HasSubstr("1648")))
                   << "Hint: The member function should not display other "
                      "routes' departure time.";
               ASSERT_THAT(your_output, Not(HasSubstr("1702")))
                   << "Hint: The member function should not display other "
                      "routes' arrival time.";
             })})
}

TEST_F(LoadFile, ThreeRoutes) {
  std::ofstream your_file;
  your_file.open("load.txt");
  your_file << "3\n[ConnectionRoute]\nWalk to LAX airport\nG Shuttle to LAX "
               "Terminals\nDelta LAX-ATL\n1523\n1524\n[Route]\n153 Brea "
               "Mall\n1642\n1703\n[Route]\n57x Brea Mall Xpress\n1648\n1702\n";
  your_file.close();

  RouteManager your_route_manager;

  ASSERT_DURATION_LE(
      3,
      {SIMULATE_SIO(
          "",
          {
            your_route_manager.load_routes("load.txt");
            your_route_manager.display_routes();
          },
          {
            ASSERT_THAT(your_output, HasSubstr("Walk to LAX airport"))
                << "Hint: The member function should display the connection "
                   "route's name, Walk to LAX airport, on the screen.";
            ASSERT_THAT(your_output, HasSubstr("G Shuttle to LAX Terminals"))
                << "Hint: The member function should display the connection "
                   "route's source, G Shuttle to LAX Terminals, on the screen.";
            ASSERT_THAT(your_output, HasSubstr("Delta LAX-ATL"))
                << "Hint: The member function should display the connection "
                   "route's destination, Delta LAX-ATL, on the screen.";
            ASSERT_THAT(your_output, HasSubstr("1523"))
                << "Hint: The member function should display the connection "
                   "route's departure time, 1523, on the screen.";
            ASSERT_THAT(your_output, HasSubstr("1524"))
                << "Hint: The member function should display the connection "
                   "route's arrival time, 1524, on the screen.";

            ASSERT_THAT(your_output, HasSubstr("153 Brea Mall"))
                << "Hint: The member function should not display other "
                   "routes' names.";
            ASSERT_THAT(your_output, HasSubstr("1642"))
                << "Hint: The member function should not display other "
                   "routes' departure time.";
            ASSERT_THAT(your_output, HasSubstr("1703"))
                << "Hint: The member function should not display other "
                   "routes' arrival time.";

            ASSERT_THAT(your_output, HasSubstr("1648"))
                << "Hint: The member function should not display other "
                   "routes' departure time.";
            ASSERT_THAT(your_output, HasSubstr("1702"))
                << "Hint: The member function should not display other "
                   "routes' arrival time.";
          })})
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

TEST(Input, CreateCheckedDisplayExit) {
  std::string user_input = "C\nDelta LAX-ATL\n535\n635\n\n1101\nD\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST(Input, DisplayCreateCheckedExit) {
  std::string user_input = "D\nC\nDelta LAX-ATL\n535\n635\n\n1101\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST(Input, CreateDisplayCreateDisplayExit) {
  std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nD\nC\nDelta "
                           "LAX-ATL\n535\n635\n1101\nD\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST(Input, CreateFindExit) {
  std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nD\nR\n57x "
                           "Brea Mall Xpress\n1623\n1637\nF\n1100\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST(Input, FindCreateExit) {
  std::string user_input = "F\n1100\nC\nDelta LAX-ATL\n535\n635\n\n1101\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST(Input, DisplayFindExit) {
  std::string user_input = "D\nF\n1100\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST(Input, FindDisplayExit) {
  std::string user_input = "F\n1100\nD\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverSaveFile, SaveExit) {
  std::string user_input = "S\nsave.txt\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverSaveFile, DisplaySaveExit) {
  std::string user_input = "D\nS\nsave.txt\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverSaveFile, SaveDisplayExit) {
  std::string user_input = "S\nsave.txt\nD\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverSaveFile, SaveCreateExit) {
  std::string user_input =
      "S\nsave.txt\nR\n57x Brea Mall Xpress\n1623\n1637\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverSaveFile, CreateSaveExit) {
  std::string user_input =
      "R\n57x Brea Mall Xpress\n1623\n1637\nS\nsave.txt\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverSaveFile, CreateCheckedSaveExit) {
  std::string user_input =
      "C\nDelta LAX-ATL\n535\n635\n\n1101\nS\nsave.txt\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverSaveFile, FindSaveExit) {
  std::string user_input = "F\n1100\nS\nsave.txt\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverSaveFile, SaveFindExit) {
  std::string user_input = "S\nsave.txt\nF\n1100\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverSaveFile, SaveLoadExit) {
  std::string user_input = "S\nsave.txt\nL\nsave.txt\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverSaveFile, LoadSaveExit) {
  std::string user_input = "L\nsave.txt\nS\nsave.txt\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverLoadFile, LoadExit) {
  std::string user_input = "L\nload.txt\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverLoadFile, DisplayLoadExit) {
  std::string user_input = "D\nL\nload.txt\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverLoadFile, LoadDisplayExit) {
  std::string user_input = "L\nload.txt\nD\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverLoadFile, LoadCreateExit) {
  std::string user_input =
      "L\nload.txt\nR\n57x Brea Mall Xpress\n1623\n1637\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverLoadFile, CreateLoadExit) {
  std::string user_input =
      "R\n57x Brea Mall Xpress\n1623\n1637\nL\nload.txt\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverLoadFile, FindLoadExit) {
  std::string user_input = "F\n1100\nL\nload.txt\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverLoadFile, LoadFindExit) {
  std::string user_input = "L\nload.txt\nF\n1100\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST(Driver, CreateDisplayExit) {
  std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nD\nX\n";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("57x Brea Mall Xpress"))
      << "Your program should show the created route's name 57x Brea Mall "
         "Xpress.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1623"))
      << "Your program should show the created route's departure time, 1623.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1637"))
      << "Your program should show the created route's arrival time 1637.";
}

TEST(Driver, CreateCreateDisplayExit) {
  std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nR\n153 Brea "
                           "Mall\n1642\n1703\nD\nX\n";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("57x Brea Mall Xpress"))
      << "Your program should show the first route's name 57x Brea Mall "
         "Xpress.";
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

TEST(Driver, CreateCreateCheckedDisplayExit) {
  std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nC\nDelta "
                           "LAX-ATL\n535\n635\n\n1101\nD\nX\n";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("57x Brea Mall Xpress"))
      << "Your program should show the first route's name 57x Brea Mall "
         "Xpress.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1623"))
      << "Your program should show the first route's departure time, 1623.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1637"))
      << "Your program should show the first route's arrival time 1637.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("Delta LAX-ATL"))
      << "Your program should show the second route's name Delta LAX-ATL.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("535"))
      << "Your program should show the second route's departure time, 535.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("635"))
      << "Your program should show the second route's takeoff time, 635.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1101"))
      << "Your program should show the second route's arrival time 1101.";
}

TEST(Driver, CreateCreateConnectionDisplayExit) {
  std::string user_input =
      "R\n57x Brea Mall Xpress\n1623\n1637\nT\nWalk to LAX airport\nG Shuttle "
      "to LAX Terminals\nDelta LAX-ATL\n1523\n1524\nD\nX\n";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("57x Brea Mall Xpress"))
      << "Your program should show the first route's name 57x Brea Mall "
         "Xpress.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1623"))
      << "Your program should show the first route's departure time, 1623.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1637"))
      << "Your program should show the first route's arrival time 1637.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("Walk to LAX airport"))
      << "Your program should show the second route's name, Walk to LAX "
         "airport";
  ASSERT_EXECTHAT("tuffytravel", user_input,
                  HasSubstr("G Shuttle to LAX Terminals"))
      << "Your program should show the second route's source, G Shuttle to LAX "
         "Terminals";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("Delta LAX-ATL"))
      << "Your program should show the second route's destination, Delta "
         "LAX-ATL";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1523"))
      << "Your program should show the second route's departure time, 1523";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1524"))
      << "Your program should show the second route's arrival time, 1524";
}

TEST(Driver, CreateCreateCheckedFindExit) {
  std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nC\nDelta "
                           "LAX-ATL\n535\n635\n\n1101\nF\n1600\nX\n";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("57x Brea Mall Xpress"))
      << "Your program should show the first route's name 57x Brea Mall "
         "Xpress.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1623"))
      << "Your program should show the first route's departure time, 1623.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1637"))
      << "Your program should show the first route's arrival time 1637.";
}

TEST_F(DriverSaveFile, CreateCreateCheckedSaveExit) {
  ASSERT_DURATION_LE(3, {
    std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nC\nDelta "
                             "LAX-ATL\n535\n635\n\n1101\nS\nsave.txt\nX\n";
    exec_program("tuffytravel", user_input);
  })

  std::ifstream your_file;
  your_file.open("save.txt");

  ASSERT_TRUE(your_file.good())
      << "      The program should create a file using the filename provided "
         "by the user. In this case, save.txt.";

  int your_file_size = 0;

  your_file >> your_file_size;
  your_file.ignore();

  ASSERT_EQ(your_file_size, 2) << "      The program should store 2 for the "
                                  "number of routes in the file.";

  std::string your_file_route_type;
  std::string your_file_route_name;
  unsigned short int your_file_departure_time;
  unsigned short int your_file_takeoff_time;
  unsigned short int your_file_arrival_time;

  // first route
  std::getline(your_file, your_file_route_type);
  ASSERT_EQ(your_file_route_type, "[Route]")
      << "      The function should save the type of the first route to be "
         "[Route]";

  std::getline(your_file, your_file_route_name);

  ASSERT_EQ(your_file_route_name, "57x Brea Mall Xpress")
      << "      The program should save the name of the first route, 57x Brea "
         "Mall Xpress";

  your_file >> your_file_departure_time;

  ASSERT_EQ(your_file_departure_time, 1623)
      << "      The program should save the departure time of the first route, "
         "1623";

  your_file >> your_file_arrival_time;
  your_file.ignore();

  ASSERT_EQ(your_file_arrival_time, 1637)
      << "      The program should save the arrival time of the first route, "
         "1637";

  // second route
  std::getline(your_file, your_file_route_type);
  ASSERT_EQ(your_file_route_type, "[CheckedRoute]")
      << "      The program should save the type of the first route to be "
         "[CheckedRoute]";

  std::getline(your_file, your_file_route_name);

  ASSERT_EQ(your_file_route_name, "Delta LAX-ATL")
      << "      The program should save the name of the second route, Delta "
         "LAX-ATL";

  your_file >> your_file_departure_time;

  ASSERT_EQ(your_file_departure_time, 535)
      << "      The program should save the departure time of the second "
         "route, 535";

  your_file >> your_file_takeoff_time;
  your_file.ignore();

  ASSERT_EQ(your_file_takeoff_time, 635)
      << "      The program should save the take off time of the second route, "
         "635";

  your_file >> your_file_arrival_time;
  your_file.ignore();

  ASSERT_EQ(your_file_arrival_time, 1101)
      << "      The function should save the arrival time of the second route, "
         "1101";

  your_file.close();
}

TEST_F(DriverLoadFile, LoadDisplayExitOutput) {
  ASSERT_DURATION_LE(3, {
    std::string user_input = "L\nload.txt\nD\nX\n";
    ASSERT_EXECTHAT("tuffytravel", user_input,
                    HasSubstr("57x Brea Mall Xpress"))
        << "Your program should show the first route's name 57x Brea Mall "
           "Xpress.";
    ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1623"))
        << "Your program should show the first route's departure time, 1623.";
    ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1637"))
        << "Your program should show the first route's arrival time 1637.";
    ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("Delta LAX-ATL"))
        << "Your program should show the second route's name Delta LAX-ATL.";
    ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1642"))
        << "Your program should show the second route's departure time, 1642.";
    ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1742"))
        << "Your program should show the second route's takeoff time, 1742.";
    ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("2250"))
        << "Your program should show the second route's arrival time 2250.";

    ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1648"))
        << "Your program should show the second route's departure time, 1648.";
    ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1702"))
        << "Your program should show the second route's arrival time 1702.";
  })
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
