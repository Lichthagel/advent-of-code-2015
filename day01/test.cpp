#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "main.cpp"

#ifdef PART1
TEST(Day01_Part1, Example1)
{
  EXPECT_EQ(run("(())"), 0);
}

TEST(Day01_Part1, Example2)
{
  EXPECT_EQ(run("()()"), 0);
}

TEST(Day01_Part1, Example3)
{
  EXPECT_EQ(run("((("), 3);
}

TEST(Day01_Part1, Example4)
{
  EXPECT_EQ(run("(()(()("), 3);
}

TEST(Day01_Part1, Example5)
{
  EXPECT_EQ(run("))((((("), 3);
}

TEST(Day01_Part1, Example6)
{
  EXPECT_EQ(run("())"), -1);
}

TEST(Day01_Part1, Example7)
{
  EXPECT_EQ(run("))("), -1);
}

TEST(Day01_Part1, Example8)
{
  EXPECT_EQ(run(")))"), -3);
}

TEST(Day01_Part1, Example9)
{
  EXPECT_EQ(run(")())())"), -3);
}
#endif

#ifdef PART2
TEST(Day01_Part2, Example1)
{
  EXPECT_EQ(run(")"), 1);
}

TEST(Day01_Part2, Example2)
{
  EXPECT_EQ(run("()())"), 5);
}
#endif