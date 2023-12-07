#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day17_Part1, Example)
{
  std::vector<unsigned int> bin_sizes = {20, 15, 10, 5, 5};

  bool *use_bin = new bool[bin_sizes.size()];

  EXPECT_EQ(combinations(bin_sizes, use_bin, 0, 25, 25), 4);

  delete[] use_bin;
}
#endif

#ifdef PART2

#endif