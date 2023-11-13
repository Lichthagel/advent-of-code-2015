#include <string>
#include <iostream>
#include <input.hpp>

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
  Input input(__FILE__);

  size_t result = run(*input);

  std::cout << result << std::endl;

  return 0;
}
#endif