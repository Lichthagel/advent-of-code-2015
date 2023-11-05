#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day04_Part1, Example1)
{
  EXPECT_EQ(run("abcdef"), 609043);
}

TEST(Day04_Part1, Example2)
{
  EXPECT_EQ(run("pqrstuv"), 1048970);
}
#endif