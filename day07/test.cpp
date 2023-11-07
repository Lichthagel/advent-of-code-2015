#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day07_Part1, Example1)
{
  Wiring wiring;

  wiring.parse("123 -> x");

  ASSERT_EQ(wiring.evaluate("x"), 123);

  wiring.parse("456 -> y");

  ASSERT_EQ(wiring.evaluate("y"), 456);

  wiring.parse("x AND y -> d");

  ASSERT_EQ(wiring.evaluate("d"), 72);

  wiring.parse("x OR y -> e");

  ASSERT_EQ(wiring.evaluate("e"), 507);

  wiring.parse("x LSHIFT 2 -> f");

  ASSERT_EQ(wiring.evaluate("f"), 492);

  wiring.parse("y RSHIFT 2 -> g");

  ASSERT_EQ(wiring.evaluate("g"), 114);

  wiring.parse("NOT x -> h");

  ASSERT_EQ(wiring.evaluate("h"), 65412);

  wiring.parse("NOT y -> i");

  ASSERT_EQ(wiring.evaluate("i"), 65079);
}
#endif