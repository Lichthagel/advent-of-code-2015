#include <unordered_map>
#include <regex>
#include <input.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <cassert>

class world
{
private:
  std::unordered_map<std::string, std::unordered_map<std::string, unsigned int>> distances;
  void dfs(std::string current, std::vector<std::string> &tour, unsigned int &curr_opt);

public:
  world();
  ~world();
  void addDistance(std::string from, std::string to, unsigned int distance);
  void readLine(std::string line);
  unsigned int pathLength(std::vector<std::string> tour);
  unsigned int optimalTour();
};

void world::dfs(std::string current, std::vector<std::string> &tour, unsigned int &curr_opt)
{
  tour.push_back(current);

  if (tour.size() == distances.size())
  {

    unsigned int length = pathLength(tour);

#ifdef PART1
    if (length < curr_opt)
      curr_opt = length;
#endif
#ifdef PART2
    if (length > curr_opt)
      curr_opt = length;
#endif
  }
  else
  {
    for (std::pair<std::string, unsigned int> next : distances[current])
    {
      if (std::find(tour.begin(), tour.end(), next.first) != tour.end())
      {
        continue;
      }

      dfs(next.first, tour, curr_opt);
    }
  }

  tour.pop_back();
}

world::world()
{
}

world::~world()
{
}

void world::addDistance(std::string from, std::string to, unsigned int distance)
{
  distances[from][to] = distance;
  distances[to][from] = distance;
}

void world::readLine(std::string line)
{
  std::regex regex("(.*) to (.*) = ([0-9]*)");
  std::smatch match;
  std::regex_match(line, match, regex);

  addDistance(match[1], match[2], std::stoi(match[3]));
}

unsigned int world::pathLength(std::vector<std::string> tour)
{
  unsigned int length = 0;

  for (size_t i = 0; i < tour.size() - 1; i++)
  {
    length += distances[tour[i]][tour[i + 1]];
  }

  return length;
}

unsigned int world::optimalTour()
{
#ifdef PART1
  unsigned int curr_opt = -1;
#endif
#ifdef PART2
  unsigned int curr_opt = 0;
#endif

  for (auto from : distances)
  {
    std::vector<std::string> tour;

    dfs(from.first, tour, curr_opt);
  }

  assert(curr_opt != -1);

  return curr_opt;
}

#ifndef TEST
int main(int argc, char const *argv[])
{
  Input input(__FILE__);

  world world;

  for (std::string line : input)
  {
    world.readLine(line);
  }

  std::cout << world.optimalTour() << std::endl;

  return 0;
}
#endif