#include <input.hpp>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

const std::unordered_map<std::string, int> hints = {
    {"children", 3},
    {"cats", 7},
    {"samoyeds", 2},
    {"pomeranians", 3},
    {"akitas", 0},
    {"vizslas", 0},
    {"goldfish", 5},
    {"trees", 3},
    {"cars", 2},
    {"perfumes", 1}};

class AuntSue
{
private:
  std::unordered_map<std::string, int> items;

public:
  AuntSue(std::string line);
  bool matches(std::unordered_map<std::string, int> hints);
  ~AuntSue();
};

AuntSue::AuntSue(std::string line)
{
  std::string key, value;

  size_t i = line.find_first_of(':') + 2;

  while (i < line.size())
  {
    size_t j = line.find_first_of(':', i);

    key = line.substr(i, j - i);

    i = j + 2;
    j = line.find_first_of(',', i);

    if (j == std::string::npos)
    {
      value = line.substr(i);
      i = line.size();
    }
    else
    {
      value = line.substr(i, j - i);
      i = j + 2;
    }

    items[key] = std::stoi(value);
  }
}

bool AuntSue::matches(std::unordered_map<std::string, int> hints)
{
  for (auto hint : hints)
  {
    if (this->items.find(hint.first) == this->items.end())
    {
      continue;
    }

#ifdef PART2
    if (hint.first == "cats" || hint.first == "trees")
    {
      if (this->items[hint.first] <= hint.second)
      {
        return false;
      }
      continue;
    }

    if (hint.first == "pomeranians" || hint.first == "goldfish")
    {
      if (this->items[hint.first] >= hint.second)
      {
        return false;
      }
      continue;
    }
#endif

    if (this->items[hint.first] != hint.second)
    {
      return false;
    }
  }

  return true;
}

AuntSue::~AuntSue()
{
}

#ifndef TEST
int main(int argc, char const *argv[])
{
  Input input(__FILE__);

  std::vector<AuntSue> aunts;

  for (auto line : input)
  {
    aunts.push_back(AuntSue(line));
  }

  for (int i = 0; i < aunts.size(); i++)
  {
    if (aunts[i].matches(hints))
    {
      std::cout << i + 1 << std::endl;
    }
  }

  return 0;
}
#endif