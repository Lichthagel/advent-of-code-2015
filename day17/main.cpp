#include <input.hpp>
#include <string>
#include <iostream>
#include <vector>
#ifdef PART2
#include <unordered_map>
#endif

#define EGGNOG_LITERS 150

int combinations(
    std::vector<unsigned int> &bin_sizes,
#ifdef PART2
    std::unordered_map<unsigned int, unsigned int> &combinations_map,
#endif
    bool *use_bin,
    size_t index,
    unsigned int liters_left,
    unsigned int total_liters)
{
  if (index == bin_sizes.size())
  {
    unsigned int liters = 0;
#ifdef PART2
    unsigned int nused = 0;
#endif

    for (size_t i = 0; i < bin_sizes.size(); i++)
    {
      liters += bin_sizes[i] * use_bin[i];
#ifdef PART2
      nused += use_bin[i];
#endif
    }

    if (liters == total_liters)
    {
#ifdef PART2
      combinations_map[nused]++;
#endif
      return 1;
    }
    else
    {
      return 0;
    }
  }

  use_bin[index] = false;
  int total = combinations(
      bin_sizes,
#ifdef PART2
      combinations_map,
#endif
      use_bin,
      index + 1,
      liters_left,
      total_liters);

  if (bin_sizes[index] <= liters_left)
  {
    use_bin[index] = true;
    total += combinations(
      bin_sizes,
#ifdef PART2
      combinations_map,
#endif
      use_bin,
      index + 1,
      liters_left - bin_sizes[index],
      total_liters);
  }

  return total;
}

#ifndef TEST
int main(int argc, char const *argv[])
{
  Input input(__FILE__);

  std::vector<unsigned int> bin_sizes;

  for (auto line : input)
  {
    bin_sizes.push_back(std::stoi(line));
  }
  
  bool *use_bin = new bool[bin_sizes.size()];

#ifdef PART1
  std::cout << combinations(bin_sizes, use_bin, 0, EGGNOG_LITERS, EGGNOG_LITERS) << std::endl;
#endif

#ifdef PART2
  std::unordered_map<unsigned int, unsigned int> combinations_map;

  combinations(bin_sizes, combinations_map, use_bin, 0, EGGNOG_LITERS, EGGNOG_LITERS);

  unsigned int min = UINT32_MAX;

  for (auto combination : combinations_map)
  {
    if (combination.first < min)
    {
      min = combination.first;
    }
  }

  std::cout << combinations_map[min] << std::endl;
#endif

  delete[] use_bin;

  return 0;
}
#endif