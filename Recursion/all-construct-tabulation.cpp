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

int main()
{
    std::mt19937 mt(69);
    std::uniform_int_distribution<int> dist(10, 1000);
    clock_t start;
    double duration;
    start = clock();
    // fastio;

    int n;
    std::string target;
    std::cin >> target >> n;
    std::vector<std::string> wordBank(n);
    fr(i, n) std::cin >> wordBank[i];
    std::vector<std::vector<std::vector<std::string>>> result(target.size() + 1);
    std::vector<std::string> tmp;
    tmp.pb("");
    (result[0]).pb(tmp);

    fr(i, target.size() + 1)
    {
        if (result[i].size() <= 0)
            continue;
        fr(j, wordBank.size())
        {
            if (wordBank[j].size() <= target.size() - i)
            {
                for (int k = i; k <= target.size(); k++)
                {
                    if (wordBank[j] == target.substr(i, k - i))
                    {
                        std::vector<std::string> tmp;
                        for (int l = 0; l < result[i].size(); l++)
                        {
                            // not sure if copy allocates memory too before inserting
                            // tmp.reserve(20);
                            // std::copy(result[i][l].begin(), result[i][l].end(), tmp);
                            for (int m = 0; m < result[i][l].size(); m++)
                                tmp.pb(result[i][l][m]);
                            tmp.pb(wordBank[j]);
                            result[k].pb(tmp);
                            tmp.clear();
                        }
                    }
                }
            }
        }
    }

    fr(i, result.size())
    {
        std::cout << "Position " << i << " : \n";
        fr(j, result[i].size())
        {
            std::cout << j << " : ";
            fr(k, result[i][j].size())
                    std::cout
                << result[i][j][k] << " ";
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "\nTime: " << duration << " s.\n";
    return 0;
}