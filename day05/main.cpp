#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <array>

namespace std
{
  template <>
  struct hash<std::array<char, 2>>
  {
    std::size_t operator()(const std::array<char, 2> &k) const
    {
      return std::hash<char>()(k[0]) ^ (std::hash<char>()(k[1]) << 1);
    }
  };
}

class State
{
private:
#ifdef PART1
  unsigned int vowels;
  bool double_letter;
  bool forbidden;
  char last_letter;
#endif
#ifdef PART2
  std::array<char, 2> last;
  std::unordered_set<std::array<char, 2>> pairs;
  bool cond1;
  bool cond2;
#endif

public:
  State();
  ~State();
  void read(char c);
  bool is_nice();
#ifdef PART1
  bool is_sink();
#endif
};

State::State()
{
#ifdef PART1
  this->vowels = 0;
  this->double_letter = false;
  this->forbidden = false;
  this->last_letter = '\0';
#endif
#ifdef PART2
  this->last[0] = '\0';
  this->last[1] = '\0';
  this->cond1 = false;
  this->cond2 = false;
#endif
}

State::~State()
{
}

void State::read(char c)
{
#ifdef PART1
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
  {
    this->vowels++;
  }

  if (c == this->last_letter)
  {
    this->double_letter = true;
  }

  if ((c == 'b' && this->last_letter == 'a') || (c == 'd' && this->last_letter == 'c') || (c == 'q' && this->last_letter == 'p') || (c == 'y' && this->last_letter == 'x'))
  {
    this->forbidden = true;
  }

  this->last_letter = c;
#endif
#ifdef PART2
  std::array<char, 2> new_pair = {this->last[1], c};

  if (!this->cond1 && this->pairs.find(new_pair) != this->pairs.end())
  {
    this->cond1 = true;
  }

  if (!this->cond2 && this->last[0] == c)
  {
    this->cond2 = true;
  }

  this->pairs.insert(this->last);
  this->last = new_pair;
#endif
}

bool State::is_nice()
{
#ifdef PART1
  return this->vowels >= 3 && this->double_letter && !this->forbidden;
#endif
#ifdef PART2
  return this->cond1 && this->cond2;
#endif
}

#ifdef PART1
bool State::is_sink()
{
  return this->forbidden;
}
#endif

bool run(std::string line)
{
  State state;

  for (char c : line)
  {
    state.read(c);

#ifdef PART1
    if (state.is_sink())
    {
      return false;
    }
#endif
#ifdef PART2
    if (state.is_nice())
    {
      return true;
    }
#endif
  }

  return state.is_nice();
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

  size_t nnice = 0;

  while (std::getline(input_stream, line))
  {
    nnice += run(line);
  }

  std::cout << nnice << std::endl;

  return 0;
}
#endif