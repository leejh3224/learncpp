#include <iostream>
#include <cstdint>

class RGBA
{
  std::uint8_t m_red;
  std::uint8_t m_green;
  std::uint8_t m_black;
  std::uint8_t m_alpha;

public:
  RGBA(std::uint8_t red = 0, std::uint8_t green = 0, std::uint8_t black = 0, std::uint8_t alpha = 255)
      : m_red{red}, m_green{green}, m_black{black}, m_alpha{alpha}
  {
  }

  void print()
  {
    // uint8_t is identical to char type or ascii code value
    // so if you provide m_red with 0, you would see blank(under ascii code 32, those characters are invisible)
    // you need to convert it to different int type in order to see it as integer
    std::cout << "r=" << static_cast<uint>(m_red)
              << " g=" << static_cast<uint>(m_green)
              << " b=" << static_cast<uint>(m_black)
              << " a=" << static_cast<uint>(m_alpha)
              << "\n";
  }
};

int main()
{
  RGBA teal{72, 127, 127};
  teal.print();
  return 0;
}