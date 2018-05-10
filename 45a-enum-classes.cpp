#include <iostream>

int main()
{
  // enum class is more desirable, it helps avoiding naming collision between enums
  enum class Color
  {
    RED,
    BLUE,
  };

  enum Animal
  {
    G,
    H
  };

  Color color = Color::BLUE;

  // enum class types can't be compared directly with other enum values
  // they should be casted first and then compared
  if (static_cast<int>(color) == H)
    std::cout << "they are equal"
              << "\n";

  std::cout << static_cast<int>(color) << "\n";

  return 0;
}