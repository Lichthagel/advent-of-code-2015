#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>

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
      std::cout << i + 1 << std::endl;
      return 0;
    }
#endif
  }

#ifdef PART1
  std::cout << floor << std::endl;
#endif

#ifdef PART2
  std::cout << -1 << std::endl;
#endif

  /* code */
  return 0;
}
