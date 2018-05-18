// header guards
// header file에는 main function과 함수 정의를 포함하는 .cpp 파일 간에
// 서로를 인식하기 위해 사용될 forward declaration만 포함하는 것이 좋다.
// square.h
#ifndef SQUARE_H
#define SQUARE_H

int getSquareSides();

int getSquarePerimeter(int sideLength);

#endif

// square.cpp
// 실제로 함수를 정의하는 곳
#include "square.h"

int getSquarePerimeter(int sideLength)
{
  return sideLength * getSquareSides();
}

int getSquareSides()
{
  return 4;
}

// forward declaration된 함수들을 실제로 사용.
// main.cpp
// square.cpp와 함께 컴파일될 때 square.h 파일을 이용해서 링크함.
#include <iostream>
#include "square.h"

int main()
{
  std::cout << "a square has " << getSquareSides() << " sides" << std::endl;
  std::cout << "a square of length 5 has perimeter length  " << getSquarePerimeter(5) << std::endl;

  return 0;
}