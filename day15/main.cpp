#include <input.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <optional>

class Ingredient
{
public:
  int capacity;
  int durability;
  int flavor;
  int texture;
  int calories;
  Ingredient(std::string s);
  ~Ingredient();
};

Ingredient::Ingredient(std::string s)
{
  size_t pos = s.find("capacity ");
  size_t comma_pos = s.find(",", pos);

  this->capacity = std::stoi(s.substr(pos + 9, comma_pos - pos - 9));

  pos = s.find("durability ", comma_pos);
  comma_pos = s.find(",", pos);

  this->durability = std::stoi(s.substr(pos + 11, comma_pos - pos - 11));

  pos = s.find("flavor ", comma_pos);
  comma_pos = s.find(",", pos);

  this->flavor = std::stoi(s.substr(pos + 7, comma_pos - pos - 7));

  pos = s.find("texture ", comma_pos);
  comma_pos = s.find(",", pos);

  this->texture = std::stoi(s.substr(pos + 8, comma_pos - pos - 8));

  pos = s.find("calories ", comma_pos);

  this->calories = std::stoi(s.substr(pos + 9));
}

Ingredient::~Ingredient()
{
}

class Kitchen
{
private:
  std::vector<Ingredient> ingredients;
  int score(int *amounts);
  int calories(int *amounts);
  int maxScoreInner(int *amounts, size_t index, int remainingTeaspoons, std::optional<int> calories = std::nullopt);

public:
  Kitchen(Input &input);
  Kitchen(std::vector<Ingredient> ingredients);
  ~Kitchen();
  int maxScore(int teaspoons, std::optional<int> calories = std::nullopt);
};

int Kitchen::score(int *amounts)
{
  int capacity = 0;
  int durability = 0;
  int flavor = 0;
  int texture = 0;

  for (size_t i = 0; i < this->ingredients.size(); i++)
  {
    capacity += this->ingredients[i].capacity * amounts[i];
    durability += this->ingredients[i].durability * amounts[i];
    flavor += this->ingredients[i].flavor * amounts[i];
    texture += this->ingredients[i].texture * amounts[i];
  }

  if (capacity < 0)
  {
    capacity = 0;
  }

  if (durability < 0)
  {
    durability = 0;
  }

  if (flavor < 0)
  {
    flavor = 0;
  }

  if (texture < 0)
  {
    texture = 0;
  }

  return capacity * durability * flavor * texture;
}

int Kitchen::calories(int *amounts)
{
  int calories = 0;

  for (size_t i = 0; i < this->ingredients.size(); i++)
  {
    calories += this->ingredients[i].calories * amounts[i];
  }

  return calories;
}

int Kitchen::maxScoreInner(int *amounts, size_t index, int remainingTeaspoons, std::optional<int> calories)
{
  if (index == this->ingredients.size() - 1)
  {
    amounts[index] = remainingTeaspoons;

    if (calories.has_value() && this->calories(amounts) != calories.value())
    {
      return 0;
    }
    
    return this->score(amounts);
  }

  int max = 0;

  for (int i = 0; i <= remainingTeaspoons; i++)
  {
    amounts[index] = i;

    int score = this->maxScoreInner(amounts, index + 1, remainingTeaspoons - i, calories);

    if (score > max)
    {
      max = score;
    }
  }

  return max;
}

Kitchen::Kitchen(Input &input)
{
  for (std::string line : input)
  {
    this->ingredients.push_back(Ingredient(line));
  }
}

Kitchen::Kitchen(std::vector<Ingredient> ingredients)
{
  this->ingredients = ingredients;
}

Kitchen::~Kitchen()
{
}

int Kitchen::maxScore(int teaspoons, std::optional<int> calories)
{
  int *amounts = new int[this->ingredients.size()];

  int max = this->maxScoreInner(amounts, 0, teaspoons, calories);

  delete[] amounts;

  return max;
}

#ifndef TEST
int main(int argc, char const *argv[])
{
  Input input(__FILE__);

  Kitchen kitchen(input);

#ifdef PART1
  std::cout << kitchen.maxScore(100) << std::endl;
#endif

#ifdef PART2
  std::cout << kitchen.maxScore(100, 500) << std::endl;
#endif

  return 0;
}
#endif