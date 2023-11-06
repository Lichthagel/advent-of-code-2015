#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day05_Part1, Example1)
{
  EXPECT_EQ(run("ugknbfddgicrmopn"), true);
}

TEST(Day05_Part1, Example2)
{
  EXPECT_EQ(run("aaa"), true);
}

TEST(Day05_Part1, Example3)
{
  EXPECT_EQ(run("jchzalrnumimnmhp"), false);
}

TEST(Day05_Part1, Example4)
{
  EXPECT_EQ(run("haegwjzuvuyypxyu"), false);
}

TEST(Day05_Part1, Example5)
{
  EXPECT_EQ(run("dvszwmarrgswjxmb"), false);
}
#endif

#ifdef PART2
TEST(Day05_Part2, Example1)
{
  EXPECT_EQ(run("qjhvhtzxzqqjkmpb"), true);
}

TEST(Day05_Part2, Example2)
{
  EXPECT_EQ(run("xxyxx"), true);
}

TEST(Day05_Part2, Example3)
{
  EXPECT_EQ(run("uurcxstgmygtbstg"), false);
}

TEST(Day05_Part2, Example4)
{
  EXPECT_EQ(run("ieodomkazucvgmuy"), false);
}
#endif