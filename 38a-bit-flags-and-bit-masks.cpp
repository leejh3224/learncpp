#include <iostream>

int main()
{
  const unsigned char isHungry = 1 << 0;
  const unsigned char isSad = 1 << 1;
  const unsigned char isMad = 1 << 2;
  const unsigned char isHappy = 1 << 3;
  const unsigned char isLaughing = 1 << 4;
  const unsigned char isAsleep = 1 << 5;
  const unsigned char isDead = 1 << 6;
  const unsigned char isCrying = 1 << 7;

  unsigned char me = 0;
  me |= isHappy | isLaughing;
  me &= ~isLaughing;

  std::cout << "Am I happy now? " << static_cast<bool>(me & isHappy) << "\n";
  std::cout << "Am I laughing now? " << static_cast<bool>(me & isLaughing) << "\n";

  return 0;
}

// another example
#include <bitset>
#include <iostream>

// Note that with std::bitset, our options correspond to bit indices, not bit patterns
const int option0 = 0;
const int option1 = 1;
const int option2 = 2;
const int option3 = 3;
const int option4 = 4;
const int option5 = 5;
const int option6 = 6;
const int option7 = 7;

int main()
{
  std::bitset<8> bits(0x2); // we need 8 bits, start with bit pattern 0000 0010
  bits.set(option4);        // set bit 4 to 1 (now we have 0001 0010)
  bits.flip(option5);       // flip bit 5 (now we have 0011 0010)
  bits.reset(option5);      // set bit 5 back to 0 (now we have 0001 0010)

  std::cout << "Bit 4 has value: " << bits.test(option4) << '\n';
  std::cout << "Bit 5 has value: " << bits.test(option5) << '\n';
  std::cout << "All the bits: " << bits << '\n';

  return 0;
}

// bitmask example
#include <iostream>
#include <bitset>

int main()
{
  const unsigned int lowMask = 0xF;

  std::cout << "Enter an integer: ";
  int num;
  std::cin >> num;

  // leave only lowest 4 bits if num is 151
  num &= lowMask;

  // to print output as binary format, store number in 4 bits bitset and convert it to string
  std::cout << "The 4 low bits have value: " << std::bitset<4>(num).to_string() << "\n";

  return 0;
}

// rgba converter
#include <iostream>

int main()
{
  const unsigned int redBits = 0xFF000000;
  const unsigned int greenBits = 0x00FF0000;
  const unsigned int blueBits = 0x0000FF00;
  const unsigned int alphaBits = 0x000000FF;

  // instead of 6 digits hex value, use 8 digits value: add alpha value
  std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
  unsigned int pixel;
  std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value

  // use bitwise AND to isolate red pixels, then right shift the value into the range 0-255
  unsigned char red = (pixel & redBits) >> 24;
  unsigned char green = (pixel & greenBits) >> 16;
  unsigned char blue = (pixel & blueBits) >> 8;
  unsigned char alpha = pixel & alphaBits;

  std::cout << "Your color contains:\n";
  std::cout << static_cast<int>(red) << " of 255 red\n";
  std::cout << static_cast<int>(green) << " of 255 green\n";
  std::cout << static_cast<int>(blue) << " of 255 blue\n";
  std::cout << static_cast<int>(alpha) << " of 255 alpha\n";

  return 0;
}
