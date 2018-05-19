// smart pointer
// a composition class that is designed to manage dynamically allocated memory
// and ensure that memory gets deleted when the smart pointer object goes out of scope

// critical flaw
#include <iostream>

// Same as above
template <class T>
class Auto_ptr1
{
  T *m_ptr;

public:
  Auto_ptr1(T *ptr = nullptr)
      : m_ptr(ptr)
  {
  }

  ~Auto_ptr1()
  {
    delete m_ptr;
  }

  T &operator*() const { return *m_ptr; }
  T *operator->() const { return m_ptr; }
};

class Resource
{
public:
  Resource() { std::cout << "Resource acquired\n"; }
  ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
  /*
   * as no assignment operator overload or copy constructor are suppliled,
   * compiler will shallow copy res1
   * as a result, res1 and res2 points to same memory address which is undesirable
   */
  Auto_ptr1<Resource> res1(new Resource);
  Auto_ptr1<Resource> res2(res1); // Alternatively, don't initialize res2 and then assign res2 = res1;
  return 0;
}

// move semantics
#include <iostream>

template <class T>
class Auto_ptr2
{
  T *m_ptr;

public:
  Auto_ptr2(T *ptr = nullptr) : m_ptr{ptr}
  {
  }

  ~Auto_ptr2()
  {
    delete m_ptr;
  }

  Auto_ptr2(Auto_ptr2 &a)
  {
    // transfer our dumb pointer from the source to local object
    m_ptr = a.m_ptr;

    // make sure the source no longer owns the pointer
    a.m_ptr = nullptr;
  }

  Auto_ptr2 &operator=(Auto_ptr2 &a)
  {
    // self-assignment
    if (&a == this)
      return *this;

    // deallocate any pointer already holding first
    delete m_ptr;

    // transfer our dumb pointer from the source to local object
    m_ptr = a.m_ptr;

    a.m_ptr = nullptr;
    return *this;
  }

  T &operator*() const { return *m_ptr; }
  T *operator->() const { return m_ptr; }
  bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
public:
  Resource() { std::cout << "Resource acquired\n"; }
  ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main()
{
  Auto_ptr2<Resource> res1(new Resource);
  Auto_ptr2<Resource> res2; // Start as nullptr

  std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
  std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

  res2 = res1; // res2 assumes ownership, res1 is set to null

  std::cout << "Ownership transferred\n";

  std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
  std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

  return 0;
}