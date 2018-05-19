#include <iostream>

class A
{
private:
  int m_x;

public:
  A(int x) : m_x{x}
  {
    if (x <= 0)
      throw 1;
  }
};

class B : public A
{
public:
  B(int x)
  try : A(x)
  {
  }
  catch (...)
  {
    // without function try blocks, catch block in main would be executed.
    std::cerr << "Construction of A failed \n";
  }
};

int main()
{
  try
  {
    B b{1};
  }
  catch (int)
  {
    std::cout << "Oops\n";
  }

  return 0;
}