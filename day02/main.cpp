#include <string>
#include <iostream>
#include <algorithm>
#include <input.hpp>

size_t run(std::string line)
{
  unsigned int dimensions[3] = {0, 0, 0};
  size_t pos = 0;

  for (size_t j = 0; j < 3; j++)
  {
    size_t new_pos = line.find('x', pos);

    dimensions[j] = std::stoi(line.substr(pos, new_pos - pos));

    pos = new_pos + 1;
  }

#ifdef PART1
  unsigned int sides[3] = {
      dimensions[0] * dimensions[1],
      dimensions[1] * dimensions[2],
      dimensions[2] * dimensions[0]};
#endif
#ifdef PART2
  unsigned int sides[3] = {
      2 * (dimensions[0] + dimensions[1]),
      2 * (dimensions[1] + dimensions[2]),
      2 * (dimensions[2] + dimensions[0])};
#endif

  unsigned int *min = std::min_element(sides, sides + 3);

#ifdef PART1
  return ((2 * sides[0]) + (2 * sides[1]) + (2 * sides[2])) + *min;
#endif
#ifdef PART2
  return (dimensions[0] * dimensions[1] * dimensions[2]) + *min;
#endif
}

#ifndef TEST
int main(int argc, char const *argv[])
{
  Input input(__FILE__);

  size_t sum = 0;

  for (std::string line : input)
  {
    sum += run(line);
  }

  std::cout << sum << std::endl;

  return 0;
}
#endif