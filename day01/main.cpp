#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>

size_t run(std::string input)
{
  int floor = 0;

  for (size_t i = 0; i < input.length(); i++)
  {
    if (input[i] == '(')
    {
      floor++;
    }
    else if (input[i] == ')')
    {
      floor--;
    }

#ifdef PART2
    if (floor == -1)
    {
      return i + 1;
    }
#endif
  }

#ifdef PART1
  return floor;
#endif

#ifdef PART2
  return -1;
#endif
}

#ifndef TEST
int main(int argc, char const *argv[])
{
  auto input_path = std::filesystem::path(__FILE__).parent_path().append("input.txt");
  std::ifstream input_stream(input_path);
  std::string input;

  if (input_stream.is_open())
  {
    input_stream >> input;
    input_stream.close();
  }
  else
  {
    std::cout << "Unable to open file" << std::endl;
    return 1;
  }

  size_t result = run(input);

  std::cout << result << std::endl;

  return 0;
}
#endif