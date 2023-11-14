#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day12_Part1, Example1)
{
  EXPECT_EQ(run("[1,2,3]"), 6);
  EXPECT_EQ(run("{\"a\":2,\"b\":4}"), 6);
}

TEST(Day12_Part1, Example2)
{
  EXPECT_EQ(run("[[[3]]]"), 3);
  EXPECT_EQ(run("{\"a\":{\"b\":4},\"c\":-1}"), 3);
}

TEST(Day12_Part1, Example3)
{
  EXPECT_EQ(run("{\"a\":[-1,1]}"), 0);
  EXPECT_EQ(run("[-1,{\"a\":1}]"), 0);
}

TEST(Day12_Part1, Example4)
{
  EXPECT_EQ(run("[]"), 0);
  EXPECT_EQ(run("{}"), 0);
}
#endif
