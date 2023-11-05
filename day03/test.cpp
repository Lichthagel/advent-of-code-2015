#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day03_Part1, Example1)
{
  EXPECT_EQ(run(">"), 2);
}

TEST(Day03_Part1, Example2)
{
  EXPECT_EQ(run("^>v<"), 4);
}

TEST(Day03_Part1, Example3)
{
  EXPECT_EQ(run("^v^v^v^v^v"), 2);
}
#endif

#ifdef PART2
TEST(Day03_Part2, Example1)
{
  EXPECT_EQ(run("^v"), 3);
}

TEST(Day03_Part2, Example2)
{
  EXPECT_EQ(run("^>v<"), 3);
}

TEST(Day03_Part2, Example3)
{
  EXPECT_EQ(run("^v^v^v^v^v"), 11);
}
#endif