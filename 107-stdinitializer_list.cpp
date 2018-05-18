#include <cassert>
#include <initializer_list>
#include <iostream>

class IntArray
{
private:
  int m_length;
  int *m_data;

public:
  IntArray() : m_length{0}, m_data{nullptr}
  {
  }

  // use initializer_list to initialize IntArray like this { 5, 4, 3, 2, 1 }
  IntArray(const std::initializer_list<int> &list) : IntArray(list.size())
  {
    int count = 0;
    int(auto &element
        : list)
    {
      m_data[count] = element;
      count++;
    }
  }

  // must clean up allocated memory
  ~IntArray()
  {
    delete[] m_data;
  }

  IntArray &operator=(const std::initializer_list<int> &list)
  {
    if (list.size() != m_length)
    {
      delete[] m_data;
      m_length = list.size();
      m_data = new int[m_length];
    }

    int count = 0;
    for (auto &element : list)
    {
      m_data[count] = element;
      ++count;
    }

    return *this;
  }

  int &operator[](const int index)
  {
    assert(index >= 0 && index < m_length);
    return m_data[index];
  }

  int getLength() const { return m_length; }
};

int main()
{
  IntArray{5, 4, 3, 2, 1};
  for (int count = 0; count < array.getLength(); count++)
    std::cout << array[count] << " ";

  return 0;
}