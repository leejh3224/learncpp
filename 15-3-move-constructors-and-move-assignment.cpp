// copy semantics
/*
 * output:
 * Resource acquired
 * Resource acquired
 * Resource destroyed
 * Resource destroyed
 */
#include <iostream>

template <class T>
class Auto_ptr3
{
  T *m_ptr;

public:
  Auto_ptr3(T *ptr = nullptr)
      : m_ptr(ptr)
  {
  }

  ~Auto_ptr3()
  {
    delete m_ptr;
  }

  // Copy constructor
  // Do deep copy of a.m_ptr to m_ptr
  Auto_ptr3(const Auto_ptr3 &a)
  {
    m_ptr = new T;
    *m_ptr = *a.m_ptr;
  }

  // Copy assignment
  // Do deep copy of a.m_ptr to m_ptr
  Auto_ptr3 &operator=(const Auto_ptr3 &a)
  {
    // Self-assignment detection
    if (&a == this)
      return *this;

    // Release any resource we're holding
    delete m_ptr;

    // Copy the resource
    m_ptr = new T;
    *m_ptr = *a.m_ptr;

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

Auto_ptr3<Resource> generateResource()
{
  // step1) Resource acquired!
  Auto_ptr3<Resource> res(new Resource);

  // this return value will invoke the copy constructor
  // return by reference or pointer would bring unexpected result because of their duration
  // step2) Resource acquired!
  return res;
} // step3) res goes out of scope, triggering destructor of class Auto_ptr3
// Resource destroyed

int main()
{
  Auto_ptr3<Resource> mainres;

  // step4) copy assingment
  // Resource acquired
  mainres = generateResource(); // this assignment will invoke the copy assignment

  // step5) temperary object goes out of scope
  // Resource destroyed
  return 0;
} // step6) mainres goes out of scope
// Resource destroyed

// move semantics with disabled copy
#include <iostream>

template <class T>
class Auto_ptr5
{
  T *m_ptr;

public:
  Auto_ptr5(T *ptr = nullptr)
      : m_ptr(ptr)
  {
  }

  ~Auto_ptr5()
  {
    delete m_ptr;
  }

  // Copy constructor -- no copying allowed!
  Auto_ptr5(const Auto_ptr5 &a) = delete;

  // Move constructor
  // Transfer ownership of a.m_mptr to m_ptr
  Auto_ptr5(Auto_ptr5 &&a)
      : m_ptr(a.m_ptr)
  {
    a.m_ptr = nullptr;
  }

  // Copy assignment -- no copying allowed!
  Auto_ptr5 &operator=(const Auto_ptr5 &a) = delete;

  // Move assignment
  // Transfer ownership of a.m_ptr to m_ptr
  Auto_ptr5 &operator=(Auto_ptr5 &&a)
  {
    // Self-assignment detection
    if (&a == this)
      return *this;

    // Release any resource we're holding
    delete m_ptr;

    // Transfer ownership of a.m_ptr to m_ptr
    m_ptr = a.m_ptr;
    a.m_ptr = nullptr;

    return *this;
  }

  T &operator*() const { return *m_ptr; }
  T *operator->() const { return m_ptr; }
  bool isNull() const { return m_ptr == nullptr; }
};