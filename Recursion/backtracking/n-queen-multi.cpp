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

#define vii std::vector<std::vector<int>>
vii result;
int nQueens(vii &board, int row);
int isSafe(vii &board, int row, int col);
vii initiate(int N);
void showBoard(vii &board);

int main()
{
    std::mt19937 mt(69);
    std::uniform_int_distribution<int> dist(10, 1000);
    clock_t start;
    double duration;
    start = clock();
    fastio;

    int N;
    std::cin >> N;
    vii result = initiate(N);
    for (auto ar : result)
    {
        std::cout << "[ ";
        for (auto it : ar)
            std::cout << it << " ";
        std::cout << "]";
    }

    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "\nTime: " << duration << " s.\n";
    return 0;
}

int nQueens(vii &board, int row)
{
    int N = board.size();
    // base case
    if (row == N)
    {
        vi tmp;
        fr(i, N)
            fr(j, N)
        {
            if (board[i][j])
            {
                tmp.pb(j);
            }
        }
        result.push_back(tmp);
        return 1;
    }
    // confirms that that row has a solution, no need to backtrack (yet)
    bool res = 0;
    fr(j, N)
    {
        showBoard(board);
        if (debugging)
            std::cout << "\n";
        if (isSafe(board, row, j))
        {
            board[row][j] = 1;
            if (nQueens(board, row + 1))
            {
                deb2(row, j);
                res = 1;
            }
            board[row][j] = 0;
        }
    }
    if (!res && debugging)
        std::cout << "Backtrack..!\n";
    return res;
}

int isSafe(vii &board, int row, int col)
{
    int N = board.size();
    fr(i, N)
        fr(j, N)
    {
        if (board[i][j])
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

vii initiate(int N)
{
    result.clear();
    vii board(N, vi(N, 0));
    if (nQueens(board, 0) == false)
    {
        return {};
    }
    std::sort(result.begin(), result.end());
    return result;
}

void showBoard(vii &board)
{
    if (!debugging)
        return;
    fr(i, board.size())
    {
        fr(j, board.size())
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}