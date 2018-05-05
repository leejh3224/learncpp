// angled brackets: from system directory
// why .h is missing?
// because iostream library is under std namespace
#include <iostream>

// quotes: from local directory
// you should provide .h extensions to work as expected
#include "add.h"

using namespace std;

int main()
{

// define statement는 main 함수 내에서 쓰여야함.
// https://stackoverflow.com/questions/5881067/whats-wrong-with-this-c-program
// macro statement는 preprocessor가 컴파일 이전에 subsitution text로 대체함.
// define의 scope는 파일 안에서만 통용됨. 다른 파일에 define이 돼더라도 인식하지 못함.
#define PRINT_JOE "joe"

#ifdef PRINT_JOE
  cout << PRINT_JOE << endl;
#endif

// ifndef => ifdef의 반대, if not defined
#ifndef PRINT_BOB
  cout << "Bob" << endl;
#endif

  cout << add(3, 4) << endl;

  return 0;
}