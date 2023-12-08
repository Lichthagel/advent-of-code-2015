#include <input.hpp>
#include <string>
#include <iostream>
#include <cassert>
#include <vector>

class Grid
{
private:
  std::vector<std::vector<bool>> grid;
#ifdef PART2
  void corners_on();
#endif
public:
  template <typename T>
  Grid(T &input);
  ~Grid();
  void print();
  void step();
  void step(size_t steps);
  size_t count();
};

#ifdef PART2
void Grid::corners_on()
{
  this->grid[0][0] = true;
  this->grid[0][this->grid[0].size() - 1] = true;
  this->grid[this->grid.size() - 1][0] = true;
  this->grid[this->grid.size() - 1][this->grid[0].size() - 1] = true;
}
#endif

template <typename T>
Grid::Grid(T &input)
{
  for (std::string line : input)
  {
    std::vector<bool> row;

    for (char c : line)
    {
      row.push_back(c == '#');
    }

    assert(grid.size() == 0 || grid[0].size() == row.size());

    this->grid.push_back(row);
  }

  assert(this->grid.size() > 0);
  assert(this->grid[0].size() == this->grid.size());

#ifdef PART2
  this->corners_on();
#endif
}

Grid::~Grid()
{
}

void Grid::print()
{
  for (std::vector<bool> row : this->grid)
  {
    for (bool cell : row)
    {
      std::cout << (cell ? '#' : '.');
    }

    std::cout << std::endl;
  }

  std::cout << std::endl;
}

void Grid::step()
{
  std::vector<std::vector<bool>> newGrid(this->grid.size(), std::vector<bool>(this->grid[0].size(), false));

  for (size_t i = 0; i < grid.size(); i++)
  {
    for (size_t j = 0; j < grid[i].size(); j++)
    {
      size_t neighbors = 0;

      for (size_t x = i > 0 ? i - 1 : 0; x < i + 2 && x < grid.size(); x++)
      {
        for (size_t y = j > 0 ? j - 1 : 0; y < j + 2 && y < grid[i].size(); y++)
        {
          if (x == i && y == j)
          {
            continue;
          }

          if (grid[x][y])
          {
            neighbors++;
          }
        }
      }

      if (grid[i][j])
      {
        newGrid[i][j] = neighbors == 2 || neighbors == 3;
      }
      else
      {
        newGrid[i][j] = neighbors == 3;
      }
    }
  }

  this->grid = newGrid;

#ifdef PART2
  this->corners_on();
#endif
}

void Grid::step(size_t steps)
{
  for (size_t i = 0; i < steps; i++)
  {
    this->step();
  }
}

size_t Grid::count()
{
  size_t count = 0;

  for (std::vector<bool> row : this->grid)
  {
    for (bool cell : row)
    {
      if (cell)
      {
        count++;
      }
    }
  }

  return count;
}

#ifndef TEST
int main(int argc, char const *argv[])
{
  Input input(__FILE__);

  Grid grid(input);

  grid.step(100);

  std::cout << grid.count() << std::endl;

  return 0;
}
#endif