#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>

std::pair<size_t, size_t> run(std::string line)
{
  size_t out = 0;

  size_t pos = 0;

  while (pos < line.size())
  {
    if (line[pos] == '"')
    {
      pos++;
#ifdef PART2
      out += 2;
#endif
    }
    else if (line[pos] == '\\')
    {
#ifdef PART1
      if (line[pos + 1] == 'x')
      {
        pos += 4;
        out += 1;
      }
      else
      {
        pos += 2;
        out += 1;
      }
#endif
#ifdef PART2
      pos += 1;
      out += 2;
#endif
    }
    else
    {
      pos++;
      out++;
    }
  }

#ifdef PART2
  out += 2;
#endif

  return std::make_pair(line.size(), out);
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

  size_t sum_in = 0;
  size_t sum_out = 0;

  while (std::getline(input_stream, line))
  {
    auto result = run(line);

    sum_in += result.first;
    sum_out += result.second;
  }

#ifdef PART1
  std::cout << (sum_in - sum_out) << std::endl;
#endif
#ifdef PART2
  std::cout << (sum_out - sum_in) << std::endl;
#endif

  return 0;
}
#endif
