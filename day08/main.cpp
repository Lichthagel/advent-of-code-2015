#include <iostream>
#include <string>
#include <input.hpp>

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
  Input input(__FILE__);

  size_t sum_in = 0;
  size_t sum_out = 0;

  for (std::string line : input)
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
