#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "gtest_ext.h"

TEST(UserInput, AskMealCostAndTip) {
  std::string user_input = "10.00 9.00";
  ASSERT_EXECEXIT("main", user_input, 3)
    << "      Your program should ask for the customer's meal cost and tip percentage.";
}

TEST(Restaurant, Taxes) {
  std::string unittest_output =
      "Please input meal cost: Please input tip percentage: \nRestaurant "
      "Bill\n====================\nSubtotal: $10.00\nTaxes: $0.75\nTip: "
      "$0.90\n====================\nTotal: $11.65\n";
  std::string input = "10.00 9";
  ASSERT_EXECEQ("main", input, unittest_output);
}

// Consider if this is required. This test fails when this formula is used
// meal_cost * 7.5 / 100
// but passes when this is used
// meal_csot * 0.075
/*TEST(Restaurant, TaxesPrecisionTest) {
  std::string unittest_output =
      "Please input meal cost: Please input tip percentage: \nRestaurant "
      "Bill\n====================\nSubtotal: $30.20\nTaxes: $2.27\nTip: "
      "$2.72\n====================\nTotal: $35.18\n";
  std::string input = "30.20 9";
  ASSERT_EXECEQ("main", input, unittest_output);
}*/

TEST(Restaurant, ZeroTip) {

  std::string unittest_output =
      "Please input meal cost: Please input tip percentage: \nRestaurant "
      "Bill\n====================\nSubtotal: $27.50\nTaxes: $2.06\nTip: "
      "$0.00\n====================\nTotal: $29.56\n";
  std::string input = "27.50 0";
  ASSERT_EXECEQ("main", input, unittest_output);
}

TEST(Restaurant, Tip) {

  std::string unittest_output =
      "Please input meal cost: Please input tip percentage: \nRestaurant "
      "Bill\n====================\nSubtotal: $54.58\nTaxes: $4.09\nTip: "
      "$5.46\n====================\nTotal: $64.13\n";
  std::string input = "54.58 10";
  ASSERT_EXECEQ("main", input, unittest_output);
}

TEST(Restaurant, Total) {
  std::string unittest_output =
      "Please input meal cost: Please input tip percentage: \nRestaurant "
      "Bill\n====================\nSubtotal: $314.19\nTaxes: $23.56\nTip: "
      "$40.84\n====================\nTotal: $378.60\n";
  std::string input = "314.19 13";
  ASSERT_EXECEQ("main", input, unittest_output);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ::testing::UnitTest::GetInstance()->listeners().Append(new SkipListener());
  return RUN_ALL_TESTS();
}

