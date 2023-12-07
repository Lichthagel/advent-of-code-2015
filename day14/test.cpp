#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day14_Part1, Example_Comet)
{
  Reindeer comet("Comet can fly 14 km/s for 10 seconds, but then must rest for 127 seconds.");

  EXPECT_EQ(comet.getDistance(1), 14);
  EXPECT_EQ(comet.getDistance(10), 140);
  EXPECT_EQ(comet.getDistance(11), 140);
  EXPECT_EQ(comet.getDistance(12), 140);
  EXPECT_EQ(comet.getDistance(1000), 1120);
}

TEST(Day14_Part1, Example_Dancer)
{
  Reindeer dancer("Dancer can fly 16 km/s for 11 seconds, but then must rest for 162 seconds.");

  EXPECT_EQ(dancer.getDistance(1), 16);
  EXPECT_EQ(dancer.getDistance(10), 160);
  EXPECT_EQ(dancer.getDistance(11), 176);
  EXPECT_EQ(dancer.getDistance(12), 176);
  EXPECT_EQ(dancer.getDistance(1000), 1056);
}
#endif

#ifdef PART2
TEST(Day14_Part2, Example_Race)
{
  std::vector<Reindeer> reindeers = {Reindeer("Comet can fly 14 km/s for 10 seconds, but then must rest for 127 seconds."),
                                     Reindeer("Dancer can fly 16 km/s for 11 seconds, but then must rest for 162 seconds.")};

  Race race(reindeers);

  EXPECT_EQ(race.pointsWinner(1), 1);
  EXPECT_EQ(race.pointsWinner(140), 139);
  EXPECT_EQ(race.pointsWinner(1000), 689);

  std::vector<unsigned int> points = race.points(1000);

  EXPECT_EQ(points[0], 312);
  EXPECT_EQ(points[1], 689);
}
#endif