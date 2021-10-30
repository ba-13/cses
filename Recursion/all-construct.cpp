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

std::vector<std::vector<std::string>> allConstructSlow(std::string target, std::vector<std::string> &wordBank);
std::vector<std::vector<std::string>> allConstructFast(std::string target, std::vector<std::string> &wordBank, std::map<std::string, std::vector<std::vector<std::string>>> &memo);

int main()
{
    std::mt19937 mt(69);
    std::uniform_int_distribution<int> dist(10, 1000);
    clock_t start;
    double duration;
    start = clock();
    fastio;

    /**
     * Function should return an array of ways of constructing target by concatenating elements of wordBank
     */
    std::string target;
    std::cin >> target;
    int n;
    std::cin >> n;
    std::vector<std::string> wordBank(n);
    fr(i, n) std::cin >> wordBank[i];
    std::vector<std::vector<std::string>> result;
    std::map<std::string, std::vector<std::vector<std::string>>> memo;
    // result = allConstructSlow(target, wordBank);
    result = allConstructFast(target, wordBank, memo);
    fr(i, result.size())
    {
        std::cout << "[";
        fr(j, result[i].size())
        {
            std::cout << "\"" << result[i][result[i].size() - j - 1] << "\""
                      << ", ";
        }
        std::cout << "]\n";
    }

    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "\nTime: " << duration << " s.\n";
    return 0;
}

/**
 * Note why passing result down and up a stack wouldn't help for now at least
 * Cause you don't have a way to track which child is returning a valid path to the parent...and adding that parent-child link to that path. If you maintain a vector for each parent level, a vector of paths, that would be easy to pass back.
 */
std::vector<std::vector<std::string>> allConstructSlow(std::string target, std::vector<std::string> &wordBank)
{
    std::vector<std::vector<std::string>> result;
    if (target == "")
    {
        std::vector<std::string> tmp;
        tmp.push_back("");
        result.push_back(tmp);
        return result;
    }
    // iterating through all wordBank
    fr(i, wordBank.size())
    {
        // check for target size comparison before getting substr
        if (target.size() >= wordBank[i].size())
        {
            // comparing substr and word
            if (target.substr(0, wordBank[i].size()) == wordBank[i])
            {
                // paths from current node's children, assuming we get valid data from this
                std::vector<std::vector<std::string>> tmp = allConstructSlow(target.substr(wordBank[i].size()), wordBank);
                fr(j, tmp.size())
                {
                    // adding that suffix to that path
                    tmp[j].push_back(wordBank[i]);
                    // adding the whole path to the current (root for now), to the result, which is of the current...but you can pretend it to be the root
                    result.push_back(tmp[j]);
                }
            }
        }
    }
    // std::vector<std::string> tmp;
    // result.push_back(tmp);

    return result;
}

std::vector<std::vector<std::string>> allConstructFast(std::string target, std::vector<std::string> &wordBank, std::map<std::string, std::vector<std::vector<std::string>>> &memo)
{
    // we didn't much improve the time complexity, cause leaf nodes comprise of n^m still...
    if (memo.find(target) != memo.end())
        return memo[target];
    std::vector<std::vector<std::string>> result;
    if (target == "")
    {
        std::vector<std::string> tmp;
        tmp.push_back("");
        result.push_back(tmp);
        return result;
    }
    fr(i, wordBank.size())
    {
        if (target.size() >= wordBank[i].size())
        {
            if (target.substr(0, wordBank[i].size()) == wordBank[i])
            {
                std::vector<std::vector<std::string>> tmp = allConstructSlow(target.substr(wordBank[i].size()), wordBank);
                fr(j, tmp.size())
                {
                    tmp[j].push_back(wordBank[i]);
                    result.push_back(tmp[j]);
                }
            }
        }
    }
    memo[target] = result;
    return result;
}

/*
abcdef
7
ab abc cd def abcd ef c
*/