#include <cassert>

class IntList
{
private:
  int m_list[10];
public:
  // const version and non-const version
  int& operator[] (const int index);
  const int& operator[] (const int index);
};

// why return references?
// if you want to do assignment like for example, list[2] = 3,
// it is possible to do assignment onlyif list[2] equals list.m_list[2] which is l-value.
// if it was 6 - value of list.m_list[2], assignment would be evaluted as 6 =3 which doesn't make any sense. 
int& IntList::operator[] (const int index)
{
  return m_list[index];
}

// Error checking
// typically [] operator doesn't check whether given index is valid or not
const int& IntList::operator[] (const int index) const
{
  assert(index >= 0 && index < 10);
  return m_list[index];
}