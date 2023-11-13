#include <array>
#include <string>
#include <iostream>
#include <input.hpp>

#ifdef PART1
#define GRID_TYPE bool
#define GRID_DEFAULT false
#endif
#ifdef PART2
#define GRID_TYPE unsigned int
#define GRID_DEFAULT 0
#endif

class Instruction
{
private:
  enum Type
  {
    ON,
    OFF,
    TOGGLE
  };
  Type type;
  std::size_t x1;
  std::size_t y1;
  std::size_t x2;
  std::size_t y2;

public:
  Instruction(std::string line);
  ~Instruction();
  friend class Grid;
};

Instruction::Instruction(std::string line)
{
  if (line.substr(0, 7) == "turn on")
  {
    this->type = ON;
    line = line.substr(8);
  }
  else if (line.substr(0, 8) == "turn off")
  {
    this->type = OFF;
    line = line.substr(9);
  }
  else if (line.substr(0, 6) == "toggle")
  {
    this->type = TOGGLE;
    line = line.substr(7);
  }
  else
  {
    throw "Invalid instruction";
  }

  std::size_t pos = line.find(',');
  this->x1 = std::stoi(line.substr(0, pos));
  line = line.substr(pos + 1);
  pos = line.find(' ');
  this->y1 = std::stoi(line.substr(0, pos));
  line = line.substr(pos + 9);
  pos = line.find(',');
  this->x2 = std::stoi(line.substr(0, pos));
  line = line.substr(pos + 1);
  this->y2 = std::stoi(line);
}

Instruction::~Instruction()
{
}

class Grid
{
private:
public:
  std::array<std::array<GRID_TYPE, 1000>, 1000> grid;
  Grid();
  ~Grid();
  void apply(Instruction instruction);
  size_t nlights_on();
};

Grid::Grid()
{
  for (std::array<GRID_TYPE, 1000> &row : this->grid)
  {
    row.fill(GRID_DEFAULT);
  }
}

Grid::~Grid()
{
}

void Grid::apply(Instruction instruction)
{
  for (std::size_t x = instruction.x1; x <= instruction.x2; x++)
  {
    for (std::size_t y = instruction.y1; y <= instruction.y2; y++)
    {
      switch (instruction.type)
      {
      case Instruction::Type::ON:
#ifdef PART1
        this->grid[x][y] = true;
#endif
#ifdef PART2
        this->grid[x][y]++;
#endif
        break;
      case Instruction::Type::OFF:
#ifdef PART1
        this->grid[x][y] = false;
#endif
#ifdef PART2
        if (this->grid[x][y] > 0)
        {
          this->grid[x][y]--;
        }
#endif
        break;
      case Instruction::Type::TOGGLE:
#ifdef PART1
        this->grid[x][y] = !this->grid[x][y];
#endif
#ifdef PART2
        this->grid[x][y] += 2;
#endif
        break;
      }
    }
  }
}

size_t Grid::nlights_on()
{
  size_t count = 0;

  for (std::size_t x = 0; x < 1000; x++)
  {
    for (std::size_t y = 0; y < 1000; y++)
    {
#ifdef PART1
      if (this->grid[x][y])
      {
        count++;
      }
#endif
#ifdef PART2
      count += this->grid[x][y];
#endif
    }
  }

  return count;
}

#ifndef TEST
int main(int argc, char const *argv[])
{
  Input input(__FILE__);

  Grid grid;

  for (std::string line : input)
  {
    Instruction instruction(line);

    grid.apply(instruction);
  }

  std::cout << grid.nlights_on() << std::endl;

  return 0;
}
#endif
