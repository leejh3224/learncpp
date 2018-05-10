#include <iostream>
#include <string>

std::string getUserName()
{
  std::cout << "Please enter your full name: ";
  std::string fullName;

  // it works similarly to std::cin but can catch whole line instead of one word
  std::getline(std::cin, fullName);

  return fullName;
}

int getUserAge()
{
  std::cout << "Enter your age: ";
  int age;
  std::cin >> age;

  return age;
}

int main()
{
  /* 
   * if getUserAge() was called first, we should ignore \n(new line) character
   * to get things done correctly. It's because without ignore() call \n will be assinged
   * to username.
   * 
   * std::cin.ignore(32767, \n); 32767 stands for how many charcters will you ignore
   */
  std::string fullName = getUserName();
  int age = getUserAge();
  int letters = fullName.length();

  // explicitly casting double type to denominator or numerator, we can get result in double type.
  // c++ basically returns int type for this type of calculation
  double agePerLetter = static_cast<double>(age) / letters;

  std::cout << "You've lived " << agePerLetter
            << " years for each letter in your name"
            << "\n";

  return 0;
}