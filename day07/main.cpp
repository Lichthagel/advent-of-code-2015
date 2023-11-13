#include <iostream>
#include <unordered_map>
#include <cassert>
#include <optional>
#include <vector>
#include <string>
#include <cstdint>
#include <input.hpp>

class Wire
{
public:
  enum WireType
  {
    BINARY,
    UNARY,
    CONSTANT
  };

  enum BinaryOp : uint8_t
  {
    AND,
    OR,
    LSHIFT,
    RSHIFT
  };

  enum UnaryOp : uint8_t
  {
    NOT,
    REWIRE
  };

private:
  WireType type;
  uint8_t op;
  std::optional<uint16_t> value;
  Wire *left_wire;
  Wire *right_wire;

public:
  Wire();
  Wire(uint16_t value);
  Wire(UnaryOp op, Wire *wire);
  Wire(BinaryOp op, Wire *left_wire, Wire *right_wire);
  ~Wire();
  uint16_t evaluate();
#ifdef PART2
  void reset();
#endif
};

Wire::Wire()
{
  this->type = WireType::CONSTANT;
  this->value = std::nullopt;
}

Wire::Wire(uint16_t value)
{
  this->type = WireType::CONSTANT;
  this->value = value;
}

Wire::Wire(UnaryOp op, Wire *wire)
{
  this->type = WireType::UNARY;
  this->op = op;
  this->left_wire = wire;
}

Wire::Wire(BinaryOp op, Wire *left_wire, Wire *right_wire)
{
  this->type = WireType::BINARY;
  this->op = op;
  this->left_wire = left_wire;
  this->right_wire = right_wire;
}

Wire::~Wire()
{
}

uint16_t Wire::evaluate()
{
  if (this->value.has_value())
  {
    return this->value.value();
  }

  if (this->type == WireType::CONSTANT)
  {
    assert(this->value.has_value());
    return this->value.value();
  }

  if (this->type == WireType::UNARY)
  {
    assert(this->left_wire != nullptr);

    uint16_t left_value = this->left_wire->evaluate();

    if (this->op == Wire::UnaryOp::NOT)
    {
      this->value = ~left_value;
    }

    if (this->op == Wire::UnaryOp::REWIRE)
    {
      this->value = left_value;
    }
  }

  if (this->type == WireType::BINARY)
  {
    assert(this->left_wire != nullptr);
    assert(this->right_wire != nullptr);

    uint16_t left_value = this->left_wire->evaluate();
    uint16_t right_value = this->right_wire->evaluate();

    if (this->op == Wire::BinaryOp::AND)
    {
      this->value = left_value & right_value;
    }

    if (this->op == Wire::BinaryOp::OR)
    {
      this->value = left_value | right_value;
    }

    if (this->op == Wire::BinaryOp::LSHIFT)
    {
      this->value = left_value << right_value;
    }

    if (this->op == Wire::BinaryOp::RSHIFT)
    {
      this->value = left_value >> right_value;
    }
  }

  assert(this->value.has_value());

  return this->value.value();
}

#ifdef PART2
void Wire::reset()
{
  if (this->type != WireType::CONSTANT)
  {
    this->value = std::nullopt;
  }
}
#endif

class Wiring
{
private:
  std::unordered_map<std::string, Wire *> wires;
  std::vector<Wire *> unnamed_wires;

public:
  Wiring();
  ~Wiring();

  void parse(std::string line);
  uint16_t evaluate(std::string wire);
#ifdef PART2
  void reset();
#endif
};

Wiring::Wiring()
{
}

Wiring::~Wiring()
{
  for (auto e : this->unnamed_wires)
  {
    delete e;
  }

  for (auto e : this->wires)
  {
    delete e.second;
  }
}

