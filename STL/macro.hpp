#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <set>
#include <utility>

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> ii;

// non-categorized
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);             \
    cin.exceptions(cin.failbit);

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
#define show(c)                                                 \
    if (debugging)                                              \
    {                                                           \
        std::cout << #c << " : ";                               \
        for (typeof c.begin() i = c.begin(); i != c.end(); i++) \
            std::cout << *i << " ";                             \
        std::cout << "\n";                                      \
    }

// When a token from the left-hand side of #define appears in the right-hand side, it should be placed in braces to avoid many nontrivial problems