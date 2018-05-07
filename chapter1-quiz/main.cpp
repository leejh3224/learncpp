#include "io.h"
#include <iostream>

int main()
{
  int num1 = readNumber();
  int num2 = readNumber();
  int sum = num1 + num2;

  writeAnswer(sum);

  return 0;
}