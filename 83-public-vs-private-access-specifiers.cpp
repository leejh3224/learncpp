#include <iostream>

// simple implementation of stack using class
int main()
{
  class Stack
  {
    int m_array[10];
    int m_next;

  public:
    void reset()
    {
      m_next = 0;
      for (int i = 0; i < 10; i++)
        m_array[i] = 0;
    }

    bool push(int value)
    {
      if (m_next == 10)
        return false;
      m_array[m_next++] = value;
      return true;
    }

    int pop()
    {
      assert(m_next > 0);

      return m_array[m_next--];
    }

    void print()
    {
      for (int i = 0; i < m_next; i++)
        std::cout << m_array[i] << ' ';
    }
  };

  return 0;
}