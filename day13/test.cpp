
#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day13_Part1, Example1)
{
  std::vector<std::string> input = {
      "Alice would gain 54 happiness units by sitting next to Bob.",
      "Alice would lose 79 happiness units by sitting next to Carol.",
      "Alice would lose 2 happiness units by sitting next to David.",
      "Bob would gain 83 happiness units by sitting next to Alice.",
      "Bob would lose 7 happiness units by sitting next to Carol.",
      "Bob would lose 63 happiness units by sitting next to David.",
      "Carol would lose 62 happiness units by sitting next to Alice.",
      "Carol would gain 60 happiness units by sitting next to Bob.",
      "Carol would gain 55 happiness units by sitting next to David.",
      "David would gain 46 happiness units by sitting next to Alice.",
      "David would lose 7 happiness units by sitting next to Bob.",
      "David would gain 41 happiness units by sitting next to Carol."};

  HolidayFeast feast;

  for (auto line : input)
  {
    feast.parseLine(line);
  }

  std::vector<std::string> people = {"Alice", "Bob", "Carol", "David"};

  EXPECT_EQ(feast.getTotalHappiness(people), 330);
}

TEST(Day13_Part1, Example2)
{
  std::vector<std::string> input = {
      "Alice would gain 54 happiness units by sitting next to Bob.",
      "Alice would lose 79 happiness units by sitting next to Carol.",
      "Alice would lose 2 happiness units by sitting next to David.",
      "Bob would gain 83 happiness units by sitting next to Alice.",
      "Bob would lose 7 happiness units by sitting next to Carol.",
      "Bob would lose 63 happiness units by sitting next to David.",
      "Carol would lose 62 happiness units by sitting next to Alice.",
      "Carol would gain 60 happiness units by sitting next to Bob.",
      "Carol would gain 55 happiness units by sitting next to David.",
      "David would gain 46 happiness units by sitting next to Alice.",
      "David would lose 7 happiness units by sitting next to Bob.",
      "David would gain 41 happiness units by sitting next to Carol."};

  HolidayFeast feast;

  for (auto line : input)
  {
    feast.parseLine(line);
  }

  std::vector<std::string> seating = feast.getOptimalSeating();

  EXPECT_EQ(feast.getTotalHappiness(seating), 330);
}
#endif