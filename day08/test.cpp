#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day08_Part1, Example1)
{
  std::pair<size_t, size_t> result = run("\"\"");

  ASSERT_EQ(result.first, 2ull);
  ASSERT_EQ(result.second, 0ull);
}

TEST(Day08_Part1, Example2)
{
  std::pair<size_t, size_t> result = run("\"abc\"");

  ASSERT_EQ(result.first, 5ull);
  ASSERT_EQ(result.second, 3ull);
}

TEST(Day08_Part1, Example3)
{
  std::pair<size_t, size_t> result = run("\"aaa\\\"aaa\"");

  ASSERT_EQ(result.first, 10ull);
  ASSERT_EQ(result.second, 7ull);
}

TEST(Day08_Part1, Example4)
{
  std::pair<size_t, size_t> result = run("\"\\x27\"");

  ASSERT_EQ(result.first, 6ull);
  ASSERT_EQ(result.second, 1ull);
}
#endif

#ifdef PART2
TEST(Day08_Part2, Example1)
{
  std::pair<size_t, size_t> result = run("\"\"");

  ASSERT_EQ(result.first, 2ull);
  ASSERT_EQ(result.second, 6ull);
}

TEST(Day08_Part2, Example2)
{
  std::pair<size_t, size_t> result = run("\"abc\"");

  ASSERT_EQ(result.first, 5ull);
  ASSERT_EQ(result.second, 9ull);
}

TEST(Day08_Part2, Example3)
{
  std::pair<size_t, size_t> result = run("\"aaa\\\"aaa\"");

  ASSERT_EQ(result.first, 10ull);
  ASSERT_EQ(result.second, 16ull);
}

TEST(Day08_Part2, Example4)
{
  std::pair<size_t, size_t> result = run("\"\\x27\"");

  ASSERT_EQ(result.first, 6ull);
  ASSERT_EQ(result.second, 11ull);
}
#endif