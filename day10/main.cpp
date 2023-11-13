#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>

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
  auto input_path = std::filesystem::path(__FILE__).parent_path().append("input.txt");
  std::ifstream input_stream(input_path);
  std::string input;

  if (!input_stream.is_open())
  {
    std::cout << "Unable to open file" << std::endl;
    return 1;
  }

  input_stream >> input;
  input_stream.close();

  for (int i = 0; i < ITERATIONS; i++)
  {
    input = run(input);
  }

  std::cout << input.length() << std::endl;

  return 0;
}
#endif