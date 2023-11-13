#include <string>
#include <iostream>
#include <input.hpp>

#ifdef PART1
#define ITERATIONS 40
#endif
#ifdef PART2
#define ITERATIONS 50
#endif

std::string run(std::string s)
{
  std::string out;
  unsigned int sum = 0;
  char prevChar = 0;

  for (int i = 0; i < s.length(); i++)
  {
    char currentChar = s[i];

    if (currentChar == prevChar)
    {
      sum++;
    }
    else
    {
      if (prevChar != 0)
      {
        out += std::to_string(sum) + prevChar;
      }
      sum = 1;
      prevChar = currentChar;
    }
  }

  out += std::to_string(sum) + prevChar;

  return out;
}

#ifndef TEST
int main(int argc, char const *argv[])
{
  Input input(__FILE__);

  std::string s = *input;

  for (int i = 0; i < ITERATIONS; i++)
  {
    s = run(s);
  }

  std::cout << s.length() << std::endl;

  return 0;
}
#endif