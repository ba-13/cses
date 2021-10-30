#include <algorithm>
#include <ctime>
#include <iostream>
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

/**
 * Tabulation is a DP technique that involves iterations instead of recursion
 * We store the values of asked data for all subproblems in a list the size of the input+1, in general
 * In case of Grid Traveller
 * gridTraveller(3,3):
 * *    0   1   2   3
 * * 0!   !   !   !   !
 * * 1!   !   !   !   !
 * * 2!   !   !   !   !
 * * 3!   !   !   !   !
 * Create such a table, fill in some seeds, and iterate properly to get the answer. 
 * In this specific problem, you want to get the 3,3 answer, you know 0,0 and 1,1 answers to be 0 and 1 respectively. 
 * Also, moving backwards to the recursion method, is the key to tabulation approach.
 * Moving backwards means you can when you start from i,j you add its steps to the i+1,j and i,j+1 cell.
 * 
 * Most important logic was how current position contributes to its neighbours
 */

int main()
{
    std::mt19937 mt(69);
    std::uniform_int_distribution<int> dist(10, 1000);
    clock_t start;
    double duration;
    start = clock();
    fastio;

    int m, n;
    std::cin >> m >> n;
    // +1 row and col declared to handle for outer limits
    std::vector<std::vector<ll>> grid(m + 2, std::vector<ll>(n + 2, 0));
    grid[0][0] = 0;
    grid[1][1] = 1;
    fr(i, m + 1)
    {
        fr(j, n + 1)
        {
            grid[i + 1][j] += grid[i][j];
            grid[i][j + 1] += grid[i][j];
        }
    }

    fr(i, m + 1)
    {
        std::cout << i << ": ";
        fr(j, n + 1)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\ngrid(" << m << "," << n << ") : " << grid[m][n];

    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "\nTime: " << duration << " s.\n";
    return 0;
}

/**
 * ! Tabulation Recipe
 * Visualise problem as a table
 * Size of the table based on the inputs
 * Initialise with compatible types, the whole table
 * Seed the trivial answer to the table
 * Iterate through the table
 * Fill furthur positions based on the current position
 */