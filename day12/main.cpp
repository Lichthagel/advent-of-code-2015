#include <string>
#include <iostream>
#ifdef PART2
#include <stack>
#endif
#include <cassert>
#include <input.hpp>

int run(std::string input)
{

#ifdef PART1
  int sum = 0;
#endif
#ifdef PART2
  std::stack<std::pair<int, bool>> stack;

  // first: sum, second: is_array
  std::pair<int, bool> current;
#endif

  size_t end;
  int number;

  for (size_t pos = 0; pos < input.size();)
  {
    switch (input[pos])
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '-':
      end = input.find_first_not_of("0123456789", pos + 1);

      assert(end != std::string::npos);

      number = std::stoi(input.substr(pos, end - pos));

#ifdef PART1
      sum += number;
#endif
#ifdef PART2
      assert(!stack.empty());

      stack.top().first += number;
#endif
      pos = end;
      break;

#ifdef PART2
    case '{':
      stack.push(std::make_pair(0, false));

      pos++;
      break;
    case '[':
      stack.push(std::make_pair(0, true));

      pos++;
      break;

    case '}':
    case ']':
      assert(stack.size() > 0);
      assert(stack.top().second == (input[pos] == ']'));

      current = stack.top();
      stack.pop();

      if (stack.size() == 0)
      {
        return current.first;
      }
      else
      {
        stack.top().first += current.first;
      }

      pos++;
      break;

    case 'r':
      // if red and current item is an object, truncate current object
      if (input.substr(pos, 3) == "red" && stack.size() > 0 && !stack.top().second)
      {
        stack.pop();

        // skip current object
        unsigned int object_depth = 1;
        while (object_depth > 0)
        {
          pos = input.find_first_of("{}", pos);
          assert(pos != std::string::npos);

          if (input[pos] == '{')
          {
            object_depth++;
          }
          else
          {
            object_depth--;
          }
          pos++;
        }

        if (stack.size() == 0)
        {
          return 0;
        }
      }
      else
      {
        pos++;
      }

      break;
#endif

    default:
      pos++;
      break;
    }
  }

#ifdef PART1
  return sum;
#endif
#ifdef PART2
  assert(stack.size() == 0);
  assert(false);
#endif
}

#ifndef TEST
int main()
{
  Input input(__FILE__);

  std::cout << run(*input) << std::endl;

  return 0;
}
#endif
