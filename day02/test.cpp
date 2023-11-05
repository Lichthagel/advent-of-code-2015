#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day02_Part1, Example1)
{
  EXPECT_EQ(run("2x3x4"), 58);
}

TEST(Day02_Part1, Example2)
{
  EXPECT_EQ(run("1x1x10"), 43);
}
#endif

#ifdef PART2
TEST(Day02_Part2, Example1)
{
  EXPECT_EQ(run("2x3x4"), 34);
}

TEST(Day02_Part2, Example2)
{
  EXPECT_EQ(run("1x1x10"), 14);
}
#endif