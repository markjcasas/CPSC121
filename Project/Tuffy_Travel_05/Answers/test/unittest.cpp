#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"
#include "../route.hpp"

using ::testing::HasSubstr;
using ::testing::Not;
using ::testing::MatchesRegex;

class SaveFile : public UnitTestFileManager {
protected:
  SaveFile() : UnitTestFileManager("save.txt") { }
  void SetUp() override {
    UnitTestFileManager::SetUp();
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
  Route routes[3];
};

class DriverSaveFile: public SaveFile { };

class LoadFile : public UnitTestFileManager {
protected:
  LoadFile() : UnitTestFileManager("load.txt") { }
  void SetUp() override {
    UnitTestFileManager::SetUp();
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
  Route routes[3];
};

class DriverLoadFile: public LoadFile { 
  protected:
    void SetUp() override {
      LoadFile::SetUp();
      std::ofstream out_file("load.txt");
      out_file << 3 << "\n";
      for (int i = 0; i < 3; i++) {
        out_file << routes[i].name() << "\n";
        out_file << routes[i].departure_time() << "\n";
        out_file << routes[i].arrival_time() << "\n";
      }
      out_file.close();
    }
};

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

class FindRoute: public DisplayRoutes { 
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

  Route best_first[3];
  Route best_second[3];
  Route best_last[3];
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

TEST_F(DisplayRoutes, MultipleRoutes) {
  ASSERT_DURATION_LE(3, {
    SIMULATE_SIO("", display_routes(routes, 3), {
      ASSERT_THAT(your_output, HasSubstr("57x Brea Mall Xpress"))
        << "Hint: The member function should display the first route's name, 57x Brea Mall Xpress, on the screen.";  
      ASSERT_THAT(your_output, HasSubstr("1623"))
        << "Hint: The member function should display the first route's departure time, 1623, on the screen.";      
      ASSERT_THAT(your_output, HasSubstr("1637"))
        << "Hint: The member function should display the first route's arrival time, 1637, on the screen.";          

      ASSERT_THAT(your_output, HasSubstr("153 Brea Mall"))
        << "Hint: The member function should not display other routes' names.";  
      ASSERT_THAT(your_output, HasSubstr("1642"))
        << "Hint: The member function should not display other routes' departure time.";      
      ASSERT_THAT(your_output, HasSubstr("1703"))
        << "Hint: The member function should not display other routes' arrival time.";

      ASSERT_THAT(your_output, HasSubstr("1648"))
        << "Hint: The member function should not display other routes' departure time.";      
      ASSERT_THAT(your_output, HasSubstr("1702"))
        << "Hint: The member function should not display other routes' arrival time.";      
    })
  })
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
  SIMULATE_SIO("", find_route(routes, 0, 1000), {
      ASSERT_THAT(your_output, MatchesRegex(R"(.*(no routes available|No routes available).*)"))
        << "Hint: The function should say that no routes are available if the routes array is empty.";  
  })
}

TEST_F(FindRoute, OneRouteNoMatch) {
  SIMULATE_SIO("", find_route(routes, 1, 1800), {
      ASSERT_THAT(your_output, MatchesRegex(R"(.*(no route that leaves on or after|No route that leaves on or after).*)"))
        << "Hint: The function should tell the user that no routes leave on or after their intended time to leave.";  
  })        
}

TEST_F(FindRoute, TwoRoutesNoMatch) {
  SIMULATE_SIO("", find_route(routes, 2, 1800), {
      ASSERT_THAT(your_output, MatchesRegex(R"(.*(no route that leaves on or after|No route that leaves on or after).*)"))
        << "Hint: The function should tell the user that no routes leave on or after their intended time to leave.";  
  })
}

TEST_F(FindRoute, MultipleRoutesNoMatch) {
  SIMULATE_SIO("", find_route(routes, 3, 1800), {
      ASSERT_THAT(your_output, MatchesRegex(R"(.*(no route that leaves on or after|No route that leaves on or after).*)"))
        << "Hint: The function should tell the user that no routes leave on or after their intended time to leave.";  
  })
}

TEST(Input, CreateExit) {
	std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nX\n";
	ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(FindRoute, OneRouteMatch) {
  SIMULATE_SIO("", find_route(routes, 1, 1600), {
      ASSERT_THAT(your_output, HasSubstr("57x Brea Mall Xpress"))
        << "Your program should show the best route's name 57x Brea Mall Xpress.";
      ASSERT_THAT(your_output, HasSubstr("1623"))
        << "Your program should show the best route's departure time, 1623.";    
      ASSERT_THAT(your_output, HasSubstr("1637"))
        << "Your program should show the best route's arrival time 1637.";
  })
}

TEST_F(FindRoute, MultipleRoutesBestFirst) {
  SIMULATE_SIO("", find_route(best_first, 3, 1630), {
      ASSERT_THAT(your_output, HasSubstr("153 Brea Mall"))
        << "Your program should show the best route's name 153 Brea Mall.";
      ASSERT_THAT(your_output, HasSubstr("1642"))
        << "Your program should show the best route's departure time, 1642.";    
      ASSERT_THAT(your_output, HasSubstr("1703"))
        << "Your program should show the best route's arrival time 1703.";
  })
}

TEST_F(FindRoute, MultipleRoutesBestSecond) {
  SIMULATE_SIO("", find_route(best_second, 3, 1630), {
      ASSERT_THAT(your_output, HasSubstr("153 Brea Mall"))
        << "Your program should show the best route's name 153 Brea Mall.";
      ASSERT_THAT(your_output, HasSubstr("1642"))
        << "Your program should show the best route's departure time, 1642.";    
      ASSERT_THAT(your_output, HasSubstr("1703"))
        << "Your program should show the best route's arrival time 1703.";
  })
}

TEST_F(FindRoute, MultipleRoutesBestLast) {
  SIMULATE_SIO("", find_route(best_last, 3, 1630), {
      ASSERT_THAT(your_output, HasSubstr("153 Brea Mall"))
        << "Your program should show the best route's name 153 Brea Mall.";
      ASSERT_THAT(your_output, HasSubstr("1642"))
        << "Your program should show the best route's departure time, 1642.";    
      ASSERT_THAT(your_output, HasSubstr("1703"))
        << "Your program should show the best route's arrival time 1703.";
  })
}

TEST(GetFilename, Filename) {
  std::string your_filename;
  SIMULATE_SIO("routes.txt", {
    your_filename = get_filename();
  }, {
    ASSERT_THAT(your_filename, "routes.txt")
      << "The filename should be the string that the user input, routes.txt.";
  })
}

TEST_F(SaveFile, CreateFile) {  
  ASSERT_DURATION_LE(3, {
    save_routes(routes, 3, "save.txt");
  })
  std::ifstream your_file;
  your_file.open("save.txt");
  ASSERT_TRUE(your_file.good()) << "      The function should create a file using the filename provided by the user. In this case, save.txt.";
}

TEST_F(SaveFile, OneRoute) {
  ASSERT_DURATION_LE(3, {
    save_routes(routes, 1, "save.txt");
  })

  std::ifstream your_file;
  your_file.open("save.txt");

  ASSERT_TRUE(your_file.good()) << "      The function should create a file using the filename provided by the user. In this case, save.txt.";
  
  int your_file_size = 0;

  your_file >> your_file_size;
  your_file.ignore();

  ASSERT_EQ(your_file_size, 1)  << "      The function should store 1 for the number of routes in the file.";

  std::string your_file_route_name;
  unsigned short int your_file_departure_time;
  unsigned short int your_file_arrival_time;

  std::getline(your_file, your_file_route_name);

  ASSERT_EQ(your_file_route_name, "57x Brea Mall Xpress") << "      The function should save the name of the first route, 57x Brea Mall Xpress";

  your_file >>your_file_departure_time;

  ASSERT_EQ(your_file_departure_time, 1623) << "      The function should save the departure time of the first route, 1623";

  your_file >>your_file_arrival_time;

  ASSERT_EQ(your_file_arrival_time, 1637) << "      The function should save the arrival time of the first route, 1637";

  your_file.close();  
}

TEST_F(LoadFile, ThreeRoutes) {
  std::ofstream your_file;
  your_file.open("load.txt");
  your_file << "3\n57x Brea Mall Xpress\n1623\n1637\n153 Brea Mall\n1642\n1703\n57x Brea Mall Xpress\n1648\n1702\n";
  your_file.close();

  Route your_routes[3];
  unsigned int your_routes_size = 0;

  ASSERT_DURATION_LE(3, {
    load_routes(your_routes, your_routes_size, "load.txt");  
  })
  
  ASSERT_EQ(your_routes_size, 3) << "      The function should load the size of the routes array, which is 3.";
  // first route
  ASSERT_EQ(your_routes[0].name(), "57x Brea Mall Xpress") << "      The function should load the name of the first route, 57x Brea Mall Xpress.";
  ASSERT_EQ(your_routes[0].departure_time(), 1623) << "      The function should load the departure time of the first route, 1623.";
  ASSERT_EQ(your_routes[0].arrival_time(), 1637) << "      The function should load the arrival time of the first route, 1637.";
  // second route
  ASSERT_EQ(your_routes[1].name(), "153 Brea Mall") << "      The function should load the name of the second route, 153 Brea Mall.";
  ASSERT_EQ(your_routes[1].departure_time(), 1642) << "      The function should load the departure time of the second route, 1642.";
  ASSERT_EQ(your_routes[1].arrival_time(), 1703) << "      The function should load the arrival time of the second route, 1703.";
  // third route
  ASSERT_EQ(your_routes[2].name(), "57x Brea Mall Xpress") << "      The function should load the name of the third route, 57x Brea Mall Xpress.";
  ASSERT_EQ(your_routes[2].departure_time(), 1648) << "      The function should load the departure time of the third route, 1648.";
  ASSERT_EQ(your_routes[2].arrival_time(), 1702) << "      The function should load the arrival time of the third route, 1702.";  
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

TEST(Input, CreateFindExit) {
  std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nD\nR\n57x Brea Mall Xpress\n1623\n1637\nF\n1100\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST(Input, FindCreateExit) {
  std::string user_input = "F\n1100\nR\n57x Brea Mall Xpress\n1623\n1637\nD\nR\n57x Brea Mall Xpress\n1623\n1637\nX\n";
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
  std::string user_input = "S\nsave.txt\nR\n57x Brea Mall Xpress\n1623\n1637\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverSaveFile, CreateSaveExit) {
  std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nS\nsave.txt\nX\n";
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
  std::string user_input = "L\nload.txt\nR\n57x Brea Mall Xpress\n1623\n1637\nX\n";
  ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST_F(DriverLoadFile, CreateLoadExit) {
  std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nL\nload.txt\nX\n";
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

TEST(Driver, CreateCreateFindExit) {
  std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nR\n153 Brea Mall\n1642\n1703\nF\n1600\nX\n";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("57x Brea Mall Xpress"))
      << "Your program should show the first route's name 57x Brea Mall Xpress.";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1623"))
    << "Your program should show the first route's departure time, 1623.";    
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1637"))
    << "Your program should show the first route's arrival time 1637.";
}

TEST_F(DriverSaveFile, CreateCreateSaveExit) {
  ASSERT_DURATION_LE(3, {
    std::string user_input = "R\n57x Brea Mall Xpress\n1623\n1637\nR\n153 Brea Mall\n1642\n1703\nS\nsave.txt\nX\n";
    exec_program("tuffytravel", user_input);
  })

  std::ifstream your_file;
  your_file.open("save.txt");

  ASSERT_TRUE(your_file.good()) << "      The program should create a file using the filename provided by the user. In this case, save.txt.";
  
  int your_file_size = 0;

  your_file >> your_file_size;
  your_file.ignore();

  ASSERT_EQ(your_file_size, 2)  << "      The program should store 2 for the number of routes in the file.";
  
  std::string your_file_route_name;
  unsigned short int your_file_departure_time;
  unsigned short int your_file_arrival_time;

  // first route
  std::getline(your_file, your_file_route_name);

  ASSERT_EQ(your_file_route_name, "57x Brea Mall Xpress") << "      The program should save the name of the first route, 57x Brea Mall Xpress";

  your_file >>your_file_departure_time;

  ASSERT_EQ(your_file_departure_time, 1623) << "      The program should save the departure time of the first route, 1623";

  your_file >>your_file_arrival_time;
  your_file.ignore();

  ASSERT_EQ(your_file_arrival_time, 1637) << "      The program should save the arrival time of the first route, 1637";
  
  // second route

  std::getline(your_file, your_file_route_name);

  ASSERT_EQ(your_file_route_name, "153 Brea Mall") << "      The program should save the name of the second route, 153 Brea Mall";

  your_file >>your_file_departure_time;

  ASSERT_EQ(your_file_departure_time, 1642) << "      The program should save the departure time of the second route, 1642";

  your_file >>your_file_arrival_time;
  your_file.ignore();

  ASSERT_EQ(your_file_arrival_time, 1703) << "      The program should save the arrival time of the second route, 1703";

  your_file.close();  
}

TEST_F(DriverLoadFile, LoadDisplayExitOutput) {
  ASSERT_DURATION_LE(3, {
    std::string user_input = "L\nload.txt\nD\nX\n";
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

    ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1648"))
      << "Your program should show the second route's departure time, 1648.";    
    ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("1702"))
      << "Your program should show the second route's arrival time 1702.";
  })
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);    
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
    return RUN_ALL_TESTS();
}
