#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day18_Part1, Example)
{
  std::vector<std::string> input = {
      ".#.#.#",
      "...##.",
      "#....#",
      "..#...",
      "#.#..#",
      "####.."};

  Grid grid(input);

  grid.step(4);

  EXPECT_EQ(grid.count(), 4);
}
#endif

#ifdef PART2
TEST(Day18_Part2, Example)
{
  std::vector<std::string> input = {
      "##.#.#",
      "...##.",
      "#....#",
      "..#...",
      "#.#..#",
      "####.#"};

  Grid grid(input);

  grid.step(5);

  EXPECT_EQ(grid.count(), 17);
}
#endif