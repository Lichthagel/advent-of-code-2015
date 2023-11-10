#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day08_Part1, Example1)
{
  ASSERT_EQ(run("\"\""), std::make_pair(2ull, 0ull));
}

TEST(Day08_Part1, Example2)
{
  ASSERT_EQ(run("\"abc\""), std::make_pair(5ull, 3ull));
}

TEST(Day08_Part1, Example3)
{
  ASSERT_EQ(run("\"aaa\\\"aaa\""), std::make_pair(10ull, 7ull));
}

TEST(Day08_Part1, Example4)
{
  ASSERT_EQ(run("\"\\x27\""), std::make_pair(6ull, 1ull));
}
#endif

#ifdef PART2
TEST(Day08_Part2, Example1)
{
  ASSERT_EQ(run("\"\""), std::make_pair(2ull, 6ull));
}

TEST(Day08_Part2, Example2)
{
  ASSERT_EQ(run("\"abc\""), std::make_pair(5ull, 9ull));
}

TEST(Day08_Part2, Example3)
{
  ASSERT_EQ(run("\"aaa\\\"aaa\""), std::make_pair(10ull, 16ull));
}

TEST(Day08_Part2, Example4)
{
  ASSERT_EQ(run("\"\\x27\""), std::make_pair(6ull, 11ull));
}
#endif