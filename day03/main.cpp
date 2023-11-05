#include <filesystem>
#include <fstream>
#include <string>
#include <iostream>
#include <unordered_set>

struct Position
{
  ssize_t x;
  ssize_t y;

  Position(ssize_t x, ssize_t y) : x(x), y(y) {}

  bool operator==(const Position &other) const
  {
    return x == other.x && y == other.y;
  }
};

namespace std
{
  template <>
  struct hash<Position>
  {
    std::size_t operator()(const Position &position) const
    {
      return std::hash<ssize_t>()(position.x) ^ std::hash<ssize_t>()(position.y);
    }
  };
}

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

  std::unordered_set<Position> visited;

  Position santa1(0, 0);
#ifdef PART2
  Position santa2(0, 0);
#endif

  visited.insert(santa1);

  for (size_t i = 0; i < input.length(); i++)
  {
#ifdef PART1
    Position &current = santa1;
#endif
#ifdef PART2
    Position &current = i % 2 == 0 ? santa1 : santa2;
#endif

    switch (input[i])
    {
    case '^':
      current.y++;
      break;
    case 'v':
      current.y--;
      break;
    case '>':
      current.x++;
      break;
    case '<':
      current.x--;
      break;
    }

    visited.insert(current);
  }

  std::cout << visited.size() << std::endl;

  return 0;
}
