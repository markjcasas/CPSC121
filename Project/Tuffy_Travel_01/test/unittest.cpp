#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "gtest_ext.h"

using ::testing::HasSubstr;

TEST(Input, RetrieveRoutesAndTimes) {
	std::string user_input = "57x Brea Mall Xpress\n1623\n153 Brea Mall\n1642\n57x Brea Mall Xpress\n1648\n1630";
	ASSERT_EXECEXIT("tuffytravel", user_input, 3);
}

TEST(Output, ShowBestRoute) {
  std::string user_input = "57x Brea Mall Xpress\n1623\n153 Brea Mall\n1642\n57x Brea Mall Xpress\n1648\n1630";
  ASSERT_EXECTHAT("tuffytravel", user_input, HasSubstr("153 Brea Mall"))
      << "Your program should select 153 Brea Mall as the best route.";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);    
    ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
    return RUN_ALL_TESTS();
}
