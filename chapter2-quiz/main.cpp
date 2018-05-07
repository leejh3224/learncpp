#include <iostream>
#include <cmath>
#include "constants.h"

using namespace std;

int getInitialTowerHeight()
{
  cout << "Enter the initial height of the tower in meters: ";

  int towerHeight;
  cin >> towerHeight;

  return towerHeight;
}

void printAnswer(int towerHeight, int seconds)
{
  double distanceFallen = constants::gravity * (pow(seconds, 2) / 2);

  double heightAfterSeconds = towerHeight - distanceFallen;

  cout << "At " << seconds << " seconds, the ball is at height: " << heightAfterSeconds << "meters" << std::endl;
}

int main()
{
  int towerHeight = getInitialTowerHeight();

  printAnswer(towerHeight, 0);
  printAnswer(towerHeight, 1);
  printAnswer(towerHeight, 2);
  printAnswer(towerHeight, 3);
  printAnswer(towerHeight, 4);
  printAnswer(towerHeight, 5);
}