void Wiring::parse(std::string line)
{
  size_t arrow_pos = line.find("->");

  assert(arrow_pos != std::string::npos);

  std::string target_str = line.substr(arrow_pos + 3);

  Wire::WireType type;
  uint8_t op;
  std::string left_str;
  std::string right_str;

  size_t pos;

  if ((pos = line.substr(0, arrow_pos).find("AND")) != std::string::npos)
  {
    type = Wire::WireType::BINARY;
    op = Wire::BinaryOp::AND;
    left_str = line.substr(0, pos - 1);
    right_str = line.substr(pos + 4, arrow_pos - pos - 5);
  }
  else if ((pos = line.substr(0, arrow_pos).find("OR")) != std::string::npos)
  {
    type = Wire::WireType::BINARY;
    op = Wire::BinaryOp::OR;
    left_str = line.substr(0, pos - 1);
    right_str = line.substr(pos + 3, arrow_pos - pos - 4);
  }
  else if ((pos = line.substr(0, arrow_pos).find("LSHIFT")) != std::string::npos)
  {
    type = Wire::WireType::BINARY;
    op = Wire::BinaryOp::LSHIFT;
    left_str = line.substr(0, pos - 1);
    right_str = line.substr(pos + 7, arrow_pos - pos - 8);
  }
  else if ((pos = line.substr(0, arrow_pos).find("RSHIFT")) != std::string::npos)
  {
    type = Wire::WireType::BINARY;
    op = Wire::BinaryOp::RSHIFT;
    left_str = line.substr(0, pos - 1);
    right_str = line.substr(pos + 7, arrow_pos - pos - 8);
  }
  else if ((pos = line.substr(0, arrow_pos).find("NOT")) != std::string::npos)
  {
    type = Wire::WireType::UNARY;
    op = Wire::UnaryOp::NOT;
    left_str = line.substr(pos + 4, arrow_pos - pos - 5);
  }
  else
  {
    type = Wire::WireType::UNARY;
    op = Wire::UnaryOp::REWIRE;
    left_str = line.substr(0, arrow_pos - 1);
  }

  if (type == Wire::BINARY)
  {
    Wire *left_wire;
    Wire *right_wire;

    if (left_str[0] >= '0' && left_str[0] <= '9')
    {
      left_wire = new Wire(std::stoi(left_str));

      this->unnamed_wires.push_back(left_wire);
    }
    else if (this->wires.count(left_str) == 0)
    {
      left_wire = new Wire();

      this->wires[left_str] = left_wire;
    }
    else
    {
      left_wire = this->wires[left_str];
    }

    if (right_str[0] >= '0' && right_str[0] <= '9')
    {
      right_wire = new Wire(std::stoi(right_str));

      this->unnamed_wires.push_back(right_wire);
    }
    else if (this->wires.count(right_str) == 0)
    {
      right_wire = new Wire();

      this->wires[right_str] = right_wire;
    }
    else
    {
      right_wire = this->wires[right_str];
    }

    if (this->wires.count(target_str) == 0)
    {
      this->wires[target_str] = new Wire((Wire::BinaryOp)op, left_wire, right_wire);
    }
    else
    {
      *this->wires[target_str] = Wire((Wire::BinaryOp)op, left_wire, right_wire);
    }

    return;
  }

  if (type == Wire::UNARY)
  {
    Wire *left_wire;

    if (left_str[0] >= '0' && left_str[0] <= '9')
    {
      left_wire = new Wire(std::stoi(left_str));

      this->unnamed_wires.push_back(left_wire);
    }
    else if (this->wires.count(left_str) == 0)
    {
      left_wire = new Wire();

      this->wires[left_str] = left_wire;
    }
    else
    {
      left_wire = this->wires[left_str];
    }

    if (this->wires.count(target_str) == 0)
    {
      this->wires[target_str] = new Wire((Wire::UnaryOp)op, left_wire);
    }
    else
    {
      *this->wires[target_str] = Wire((Wire::UnaryOp)op, left_wire);
    }

    return;
  }

  assert(false);
}

uint16_t Wiring::evaluate(std::string wire)
{
  return this->wires[wire]->evaluate();
}

#ifdef PART2
void Wiring::reset()
{
  for (auto e : this->unnamed_wires)
  {
    e->reset();
  }

  for (auto e : this->wires)
  {
    e.second->reset();
  }
}
#endif

#ifndef TEST
int main(int argc, char const *argv[])
{
  Input input(__FILE__);

  Wiring wiring;

  for (std::string line : input)
  {
    wiring.parse(line);
  }

  uint16_t part1_a = wiring.evaluate("a");

#ifdef PART1
  std::cout << part1_a << std::endl;
#endif

#ifdef PART2
  wiring.parse(std::to_string(part1_a) + " -> b");
  wiring.reset();

  std::cout << wiring.evaluate("a") << std::endl;
#endif

  return 0;
}
#endif
