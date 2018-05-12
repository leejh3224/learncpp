#include <iostream>
#include <string>
#include <algorithm>

int getCountNames()
{
  // how many names you wish to enter
  int countNames;
  std::cout << "How many names would you like to enter? ";
  std::cin >> countNames;

  return countNames;
}

void addNames(std::string *names, const int length)
{
  int nextNameIndex = 0;

  for (int i = 0; i < length; i++)
  {
    std::cout << "Enter name #" << i + 1 << ": ";

    std::string newName;
    std::cin >> newName;

    names[i] = newName;

    nextNameIndex++;
  }
}

void sort(std::string *array, const int length)
{
  for (int startIndex = 0; startIndex < length - 1; ++startIndex)
  {
    int smallestIndex = startIndex;

    // Then look for a smaller element in the rest of the array
    for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
    {
      if (array[currentIndex] < array[smallestIndex])
        smallestIndex = currentIndex;
    }

    std::swap(array[startIndex], array[smallestIndex]);
  }
}

int main()
{
  int countNames = getCountNames();
  std::string *names = new std::string[countNames];

  addNames(names, countNames);

  sort(names, countNames);

  for (int j = 0; j < countNames; j++)
    std::cout << names[j] << "\n";

  // should always delete array after using it
  delete[] names;

  return 0;
}