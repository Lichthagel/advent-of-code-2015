#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <algorithm>

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
  auto input_path = std::filesystem::path(__FILE__).parent_path().append("input.txt");
  std::ifstream input_stream(input_path);
  std::string line;

  if (!input_stream.is_open())
  {
    std::cout << "Unable to open file" << std::endl;
    return 1;
  }

  unsigned int sum = 0;

  while (std::getline(input_stream, line))
  {
    sum += run(line);
  }

  std::cout << sum << std::endl;

  return 0;
}
#endif