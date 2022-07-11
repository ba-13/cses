#include <algorithm>
#include <cmath>
#include <ctime>
#include <iostream>
#include <limits.h>
#include <map>
#include <random>
#include <set>
#include <sstream>
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
#define fastio                                                                 \
  std::ios::sync_with_stdio(0);                                                \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);                                                            \
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
#define deb(x)                                                                 \
  if (debugging)                                                               \
    std::cout << #x << " : " << x << "\n";
#define deb2(x, y)                                                             \
  if (debugging)                                                               \
    std::cout << #x << " " << x << " :: " << #y << " " << y << "\n";
// typeof isn't defined everywhere, convert it manually
#define show(c)                                                                \
  if (debugging) {                                                             \
    std::cout << #c << " : ";                                                  \
    for (typeof c.begin() i = c.begin(); i != c.end(); i++)                    \
      std::cout << *i << " ";                                                  \
    std::cout << "\n";                                                         \
  }

int solve(int testcase, ll query);

int main() {
  std::mt19937 mt(69);
  std::uniform_int_distribution<int> dist(10, 1000);
  clock_t start;
  double duration;
  start = clock();
  fastio;
  int testcases;
  ll query;
  std::cin >> testcases;
  fr(testcase, testcases) {
    std::cin >> query;
    solve(testcase, query);
  }
  duration = (clock() - start) / (double)CLOCKS_PER_SEC;
  if (debugging)
    std::cout << "\nTime: " << duration << " s.\n";
  return 0;
}

int solve(int testcase, ll query) {
  if (query < 10) {
    int pos = 0;
    deb2(pos, query);
    std::cout << query << "\n";
    return 0;
  }
  int num_digits = 1;
  std::string nines("9"), nines_prev("9");
  ll nines_, nines_prev_;
  ll partial_sum = 9;
  // check which partial sum is just less than query
  while (num_digits < 19) {
    nines = nines + "0";
    std::stringstream nines__(nines);
    nines__ >> nines_;
    if (query <= partial_sum + (num_digits + 1) * nines_) {
      break;
    }
    num_digits++;
    partial_sum += num_digits * nines_;
    nines_prev = nines_prev + "9";
  }
  query -= partial_sum;
  num_digits++;
  int pos = (query) % num_digits;
  ll num = pos ? (query / num_digits) + 1 : (query / num_digits);
  // ll num = (query / num_digits);
  std::stringstream nines_prev__(nines_prev);

  nines_prev__ >> nines_prev_;
  num += nines_prev_;

  std::string num_string = std::to_string(num);
  // deb(query);
  deb2(pos, num);
  int result = pos - 1 < 0 ? num_digits - 1 : pos - 1;
  std::cout << num_string.at(result) << "\n";
  return 0;
}