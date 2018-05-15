#include <iostream>

class Calc
{
private:
  int m_value;

public:
  Calc(int value = 0) : m_value{value}
  {
  }

  Calc &add(int value)
  {
    m_value += value;
    return *this;
  }

  Calc &sub(int value)
  {
    m_value -= value;
    return *this;
  }

  Calc &mult(int value)
  {
    m_value *= value;
    return *this;
  }

  int getValue()
  {
    return m_value;
  }
};

int main()
{
  Calc calc{3};

  calc.add(3).sub(2).mult(10);

  std::cout << calc.getValue() << "\n";

  return 0;
}