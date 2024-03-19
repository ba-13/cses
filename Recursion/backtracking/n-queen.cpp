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

#define vii std::vector<std::vector<int>>
int N;

int nQueen(vii &board, int row);
int isSafe(vii &board, int row, int col);
void showRow(vi arr);

int main()
{
    std::mt19937 mt(69);
    std::uniform_int_distribution<int> dist(10, 1000);
    clock_t start;
    double duration;
    start = clock();
    fastio;
    /**
     * Backtracking Q1
     * N-Queens - State one way in which we can place N Queens in a N*N chessboard.
     * One straight conclusion is each row will have one queen, so directly mentioning the column number would suffice as a configuration, cause all queens are identical
     * That's how the solution will be, array of size N, having N distinct numbers, stating where 0 to N-1 row-th queen would be in that numbered column
     */

    std::cin >> N;
    vii board(N, std::vector<int>(N));
    if (nQueen(board, 0))
    {
        std::cout << "Solved!\n";
        fr(i, N)
        {
            showRow(board[i]);
        }
    }
    else
    {
        std::cout << "Not solved...\n";
    }

    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "\nTime: " << duration << " s.\n";
    return 0;
}

/**
 * @brief checks if position is safe
 * 
 * @param board chessboard
 * @param row row-check
 * @param col col-check
 * @return int 
 */
int isSafe(vii &board, int row, int col)
{
    fr(i, N)
        fr(j, N)
    {
        // we are sure that the current position is 0
        // so check if (i,j) is 1
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

/**
 * @brief solves the nQueen for one solution
 * 
 * @param board chessboard
 * @param row row to be solved
 * @return int 
 */
int nQueen(vii &board, int row)
{
    if (row == N)
        return 1;
    fr(i, N)
    {
        if (isSafe(board, row, i))
        {
            board[row][i] = 1;
            if (nQueen(board, row + 1))
                return 1;
            board[row][i] = 0;
        }
    }
    return 0;
}

void showRow(vi arr)
{
    fr(i, arr.size())
    {
        if (arr[i])
            // std::cout << "\033[1;31m" << arr[i] << "\033[0m ";
            std::cout << "\033 ";
        else
            std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}