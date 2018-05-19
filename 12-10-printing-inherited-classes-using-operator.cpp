#include <iostream>

class Base
{
public:
  Base()
  {
  }

  // shows how to virtualize oeprator<<
  // just delegeate task to virtual function print!
  // friend function is not a member function but can call it in its body
  friend std::ostream &operator<<(std::ostream &out, const Base &b)
  {
    return b.print(out);
  }

  virtual std::ostream &print(std::ostream &out) const
  {
    out << "Base\n";
    return out;
  }
};

class Derived : public Base
{
public:
  Derived()
  {
  }

  virtual std::ostream &print(std::ostream &out) const
  {
    out << "Derived\n";
    return out;
  }
};

int main()
{
  Base b;
  std::cout << b << "\n";

  Derived d;
  std::cout << d << "\n";

  Base &ref = d;
  std::cout << ref << "\n";

  return 0;
}