#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <algorithm>

class State
{
private:
  unsigned int vowels;
  bool double_letter;
  bool forbidden;
  char last_letter;

public:
  State();
  ~State();
  void read(char c);
  bool is_nice();
  bool is_sink();
};

State::State()
{
  this->vowels = 0;
  this->double_letter = false;
  this->forbidden = false;
  this->last_letter = '\0';
}

State::~State()
{
}

void State::read(char c)
{
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
}

bool State::is_nice()
{
  return this->vowels >= 3 && this->double_letter && !this->forbidden;
}

bool State::is_sink()
{
  return this->forbidden;
}

bool run(std::string line)
{
  State state;

  for (char c : line)
  {
    state.read(c);

    if (state.is_sink())
    {
      return false;
    }
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