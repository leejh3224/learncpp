#include <array>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

const vector<vector<char>> board{
    {'U', 'R', 'L', 'P', 'M'},
    {'X', 'P', 'R', 'E', 'T'},
    {'G', 'I', 'A', 'E', 'T'},
    {'X', 'T', 'N', 'Z', 'Y'},
    {'X', 'O', 'Q', 'R', 'S'}};

/*
 * <재귀함수>
 * 
 * dx와 dy
 * 가능한 모든 조합의 움직임을 dy, dy로 만들어놓고 (8방향), 두 가지의 기저 사례를 살핀다.
 * 첫 번째는 범위를 벗어나는 일 (inRange 함수를 통해 확인),
 * 두 번째는 첫 번째로 확인한 글자가 word의 첫 글자와 다를 때 (무조건 false),
 * 이 두 가지 사례를 제외하면 무조건 true.
 * 
 * 이제 반복문을 통해 8방향을 확인한다.
 * 
 * 시간 복잡도?
 * 탐색은 단어의 길이 n에 대해 n-1 단계 진행됨.
 * 그러므로 검사하는 후보의 수는 최대 8^n-1회 진행됨.
 * 복잡도는 O(8^n)
 */
const array<int, 8> dx{
    -1, -1, -1, 1, 1, 1, 0, 0};

const array<int, 8> dy{
    -1, 0, 1, -1, 0, 1, -1, 1};

bool inRange(int y, int x)
{
  int max{board.size()};
  return y < max || y > 0 || x < max || x > 0;
}

bool hasWord(int y, int x, const string &word)
{
  if (!inRange(y, x))
    return false;

  if (board[y][x] != word[0])
    return false;

  if (word.size() == 1)
    return true;

  for (int direction = 0; direction < 8; ++direction)
  {
    int nextY = y + dy[direction];
    int nextX = x + dx[direction];

    if (hasWord(nextY, nextX, word.substr(1)))
      return true;
  }

  return false;
}

int main()
{

  string word{"GIRL"};

  bool boggle = hasWord(2, 0, word);

  cout << boggle << "\n";

  return 0;
}