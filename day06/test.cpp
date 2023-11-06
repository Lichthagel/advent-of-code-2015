#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day06_Part1, Example1)
{
  Grid grid;

  Instruction instruction("turn on 0,0 through 999,999");

  grid.apply(instruction);

  EXPECT_EQ(grid.nlights_on(), 1000000);
}

TEST(Day06_Part1, Example2_1)
{
  Grid grid;

  Instruction instruction("toggle 0,0 through 999,0");

  grid.apply(instruction);

  EXPECT_EQ(grid.nlights_on(), 1000);
}

TEST(Day06_Part1, Example2_2)
{
  Grid grid;

  for (std::array<bool, 1000> &row : grid.grid)
  {
    row.fill(true);
  }

  Instruction instruction("toggle 0,0 through 999,0");

  grid.apply(instruction);

  EXPECT_EQ(grid.nlights_on(), 999000);
}

TEST(Day06_Part1, Example3_1)
{
  Grid grid;

  Instruction instruction("turn off 499,499 through 500,500");

  grid.apply(instruction);

  EXPECT_EQ(grid.nlights_on(), 0);
}

TEST(Day06_Part1, Example3_2)
{
  Grid grid;

  for (std::array<bool, 1000> &row : grid.grid)
  {
    row.fill(true);
  }

  Instruction instruction("turn off 499,499 through 500,500");

  grid.apply(instruction);

  EXPECT_EQ(grid.nlights_on(), 999996);
}
#endif

#ifdef PART2
TEST(Day06_Part2, Example1)
{
  Grid grid;

  Instruction instruction("turn on 0,0 through 0,0");

  grid.apply(instruction);

  EXPECT_EQ(grid.nlights_on(), 1);
}

TEST(Day06_Part2, Example2)
{
  Grid grid;

  Instruction instruction("toggle 0,0 through 999,999");

  grid.apply(instruction);

  EXPECT_EQ(grid.nlights_on(), 2000000);
}
#endif