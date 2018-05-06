#include <iostream>

int readNumber()
{
  int userInput;

  std::cout << "Please enter the number: ";
  std::cin >> userInput;

  return userInput;
}

void writeAnswer(int number)
{
  std::cout << "The sum of the two numbers are " << number << std::endl;
}