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

class Race
{
private:
  std::vector<Reindeer> reindeers;

public:
  Race(Input input);
  Race(std::vector<Reindeer> reindeers);
  ~Race();
  unsigned int totalDistanceWinner(unsigned int time);
  std::vector<unsigned int> points(unsigned int time);
  unsigned int pointsWinner(unsigned int time);
};

Race::Race(Input input)
{
  for (auto line : input)
  {
    this->reindeers.push_back(Reindeer(line));
  }
}

Race::Race(std::vector<Reindeer> reindeers)
{
  this->reindeers = reindeers;
}

Race::~Race()
{
}

unsigned int Race::totalDistanceWinner(unsigned int time)
{
  unsigned int max = 0;

  for (auto reindeer : reindeers)
  {
    unsigned int distance = reindeer.getDistance(time);

    if (distance > max)
    {
      max = distance;
    }
  }

  return max;
}

std::vector<unsigned int> Race::points(unsigned int time)
{
  size_t n = this->reindeers.size();

  std::vector<unsigned int> points(this->reindeers.size());
  std::vector<unsigned int> distances(this->reindeers.size());
  std::vector<int> power(this->reindeers.size());

  for (size_t i = 0; i < n; i++)
  {
    points[i] = 0;
    distances[i] = 0;
    power[i] = this->reindeers[i].flyTime;
  }

  for (unsigned int t = 0; t < time; t++)
  {
    unsigned int maxDistance = 0;

    for (size_t i = 0; i < n; i++)
    {

      if (power[i] <= -((int)this->reindeers[i].restTime))
      {
        power[i] = this->reindeers[i].flyTime;
      }

      if (power[i] > 0)
      {
        distances[i] += this->reindeers[i].flySpeed;
      }

      power[i]--;
      if (distances[i] >= maxDistance)
      {
        maxDistance = distances[i];
      }
    }

    for (size_t i = 0; i < n; i++)
    {
      if (distances[i] == maxDistance)
      {
        points[i]++;
      }
    }
  }

  return points;
}

unsigned int Race::pointsWinner(unsigned int time)
{
  std::vector<unsigned int> points = this->points(time);

  return *std::max_element(points.begin(), points.end());
}

#ifndef TEST
int main(int argc, char const *argv[])
{
  Race race(Input(__FILE__));

#ifdef PART1
  std::cout << race.totalDistanceWinner(2503) << std::endl;
#endif

#ifdef PART2
  std::cout << race.pointsWinner(2503) << std::endl;
#endif

  return 0;
}
#endif