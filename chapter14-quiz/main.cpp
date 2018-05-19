#include <stdexcept>
#include <iostream>

class Fraction
{
private:
  int m_numerator;
  int m_denominator;

public:
  Fraction(int numerator = 0, int denominator = 1)
      : m_numerator{numerator}, m_denominator{denominator}
  {
    if (denominator == 0)
      throw std::runtime_error("denominator must be bigger than 0!");
  }

  friend std::ostream &operator<<(std::ostream &out, Fraction &f)
  {
    out << f.m_numerator << "/" << f.m_denominator << "\n";
    return out;
  }
};

int main()
{
  int x;
  int y;

  try
  {
    std::cout << "Please enter numerator: ";
    std::cin >> x;
    std::cout << "Please enter denominator: ";
    std::cin >> y;

    Fraction fraction{x, y};

    std::cout << "Your fraction is " << fraction;
  }
  catch (std::exception &)
  {
    std::cout << "You fraction has an invalid denominator! \n";
  }

  return 0;
}