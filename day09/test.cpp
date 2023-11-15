#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day09_Part1, Example1)
{
  world w;

  w.readLine("London to Dublin = 464");
  w.readLine("London to Belfast = 518");
  w.readLine("Dublin to Belfast = 141");

  EXPECT_EQ(w.optimalTour(), 605);
}
#endif

#ifdef PART2
TEST(Day09_Part2, Example1)
{
  world w;

  w.readLine("London to Dublin = 464");
  w.readLine("London to Belfast = 518");
  w.readLine("Dublin to Belfast = 141");

  EXPECT_EQ(w.optimalTour(), 982);
}
#endif