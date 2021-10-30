#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <algorithm>
#include <map>
// #include <bits/stdc++.h>
typedef long long ll;
typedef std::vector<int> vi;
const ll mod = 1000000007;
const bool debugging = false;
#define deb(x)     \
    if (debugging) \
        cout << #x << " " << x << "\n";
#define fr(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back
#define endl "\n"
using namespace std;

/**
 * Depth is the level of stack, 0 being the root.
 * @l DP Qs are based on the fact that it can be broken down to similar subproblems, and so a tree suits its representation well
 * Trees themselves are recursive in nature, leaves being the base cases, and moving along edges are recursive steps
 */
int depth = 0;
ll go(int row, int col, map<pair<int, int>, ll> &memo);
int goSlow(int row, int col);

int main()
{
    /**
     * We obtain input as row, col. You have to find all possibilities by which a traveller can enter the top-left and exit bottom-right corners by only moving right or down.
     */
    int row, col;
    cin >> row >> col;
    std::map<pair<int, int>, ll> memo;
    // cout << goSlow(row, col);
    cout << go(row, col, memo);
    return 0;
}

/**
 * The approach for recursion is to think of it as a tree, and DP involves optimizing the tree transversal or something, via memoisation or...
 * This problem is just like a spin-off of fibonacci.
 * That's what you need to remember, ~most~ all problems are solved on the basis of your past experiences.
 * Most (all) recursive problems can be represented as trees. Draw one.
 */
int goSlow(int row, int col)
{
    // This implementation is purely recursive, no DP involved, so quite slow.
    // O(2^{row + col}) time
    // O(row + col) space
    deb(row);
    deb(col);
    if (row == 1 && col == 1)
        return 1;
    if (row == 0 || col == 0)
        return 0;
    return goSlow(row - 1, col) + goSlow(row, col - 1);
}

ll go(int row, int col, map<pair<int, int>, ll> &memo)
{
    // key to memoisation, store the return value, and check at the start!
    pair<int, int> key(row, col);
    pair<int, int> key2(col, row);
    if (memo.find(key) != memo.end())
        return memo[key];
    if (memo.find(key2) != memo.end())
        return memo[key2];
    if (row == 1 && col == 1)
        return 1;
    if (row == 0 || col == 0)
        return 0;
    memo[key] = go(row - 1, col, memo) + go(row, col - 1, memo);
    return memo[key];
}

/**
 * Just mentioning here out of no context,
 * Pass by pointer vs Pass by reference!
 * pass by pointer
 * foo(&a);
 * void foo(auto *a) {...}
 *
 * pass by reference
 * bar(a);
 * void bar(auto &a) {...}
 */