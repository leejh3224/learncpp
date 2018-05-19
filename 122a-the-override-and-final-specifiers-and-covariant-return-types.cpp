#include <iostream>

class A
{
public:
  virtual const char *getName1(int x) { return "x"; }
  virtual const char *getName2(int x) { return "x"; }
};

class B : public A
{
public:
  // override?
  // override specifies that member function in child class "explicitly" overrides that of parent class.
  // it produces compile error if it has different parameters or different types e.g. const
  virtual const char *getName1(short int x) override { return "B"; }
  virtual const char *getName2(int x) const { return "B"; }
};

int main()
{
  // without virtual keyword, rBase would use A::getName1() instead of B::getName1()
  // By using virtual keyword, it specifies that getName1() call should be match most appropriate version
  // which is B::getName1()
  // Although, virtual keyword in B class is not mandatory, it is recommended to use virtual in both classes because it is more clear
  B b;
  A &rBase{b}; // rBase has A type and reference to B b

  std::cout << rBase.getName1(1) << "\n";
  std::cout << rBase.getName2(2) << "\n";

  return 0;
}

// final -> prevent overriding of virtual functions
class A
{
public:
  virtual const char *getName() { return "A"; }
};

// final keyword after classname: prevents inheriting
class B final : public A
{
public:
  // note use of final specifier on following line -- that makes this function no longer overridable
  virtual const char *getName() override final { return "B"; } // okay, overrides A::getName()
};

class C : public B
{
public:
  virtual const char *getName() override { return "C"; } // compile error: overrides B::getName(), which is final
};

// covariant return types
#include <iostream>

class Base
{
public:
  // This version of getThis() returns a pointer to a Base class
  virtual Base *getThis()
  {
    std::cout << "called Base::getThis()\n";
    return this;
  }
  void printType() { std::cout << "returned a Base\n"; }
};

class Derived : public Base
{
public:
  // Normally override functions have to return objects of the same type as the base function
  // However, because Derived is derived from Base, it's okay to return Derived* instead of Base*
  virtual Derived *getThis()
  {
    std::cout << "called Derived::getThis()\n";
    return this;
  }
  void printType() { std::cout << "returned a Derived\n"; }
};

int main()
{
  Derived d;
  Base *b = &d;
  d.getThis()->printType();  // calls Derived::getThis(), returns a Derived*, calls Derived::printType
  b->getThis()->printType(); // calls Derived::getThis(), returns a Base*, calls Base::printType
}

// ignoring virtual functions
#include <iostream>

class Base
{
public:
  virtual const char *getName() { return "Base"; }
};

class Derived : public Base
{
public:
  virtual const char *getName() { return "Derived"; }
};

int main()
{
  Derived derived;
  Base &base = derived;
  // Calls Base::GetName() instead of the virtualized Derived::GetName()
  std::cout << base.Base::getName() << "\n";

  return 0;
}