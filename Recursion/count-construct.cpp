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

int countConstruct(std::string target, std::vector<std::string> wordBank);
int countConstructFast(std::string target, std::vector<std::string> wordBank, std::map<std::string, int> &memo);

int main()
{
    std::mt19937 mt(69);
    std::uniform_int_distribution<int> dist(10, 1000);
    clock_t start;
    double duration;
    start = clock();
    fastio;

    /**
     * We want number of ways the target can be constructed by concatenating elements of wordBank
     */
    std::string target;
    std::cin >> target;
    std::cout << target << "\n";
    int n;
    std::cin >> n;
    std::vector<std::string> wordBank(n);
    std::map<std::string, int> memo;
    fr(i, n)
            std::cin >>
        wordBank[i];
    show(wordBank);

    // std::cout << countConstruct(target, wordBank);
    std::cout << countConstructFast(target, wordBank, memo);

    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "\nTime: " << duration << " s.\n";
    return 0;
}

int countConstruct(std::string target, std::vector<std::string> wordBank)
{
    if (target == "")
        return 1;
    int totalCount = 0;
    fr(i, wordBank.size())
    {
        if (target.size() >= wordBank[i].size())
        {
            if (target.substr(0, wordBank[i].size()) == wordBank[i])
            {
                // prefix
                /**
                 * smallerCount stores that branch's returning solutions,
                 * so it has to be stored as the sum somewhere.
                 */
                try
                {
                    int smallerCount = countConstruct(target.substr(wordBank[i].size()), wordBank);
                    totalCount += smallerCount;
                }
                catch (int allowed)
                {
                    std::cout << "\nHere Error\n";
                }
            }
        }
    }

    return totalCount;
}

int countConstructFast(std::string target, std::vector<std::string> wordBank, std::map<std::string, int> &memo)
{
    if (memo.find(target) != memo.end())
        return memo[target];
    if (target == "")
        return 1;
    int totalCount = 0;
    fr(i, wordBank.size())
    {
        if (target.size() >= wordBank[i].size())
        {
            if (target.substr(0, wordBank[i].size()) == wordBank[i])
            {
                int smallerCount = countConstruct(target.substr(wordBank[i].size()), wordBank);
                totalCount += smallerCount;
            }
        }
    }
    memo[target] = totalCount;
    return totalCount;
}

/*
enterapotentpot
7
a p ent enter ot o t
*/