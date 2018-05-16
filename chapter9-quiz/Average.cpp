#include <iostream>
#include <cstdint>

class Average
{
private:
  int32_t m_total = 0;
  int8_t m_numbers = 0;

public:
  Average()
  {
  }

  friend std::osteam &operator<<(std::ostream &out, const Average &average)
  {
    out << static_cast<double>(average.m_total) / average.m_numbers;
    return out;
  }

  Average &operator+=(int num)
  {
    m_total += num;
    ++m_number;
    return *this;
  }
};

int main()
{
  Average avg;

  avg += 4;
  std::cout << avg << "\n";

  (avg += 6) += 10;
  std::cout << avg << "\n";

  return 0;
}