#include <input.hpp>
#include <string>
#include <regex>
#include <iostream>

class Reindeer
{
private:
  static std::regex lineRegex;
  unsigned int cycleTime;

public:
  unsigned int flySpeed;
  unsigned int flyTime;
  unsigned int restTime;
  Reindeer(std::string line);
  ~Reindeer();
  unsigned int getDistance(unsigned int time);
};

std::regex Reindeer::lineRegex = std::regex("^(\\w+) can fly (\\d+) km/s for (\\d+) seconds, but then must rest for (\\d+) seconds.$");

Reindeer::Reindeer(std::string line)
{
  std::smatch match;

  std::regex_match(line, match, lineRegex);

  flySpeed = std::stoi(match[2]);
  flyTime = std::stoi(match[3]);
  restTime = std::stoi(match[4]);

  cycleTime = flyTime + restTime;
}

Reindeer::~Reindeer()
{
}

unsigned int Reindeer::getDistance(unsigned int time)
{
  unsigned int distance = 0;

  unsigned int completeCycles = time / cycleTime;

  distance += completeCycles * flySpeed * flyTime;

  unsigned int remainingTime = time % cycleTime;

  distance += std::min(remainingTime, flyTime) * flySpeed;

  return distance;
}

#ifndef TEST
int main(int argc, char const *argv[])
{
  Input input(__FILE__);

  std::vector<Reindeer> reindeers;

  for (auto line : input)
  {
    reindeers.push_back(Reindeer(line));
  }

  unsigned int max = 0;

  for (auto reindeer : reindeers)
  {
    unsigned int distance = reindeer.getDistance(2503);

    if (distance > max)
    {
      max = distance;
    }
  }

  std::cout << max << std::endl;

  /* code */
  return 0;
}
#endif