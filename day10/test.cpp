#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day10, Example1)
{
  EXPECT_EQ(run("1"), "11");
}

TEST(Day10, Example2)
{
  EXPECT_EQ(run("11"), "21");
}

TEST(Day10, Example3)
{
  EXPECT_EQ(run("21"), "1211");
}

TEST(Day10, Example4)
{
  EXPECT_EQ(run("1211"), "111221");
}

TEST(Day10, Example5)
{
  EXPECT_EQ(run("111221"), "312211");
}
#endif