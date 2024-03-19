#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <limits.h>
#include <map>
#include <random>
#include <set>
#include <string>
#include <utility>
#include <vector>
// #include <bits/stdc++.h>

using std::clock;
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> ii;
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vii;

const ll mod = 1000000007;
const bool debugging = true;

// non-categorized
#define fastio                    \
    std::ios::sync_with_stdio(0); \
    std::cin.tie(0);              \
    std::cout.tie(0);             \
    std::cin.exceptions(std::cin.failbit);

// shortening frequent phrases
#define pb push_back
#define mp make_pair

// shortening frequent expression
#define sz(a) int((a).size()) // converting from uint to int
#define all(x) x.begin(), x.end()
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

// iteration shorthands
#define fr(i, n) for (int i = 0; i < n; i++)
#define tr(c, i) for (typeof c.begin() i = c.begin(); i != c.end(); i++)

// debugging macros
#define deb(x)     \
    if (debugging) \
        std::cout << #x << " : " << x << "\n";
#define deb2(x, y) \
    if (debugging) \
        std::cout << #x << " " << x << " :: " << #y << " " << y << "\n";
// typeof isn't defined everywhere, convert it manually
#define show(c)                                                 \
    if (debugging)                                              \
    {                                                           \
        std::cout << #c << " : ";                               \
        for (typeof c.begin() i = c.begin(); i != c.end(); i++) \
            std::cout << *i << " ";                             \
        std::cout << "\n";                                      \
    }

// ! Only square values allowed
const int largeBoxSize = 9;
const int smallBoxSize = sqrt(largeBoxSize);

int solve(vii &board);
int foundUnassignedLocation(vii &board, int &row, int &col);
int isSafe(vii &board, int row, int col, int val);
void printSudoku(vii &board);

int main()
{
    std::mt19937 mt(69);
    std::uniform_int_distribution<int> dist(10, 1000);
    clock_t start;
    double duration;
    start = clock();
    fastio;

    vii board(largeBoxSize, vi(largeBoxSize, 0));
    fr(i, largeBoxSize)
            fr(j, largeBoxSize)
                std::cin >>
        board[i][j];
    std::cout << "Unsolved Sudoku:\n";
    printSudoku(board);
    if (solve(board))
    {
        std::cout << "Solved Sudoku:\n";
        printSudoku(board);
    }
    else
    {
        std::cout << "Unsolvable Sudoku.";
    }

    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    if (debugging)
        std::cout << "\nTime: " << duration << " s.\n";
    return 0;
}

int solve(vii &board)
{
    int row, col;
    if (!foundUnassignedLocation(board, row, col))
        return true; // sudoku complete
    // row,col contains 0 rn
    for (int val = 1; val < 10; val++)
    {
        if (isSafe(board, row, col, val))
        {
            board[row][col] = val;
            if (solve(board))
                return 1;
            board[row][col] = 0;
        }
    }
    return 0;
}

int foundUnassignedLocation(vii &board, int &row, int &col)
{
    for (row = 0; row < sz(board); row++)
        for (col = 0; col < sz(board); col++)
            if (board[row][col] == 0)
                return 1;
    return 0;
}

int isSafe(vii &board, int row, int col, int val)
{
    // row check
    fr(j, sz(board))
    {
        if (board[row][j] == val)
            return 0;
    }
    // col check
    fr(i, sz(board))
    {
        if (board[i][col] == val)
            return 0;
    }
    // box start values
    int smallBoxStartRow = row - (row % smallBoxSize);
    int smallBoxStartCol = col - (col % smallBoxSize);
    for (int i = smallBoxStartRow; i < smallBoxStartRow + smallBoxSize; i++)
        for (int j = smallBoxStartCol; j < smallBoxStartCol + smallBoxSize; j++)
        {
            if (board[i][j] == val)
                return 0;
        }

    return 1;
}

void printSudoku(vii &board)
{
    fr(i, sz(board))
    {
        fr(j, sz(board))
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

/*
Unsolved Sudoku: 
0 0 0 8 0 1 0 0 0 
0 0 0 0 0 0 4 3 0 
5 0 0 0 0 0 0 0 0 
0 0 0 0 7 0 8 0 0 
0 0 0 0 0 0 1 0 0 
0 2 0 0 3 0 0 0 0 
6 0 0 0 0 0 0 7 5 
0 0 3 4 0 0 0 0 0 
0 0 0 2 0 0 6 0 0 
Solved Sudoku: 
2 3 4 8 9 1 5 6 7 
1 6 9 7 2 5 4 3 8 
5 7 8 3 4 6 9 1 2 
3 1 6 5 7 4 8 2 9 
4 9 7 6 8 2 1 5 3 
8 2 5 1 3 9 7 4 6 
6 4 2 9 1 8 3 7 5 
9 5 3 4 6 7 2 8 1 
7 8 1 2 5 3 6 9 4 

Time: 11.886 s.
*/