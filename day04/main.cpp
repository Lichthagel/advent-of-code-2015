#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <numeric>

#include <md5.h>

#ifdef PART1
#define LEADING_ZEROS "00000"
#define NUM_LEADING_ZEROS 5
#endif
#ifdef PART2
#define LEADING_ZEROS "000000"
#define NUM_LEADING_ZEROS 6
#endif

size_t run(std::string input)
{
  size_t i = 0;
  std::string hash;

  while (true)
  {
    std::string concatened = input + std::to_string(i);
    hash = MD5(concatened).hexdigest();

    if (hash.substr(0, NUM_LEADING_ZEROS) == LEADING_ZEROS)
    {
      break;
    }

    i++;
  }

  return i;
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

  std::cout << run(input) << std::endl;

  return 0;
}
#endif