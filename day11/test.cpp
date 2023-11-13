#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day11_Part1, Example1)
{
  Password pw("hijklmmn");

  EXPECT_TRUE(pw.satisfiesRequirement1());
  EXPECT_FALSE(pw.satisfiesRequirement2());
}

TEST(Day11_Part1, Example2)
{
  Password pw("abbceffg");

  EXPECT_FALSE(pw.satisfiesRequirement1());
  EXPECT_TRUE(pw.satisfiesRequirement3());
}

TEST(Day11_Part1, Example3)
{
  Password pw("abbcegjk");

  EXPECT_FALSE(pw.satisfiesRequirement3());
}

TEST(Day11_Part1, Example4)
{
  Password pw("abcdefgh");

  pw.next();

  EXPECT_EQ(pw.str, "abcdffaa");
}

TEST(Day11_Part1, Example5)
{
  Password pw("ghijklmn");

  pw.next();

  EXPECT_EQ(pw.str, "ghjaabcc");
}
#endif