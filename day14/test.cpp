#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day14_Part1, Example1) {
  Reindeer comet("Comet can fly 14 km/s for 10 seconds, but then must rest for 127 seconds.");

  EXPECT_EQ(comet.getDistance(1), 14);
}

TEST(Day14_Part1, Example2) {
  Reindeer comet("Comet can fly 14 km/s for 10 seconds, but then must rest for 127 seconds.");

  EXPECT_EQ(comet.getDistance(10), 140);
}

TEST(Day14_Part1, Example3) {
  Reindeer comet("Comet can fly 14 km/s for 10 seconds, but then must rest for 127 seconds.");

  EXPECT_EQ(comet.getDistance(11), 140);
}

TEST(Day14_Part1, Example4) {
  Reindeer comet("Comet can fly 14 km/s for 10 seconds, but then must rest for 127 seconds.");

  EXPECT_EQ(comet.getDistance(12), 140);
}

TEST(Day14_Part1, Example5) {
  Reindeer comet("Comet can fly 14 km/s for 10 seconds, but then must rest for 127 seconds.");

  EXPECT_EQ(comet.getDistance(1000), 1120);
}

TEST(Day14_Part1, Example6) {
  Reindeer dancer("Dancer can fly 16 km/s for 11 seconds, but then must rest for 162 seconds.");

  EXPECT_EQ(dancer.getDistance(1), 16);
}

TEST(Day14_Part1, Example7) {
  Reindeer dancer("Dancer can fly 16 km/s for 11 seconds, but then must rest for 162 seconds.");

  EXPECT_EQ(dancer.getDistance(10), 160);
}

TEST(Day14_Part1, Example8) {
  Reindeer dancer("Dancer can fly 16 km/s for 11 seconds, but then must rest for 162 seconds.");

  EXPECT_EQ(dancer.getDistance(11), 176);
}

TEST(Day14_Part1, Example9) {
  Reindeer dancer("Dancer can fly 16 km/s for 11 seconds, but then must rest for 162 seconds.");

  EXPECT_EQ(dancer.getDistance(12), 176);
}

TEST(Day14_Part1, Example10) {
  Reindeer dancer("Dancer can fly 16 km/s for 11 seconds, but then must rest for 162 seconds.");

  EXPECT_EQ(dancer.getDistance(1000), 1056);
}
#endif