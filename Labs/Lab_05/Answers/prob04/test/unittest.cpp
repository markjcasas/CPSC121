#include <fstream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "gtest_ext.h"

using ::testing::HasSubstr;
using ::testing::MatchesRegex;

struct UserInput : public UnitTestFileManager {
    UserInput() : UnitTestFileManager("donations.txt") { }
};

struct FileLoading : public UnitTestFileManager {
  FileLoading() : UnitTestFileManager("load_donations.txt") { }
};

TEST_F(UserInput, FileName) {
  std::string user_input = "donations.txt\n";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the file name of the donations file.";
}

TEST_F(FileLoading, OneDonation) {
  std::ofstream user_file;
  user_file.open("load_donations.txt");
  user_file << "1\n200\n";
  user_file.close();

  std::string user_input = "load_donations.txt\n";
  
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("$200.00"))
      << "      Your program should show the first donation, $200.00.";
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*((Total|total).*\$200.00).*)"))
      << "      Your program's total donation should be equal to $200.00.";      
  })
}

TEST_F(FileLoading, MultipleDonations) {
  std::ofstream user_file;
  user_file.open("load_donations.txt");
  user_file << "4\n200\n143.23\n501.37\n396.88\n";
  user_file.close();

  std::string user_input = "load_donations.txt\n";
  
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, HasSubstr("$200.00"))
      << "      Your program should show the first donation, $200.00.";
    ASSERT_EXECTHAT("main", user_input, HasSubstr("$143.23"))
      << "      Your program should show the second donation, $143.23.";
    ASSERT_EXECTHAT("main", user_input, HasSubstr("$501.37"))
      << "      Your program should show the third donation, $501.37.";
    ASSERT_EXECTHAT("main", user_input, HasSubstr("$396.88"))
      << "      Your program should show the fourth donation, $1241.48.";
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*((Total|total).*\$1241.48).*)"))
      << "      Your program's total donation should be equal to $1241.48.";      
  })
}

TEST_F(FileLoading, MissingFile) {
  std::ifstream user_file;
  std::string user_input = "missingfile.txt\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECTHAT("main", user_input, MatchesRegex(R"(.*(Invalid|invalid|error|missing).*)"))
      << "      Your program should show an error message when it is asked to load a missing donation file.";
  })
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);    
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}
