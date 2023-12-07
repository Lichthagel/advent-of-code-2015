#include <input.hpp>
#include <string>
#include <iostream>
#include <vector>

#define EGGNOG_LITERS 150

int combinations(std::vector<unsigned int> bin_sizes, bool *use_bin, size_t index, unsigned int liters_left, unsigned int total_liters = EGGNOG_LITERS)
{
  if (index == bin_sizes.size())
  {
    unsigned int liters = 0;

    for (size_t i = 0; i < bin_sizes.size(); i++)
    {
      liters += bin_sizes[i] * use_bin[i];
    }

    if (liters == total_liters)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  
  use_bin[index] = false;
  int total = combinations(bin_sizes, use_bin, index + 1, liters_left, total_liters);

  if (bin_sizes[index] <= liters_left)
  {
    use_bin[index] = true;
    total += combinations(bin_sizes, use_bin, index + 1, liters_left - bin_sizes[index], total_liters);
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

  // std::vector<unsigned int> bin_sizes = {20, 15, 10, 5, 5};

  bool *use_bin = new bool[bin_sizes.size()];

  std::cout << combinations(bin_sizes, use_bin, 0, EGGNOG_LITERS) << std::endl;

  delete[] use_bin;

  return 0;
}
#endif