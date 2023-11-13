#include "input.hpp"

#include <filesystem>
#include <iostream>

InputIterator::InputIterator()
{
  this->input_stream = nullptr;
}

InputIterator::InputIterator(std::ifstream *input_stream)
{
  this->input_stream = input_stream;
  this->operator++();
}

InputIterator::~InputIterator()
{
}

std::string InputIterator::operator*()
{
  return this->current_line;
}

InputIterator &InputIterator::operator++()
{
  if (!std::getline(*this->input_stream, this->current_line))
  {
    this->input_stream = nullptr;
  }

  return *this;
}

bool InputIterator::operator!=(const InputIterator &other)
{
  return this->input_stream != other.input_stream;
}

Input::Input(const char *sourcefile)
{
  auto input_path = std::filesystem::path(sourcefile).parent_path().append("input.txt");
  this->input_stream.open(input_path);

  if (!this->input_stream.is_open())
  {
    throw std::runtime_error("Unable to open file");
  }
}

Input::~Input()
{
  this->input_stream.close();
}

InputIterator Input::begin()
{
  return InputIterator(&this->input_stream);
}

InputIterator Input::end()
{
  return InputIterator();
}

std::string Input::operator*()
{
  return *this->begin();
}
