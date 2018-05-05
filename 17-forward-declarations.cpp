#include <iostream>

// main 함수에서 add 함수가 어떤 리턴 타입을 가지는지 또 파라미터는 어떤 타입을 가지는지를 미리 알려줌
// c++같은 경우에는 javascript와 달리 함수 선언이 호이스팅하지 않기 때문에 컴파일러에서 에러가 발생함
int add(int x, int y);

int main()
{
  std::cout << "The sum of 3 and 4 is " << add(3, 4) << std::endl;
  return 0;
}

int add(int x, int y)
{
  return x + y;
}