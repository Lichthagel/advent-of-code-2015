#include <gtest/gtest.h>

#include "main.cpp"

#ifdef PART1
TEST(Day15_Part1, Example)
{
  std::vector<Ingredient> ingredients = {
    Ingredient("Butterscotch: capacity -1, durability -2, flavor 6, texture 3, calories 8"),
    Ingredient("Cinnamon: capacity 2, durability 3, flavor -2, texture -1, calories 3")
  };

  Kitchen kitchen(ingredients);

  EXPECT_EQ(kitchen.maxScore(100), 62842880);
}
#endif

#ifdef PART2
TEST(Day15_Part2, Example)
{
  std::vector<Ingredient> ingredients = {
    Ingredient("Butterscotch: capacity -1, durability -2, flavor 6, texture 3, calories 8"),
    Ingredient("Cinnamon: capacity 2, durability 3, flavor -2, texture -1, calories 3")
  };

  Kitchen kitchen(ingredients);

  EXPECT_EQ(kitchen.maxScore(100, 500), 57600000);
}
#endif