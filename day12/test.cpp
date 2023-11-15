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

#ifdef PART2
TEST(Day12_Part2, Example1)
{
  EXPECT_EQ(run("[1,2,3]"), 6);
}

TEST(Day12_Part2, Example2)
{
  EXPECT_EQ(run("[1,{\"c\":\"red\",\"b\":2},3]"), 4);
}

TEST(Day12_Part2, Example3)
{
  EXPECT_EQ(run("{\"d\":\"red\",\"e\":[1,2,3,4],\"f\":5}"), 0);
}

TEST(Day12_Part2, Example4)
{
  EXPECT_EQ(run("[1,\"red\",5]"), 6);
}

TEST(Day12_Part2, Test1)
{
  EXPECT_EQ(run("[93,\"red\",183,\"blue\",\"red\",30,-16,\"red\",\"red\",\"yellow\"]"), 290);
}

TEST(Day12_Part2, Test2)
{
  EXPECT_EQ(run("[\"violet\",19,\"orange\",\"yellow\",\"red\",\"violet\",\"blue\",\"violet\",{\"e\":\"yellow\",\"a\":\"violet\",\"d\":137,\"c\":\"blue\",\"h\":197,\"b\":\"orange\",\"g\":{\"e\":\"yellow\",\"c\":\"orange\",\"a\":18,\"b\":42,\"d\":183,\"f\":142},\"f\":68}]"), 806);
}

TEST(Day12_Part2, Test3)
{
  EXPECT_EQ(run("{\"d\":[\"red\",4,6]}"), 10);
}
#endif