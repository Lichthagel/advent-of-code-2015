#include <string>
#include <iostream>
#include <input.hpp>

int run(std::string input)
{
  int sum = 0;

  for (size_t pos = 0; pos < input.size();)
  {
    pos = input.find_first_of("-0123456789", pos);

    if (pos == std::string::npos)
    {
      break;
    }

    size_t end = input.find_first_not_of("0123456789", pos + 1);

    if (end == std::string::npos)
    {
      end = input.size();
    }

    int number = std::stoi(input.substr(pos, end - pos));

    sum += number;

    pos = end;
  }

  return sum;
}

#ifndef TEST
int main()
{
  Input input(__FILE__);

  std::cout << run(*input) << std::endl;

  return 0;
}
#endif
