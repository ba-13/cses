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
        std::cout << #c << " : [";                              \
        for (typeof c.begin() i = c.begin(); i != c.end(); i++) \
            std::cout << *i << ", ";                            \
        std::cout << "]\n";                                     \
    }

bool canConstructSlow(std::string target, std::vector<std::string> &wordBank);
bool canConstructFast(std::string target, std::vector<std::string> &wordBank, std::map<std::string, bool> &memo);

int main()
{
    std::mt19937 mt(69);
    std::uniform_int_distribution<int> dist(10, 1000);
    clock_t start;
    double duration;
    start = clock();
    // fastio;

    /**
     * canConstruct(target, wordBank) should return a bool indicating whether we can construct the target by concatenating elements in the wordBank array.
     * We can reuse wordBank any number of times which specifically means that the array remains the same for any recursive call
     */
    int n;
    std::string target;
    std::cin >> target;
    std::cin >> n;
    std::vector<std::string> wordBank(n);
    fr(i, n)
            std::cin >>
        wordBank[i];
    deb(target);
    show(wordBank);
    std::map<std::string, bool> memo;
    // std::cout << canConstructSlow(target, wordBank);
    std::cout << canConstructFast(target, wordBank, memo);

    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "\nTime: " << duration << " s.\n";
    return 0;
}

bool canConstructSlow(std::string target, std::vector<std::string> &wordBank)
{
    // taking target as the tree nodes, cause it's what changing
    // note that we need to check if the current target has a suffix or prefix from the wordBank
    /**
     * let m = target.length
     * n - wordBank.length
     * 
     * Worst case: 
     * m - height of tree
     * branching factor: n branches per node
     * each iteration involves substring division, thus m
     * O(m*n^m) time complexity
     * O(m) space complexity, not stored in this case
     */
    if (target == "")
        return true;
    fr(i, wordBank.size())
    {
        // std::cout << target << "\n";
        if (target.size() >= wordBank[i].size() && target.substr(0, wordBank[i].size()) == wordBank[i])
        {
            // prefix found
            std::cout << "Trying prefix with " << wordBank[i] << " and " << target << "\n";
            // directly returning is a no-no, cause once false is reached, it will be returned without checking for other paths
            // return canConstructSlow(target.substr(wordBank[i].size(), target.size()), wordBank);
            if (canConstructSlow(target.substr(wordBank[i].size(), target.size()), wordBank) == true)
                return true;
        }
        /*
         * Why not to include suffix? Cause it leads to double counting, or more!
        else if (target.size() >= wordBank[i].size() && target.substr(target.size() - wordBank[i].size(), target.size()) == wordBank[i])
        {
            // suffix found
            std::cout << "Trying suffix with " << wordBank[i] << " and " << target << "\n";
            if (canConstructSlow(target.substr(0, target.size() - wordBank[i].size()), wordBank) == true)
                return true;
        }*/
    }
    // when no word in wordBank can act as prefix or suffix
    return false;
}

bool canConstructFast(std::string target, std::vector<std::string> &wordBank, std::map<std::string, bool> &memo)
{
    // O(n*m^2) time complexity
    if (memo.find(target) != memo.end())
        return memo[target];
    if (target == "")
        return true;
    fr(i, wordBank.size())
    {
        // std::cout << target << "\n";
        if (target.size() >= wordBank[i].size() && target.substr(0, wordBank[i].size()) == wordBank[i])
        {
            // prefix found
            std::cout << "Trying prefix with " << wordBank[i] << " and " << target << "\n";
            // directly returning is a no-no, cause once false is reached, it will be returned without checking for other paths
            // return canConstructSlow(target.substr(wordBank[i].size(), target.size()), wordBank);
            memo[target] = canConstructFast(target.substr(wordBank[i].size(), target.size()), wordBank, memo);
            if (memo[target] == true)
                return true;
        }
        else if (target.size() >= wordBank[i].size() && target.substr(target.size() - wordBank[i].size(), target.size()) == wordBank[i])
        {
            // suffix found
            std::cout << "Trying suffix with " << wordBank[i] << " and " << target << "\n";
            memo[target] = canConstructFast(target.substr(0, target.size() - wordBank[i].size()), wordBank, memo);
            if (memo[target] == true)
                return true;
        }
    }
    // when no word in wordBank can act as prefix or suffix
    memo[target] = false;
    return false;
}

/*
skateboard
8
bo r te ska a rde ard b 
*/
/*
eeeeeeeeeeeeeeeeeeeeeeeeef
6
e ee eee eeee eeeee eeeeee eeeeeee

0
Time: 35.129 s.
*/