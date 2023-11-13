#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

class Password
{
#ifndef TEST
private:
#else
public:
#endif
  bool satisfiesRequirement1();
  bool satisfiesRequirement2();
  bool satisfiesRequirement3();

public:
  std::string str;
  Password(std::string str);
  ~Password();
  void increment();
  void next();
  bool isValid();
};

// STRAIGHT OF THREE LETTERS
bool Password::satisfiesRequirement1()
{
  for (size_t i = 0; i < str.length() - 2; i++)
  {
    if (str[i] + 1 == str[i + 1] && str[i] + 2 == str[i + 2])
    {
      return true;
    }
  }

  return false;
}

// NOT i, o or l
bool Password::satisfiesRequirement2()
{
  for (size_t i = 0; i < str.length(); i++)
  {
    if (str[i] == 'i' || str[i] == 'o' || str[i] == 'l')
    {
      return false;
    }
  }

  return true;
}

// TWO NON-OVERLAPPING PAIRS
bool Password::satisfiesRequirement3()
{
  bool first_pair = false;
  for (size_t i = 0; i < str.length() - 1; i++)
  {
    if (str[i] == str[i + 1])
    {
      if (first_pair)
      {
        return true;
      }
      first_pair = true;
      i++;
    }
  }

  return false;
}

Password::Password(std::string str)
{
  this->str = str;
}

Password::~Password()
{
}

void Password::increment()
{
  size_t i = str.length() - 1;
  while (i >= 0)
  {
    if (str[i] == 'z')
    {
      str[i] = 'a';
      i--;
    }
    else
    {
      str[i]++;
      break;
    }
  }
}

void Password::next()
{
  do
  {
    increment();
  } while (!isValid());
}

bool Password::isValid()
{
  return satisfiesRequirement1() && satisfiesRequirement2() && satisfiesRequirement3();
}

#ifndef TEST
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

  Password password(input);

  password.next();

#ifdef PART2
  password.next();
#endif

  std::cout << password.str << std::endl;

  /* code */
  return 0;
}
#endif