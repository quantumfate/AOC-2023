#include "./test.hpp"

void TestAdventOfCode::testDayOne() {
  std::string case_one   = "1abc2";
  std::string case_two   = "pqr3stu8vwx";
  std::string case_three = "a1b2c3d4e5f";
  std::string case_four  = "treb7uchet";
  std::string case_five  = "notanumber";

  int         expected_one   = 12;
  int         expected_two   = 38;
  int         expected_three = 15;
  int         expected_four  = 77;
  int         expected_five  = 0;

  int         expected_sum = expected_one + expected_two + expected_three + expected_four + expected_five;

  DayOne      dayOne;
  int         actual_one   = dayOne.retrieveCipher(case_one);
  int         actual_two   = dayOne.retrieveCipher(case_two);
  int         actual_three = dayOne.retrieveCipher(case_three);
  int         actual_four  = dayOne.retrieveCipher(case_four);
  int         actual_five  = dayOne.retrieveCipher(case_five);

  int         actual_sum = actual_one + actual_two + actual_three + actual_four + actual_five;

  assert(actual_one == expected_one);
  assert(actual_two == expected_two);
  assert(actual_three == expected_three);
  assert(actual_four == expected_four);
  assert(actual_five == expected_five);
  assert(actual_sum == expected_sum);
  printf("Day One tests passed.\n");
}

int main(int argc, char** argv) {
  TestAdventOfCode testAdventOfCode;
  testAdventOfCode.testDayOne();
}
