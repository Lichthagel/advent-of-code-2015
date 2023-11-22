#include <input.hpp>
#include <unordered_map>
#include <regex>
#include <vector>
#include <cassert>
#include <iostream>

class HolidayFeast
{
private:
  std::unordered_map<std::string, std::unordered_map<std::string, int>> happiness_table;
  std::regex regex;

public:
  HolidayFeast();
  ~HolidayFeast();
  void parseLine(std::string line);
#ifdef PART2
  void addMe();
#endif
  int getTotalHappiness(std::vector<std::string> seating);
  std::vector<std::string> getOptimalSeating();
};

HolidayFeast::HolidayFeast()
{
  this->regex = std::regex("(.+) would (gain|lose) (\\d+) happiness units by sitting next to (.+).");
}

HolidayFeast::~HolidayFeast()
{
}

void HolidayFeast::parseLine(std::string line)
{
  std::smatch match;

  std::regex_match(line, match, regex);

  std::string person = match[1];
  std::string gain_or_lose = match[2];
  int happiness = std::stoi(match[3]);
  std::string next_to = match[4];

  if (gain_or_lose == "lose")
  {
    happiness = -happiness;
  }

  happiness_table[person][next_to] = happiness;
}

#ifdef PART2
void HolidayFeast::addMe()
{
  this->happiness_table["Me"] = {};
}
#endif

int HolidayFeast::getTotalHappiness(std::vector<std::string> seating)
{
  assert(seating.size() == this->happiness_table.size());

  size_t n = seating.size();

  int total_happiness = 0;

  for (size_t i = 0; i < n; i++)
  {
    std::string person = seating[i];
    std::string left = seating[(i + n - 1) % n];
    std::string right = seating[(i + 1) % n];

    total_happiness += this->happiness_table[person][left];
    total_happiness += this->happiness_table[person][right];
  }

  return total_happiness;
}

std::vector<std::string> HolidayFeast::getOptimalSeating()
{
  std::vector<std::string> people(this->happiness_table.size());

  std::transform(this->happiness_table.begin(), this->happiness_table.end(), people.begin(), [](auto pair)
                 { return pair.first; });

  std::sort(people.begin(), people.end());

  std::vector<std::string> optimal_seating;
  int optimal_happiness = 0;

  do
  {
    int happiness = this->getTotalHappiness(people);

    if (happiness > optimal_happiness)
    {
      optimal_seating = people;
      optimal_happiness = happiness;
    }
  } while (std::next_permutation(people.begin(), people.end()));

  return optimal_seating;
}

#ifndef TEST
int main(int argc, char const *argv[])
{
  Input input(__FILE__);

  HolidayFeast feast;

  for (auto line : input)
  {
    feast.parseLine(line);
  }

#ifdef PART2
  feast.addMe();
#endif

  std::vector<std::string> seating = feast.getOptimalSeating();

  std::cout << feast.getTotalHappiness(seating) << std::endl;

  return 0;
}
#endif