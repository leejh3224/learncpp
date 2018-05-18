#include <iostream>

class IntArray
{
private:
  int m_size;
  int *m_array = nullptr;

public:
  IntArray(int size) : m_size{size}
  {
    // prevent bad data
    assert(size > 0 && "IntArray length should be a positive integer");
    m_array = new int[size]{0};
  }

  // copy constructor
  IntArray(const IntArray &array) : m_size{array.m_size}
  {
    m_array = new int[m_size];

    for (int count = 0; count < array.m_size; count++)
      m_array[count] = array.m_array[count];
  }

  // destructor
  // free dynamically allocated memory
  ~IntArray()
  {
    delete[] m_array;
  }

  int &operator[](const int index)
  {
    // prevent bad data
    assert(index >= 0);
    assert(index < m_size);
    return m_array[index];
  }

  IntArray &operator=(const IntArray &array)
  {
    if (this == &array)
      return *this;

    delete[] m_array;

    m_size = array.m_size;

    m_array = new int[m_size];

    for (int count = 0; count < array.m_size; count++)
      m_array[count] = array.m_array[count];

    return *this;
  }

  friend std::ostream &operator<<(std::ostream &out, const IntArray &array)
  {
    for (int index = 0; index < array.m_size; index++)
      out << array.m_array[index] << " ";
    return out;
  }
};

IntArray fillArray()
{
  IntArray a(5);
  a[0] = 5;
  a[1] = 8;
  a[2] = 2;
  a[3] = 3;
  a[4] = 6;

  return a;
}

int main()
{
  IntArray a = fillArray();
  std::cout << a << '\n';

  IntArray b(1);
  a = a;
  b = a;

  std::cout << b << '\n';

  return 0;
}