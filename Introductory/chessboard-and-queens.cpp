#include <algorithm>
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
const bool debugging = false;

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

const int N = 8;
int result = 0;
int nQueens(std::vector<std::vector<char>> &board, int row);
int isSafe(std::vector<std::vector<char>> &board, int row, int col);
void showBoard(std::vector<std::vector<char>> &board);

int main()
{
    std::mt19937 mt(69);
    std::uniform_int_distribution<int> dist(10, 1000);
    clock_t start;
    double duration;
    start = clock();
    fastio;

    std::vector<std::vector<char>> board(N, std::vector<char>(N, '.'));
    fr(i, N)
    {
        fr(j, N)
            board[i][j] = getchar();
        getchar();
    }
    if (nQueens(board, 0))
    {
        std::cout << result;
    };

    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    if (debugging)
        std::cout << "\nTime: " << duration << " s.\n";
    return 0;
}

int nQueens(std::vector<std::vector<char>> &board, int row)
{
    if (row == N)
    {
        result++;
        deb(result);
        showBoard(board);
        if (debugging)
            std::cout << "\n";
        return 1;
    }

    bool res = 0;
    fr(j, N)
    {
        if (board[row][j] != '*')
        {
            if (isSafe(board, row, j))
            {
                board[row][j] = 'Q';
                if (nQueens(board, row + 1))
                    res = 1;
                board[row][j] = '.';
            }
        }
    }
    return res;
}

int isSafe(std::vector<std::vector<char>> &board, int row, int col)
{
    fr(i, N)
        fr(j, N)
    {
        if (board[i][j] == 'Q')
        {
            if (i == row || j == col)
                return 0;
            if (i + j == row + col)
                return 0;
            if (i - j == row - col)
                return 0;
        }
    }
    return 1;
}

void showBoard(std::vector<std::vector<char>> &board)
{
    if (!debugging)
        return;
    fr(i, N)
    {
        fr(j, N)
                std::cout
            << board[i][j] << " ";
        std::cout << "\n";
    }
}

/*
........
........
..*.....
........
........
.....**.
...*....
........

65
*/