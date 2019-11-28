#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;

TEST(UserInput, AskOperationAndInputs) {
  std::string user_input = "+\n1\n2\nx\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the operator followed by 2 numerical inputs and x to exit.";
}

TEST(Operations, Addition) {
  std::string user_input = "+\n5\n-3\nx\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"((.* 2.*))"))
      << "      The sum should equal 2.";
  })
}

TEST(Operations, Subtraction) {
  std::string user_input = "-\n10\n-9\nx\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"((.* 19.*))"))
      << "      The difference should equal 19.";
  })
}

TEST(Operations, Multiplication) {
  std::string user_input = "*\n2\n-32\nx\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"((.* -64.*))"))
      << "      The product should equal -64.";
  })
}

TEST(Operations, Division) {
  std::string user_input = "/\n14\n-5\nx\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"((.* -2.*))"))
      << "      The quotient should equal -2.";
  })
}

TEST(Operations, InvalidInput) {
  std::string user_input = "@\nx\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*((can not)|can't|rerun|invalid|Invalid|error).*)"))
      << "      The program should not accept invalid operation types.";
  })
}

TEST(UserInput, MultipleOperations) {
  std::string user_input = "+\n1\n2\n-\n1\n2\n*\n1\n2\n/\n1\n2\n@\nx\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should continuously accept inputs until the user types x to exit.";
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
