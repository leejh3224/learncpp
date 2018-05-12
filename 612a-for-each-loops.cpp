#include <iostream>

int main()
{
  const int numStudents = 5;
  int scores[numStudents] = {84, 92, 76, 81, 56};
  int maxScore = 0;

  // const reference is preferred because they are less expensive than copying each element of array
  for (const auto &score : scores)
    if (score > maxScore)
      maxScore = score;

  std::cout << "The best score was " << maxScore << '\n';

  return 0;
}