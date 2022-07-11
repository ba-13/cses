#include <ctime>
#include <iostream>
#include <random>
#include <stdexcept>
#include <stdlib.h>
#include <utility>
#include <vector>
#define deb(x) cout << #x << "=" << x << "." << endl
#define endl "\n"
#define fr(i, n) for (int i = 0; i < n; ++i)
#define ll long long
#define vi std::vector<int>
using namespace std;

const int SZ = 7;
std::invalid_argument OtherVal("Enter ?, U, R, D, L only");
// vi visited(SZ *SZ);
vi steps(SZ *SZ - 1);
struct current
{
  int x;
  int y;
  int step;
  current(int x, int y, int step) : x(x), y(y), step(step) {}
};
current curr(0, 0, 0);

std::vector<vi> grid(7, std::vector<int>(SZ, -1));
int result = 0;

int move(int);
int traverse(int step);

int main()
{
  //    1
  //  4 0 2
  //    3
  char step;
  grid[0][0] = 1;
  fr(i, SZ * SZ - 1)
  {
    step = getchar();
    switch (step)
    {
    case '?':
      steps[i] = 0;
      break;
    case 'U':
      steps[i] = 1;
      break;
    case 'R':
      steps[i] = 2;
      break;
    case 'D':
      steps[i] = 3;
      break;
    case 'L':
      steps[i] = 4;
      break;
    default:
      throw OtherVal;
    }
  }
  curr.step = 0;
  curr.x = 0;
  curr.y = 0;
  fr(i, SZ * SZ - 1) cout << steps[i] << " ";
  traverse(0);
  cout << "\nSteps: " << result << "\n";
  return 0;
}

int move(int moveIdx, int step)
{
  if (steps[moveIdx] == 0)
    return -1;
  else if (steps[moveIdx] == 1)
  {
    curr.x = curr.x - 1;
    curr.y = curr.y;
    curr.step = step;
  }
  else if (steps[moveIdx] == 2)
  {
    curr.x = curr.x;
    curr.y = curr.y + 1;
    curr.step = step;
  }
  else if (steps[moveIdx] == 3)
  {
    curr.x = curr.x + 1;
    curr.y = curr.y;
    curr.step = step;
  }
  else if (steps[moveIdx] == 4)
  {
    curr.x = curr.x;
    curr.y = curr.y - 1;
    curr.step = step;
  }
  return 0;
}

/**
 * @brief Call after taking a move, i.e. changing curr
 *
 * @return true
 * @return false
 */
bool validMove()
{
  if (curr.x < 0 || curr.x > SZ - 1)
    return false;
  if (curr.y < 0 || curr.y > SZ - 1)
    return false;
  if (grid[curr.x][curr.y] == 1)
    return false;
  return true;
}

int traverse(int step)
{
  if (!validMove())
    return -1;
  if (step > SZ * SZ - 1)
    return -1;
  if (curr.x == SZ - 1 && curr.y == SZ - 1)
  {
    result++;
    return 1;
  }

  grid[curr.x][curr.y] = 1;

  if (steps[step] != 0)
  {
    move(steps[step], step + 1);
    traverse(step + 1);
    curr.step -= 1;
  }
  else
  {
    for (int i = 1; i < 5; i++)
    {
      move(i, step + 1);
      traverse(step + 1);
      curr.step -= 1;
    }
  }
  return -1;
}