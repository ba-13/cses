#include <algorithm>
#include <cmath>
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

int solve(int testcase);
int solveCorrect(int testcase);
int solve2(int testcase);
int digit_at_n(int digitNumber, ll val);

int main() {
  std::mt19937 mt(69);
  std::uniform_int_distribution<int> dist(10, 1000);
  clock_t start;
  double duration;
  start = clock();
  fastio;

  int testcases;
  std::cin >> testcases;
  fr(i, testcases) { solveCorrect(i); }

  duration = (clock() - start) / (double)CLOCKS_PER_SEC;
  if (debugging)
    std::cout << "\nTime: " << duration << " s.\n";
  return 0;
}

int solve2(int testcase) {
  ll val;
  std::cin >> val;
}

int solve(int testcase) {
  long long val;
  std::cin >> val;
  val++;
  if (val <= 10) {
    std::cout << val - 1 << "\n";
    return 0;
  }
  ll nthOrder = 10;
  int i;
  for (i = 1; i < 20; i++) {
    ll tmp = (i + 1) * 9 * pow(10, i);
    if (nthOrder + tmp > val)
      break;
    nthOrder += tmp;
  }
  deb(nthOrder);
  // now we have the lower limit
  val -= nthOrder;
  deb(val);
  ll leastDigits = pow(10, i);
  deb(leastDigits);
  int digitNumber =
      val % (i + 1); // 0 implies unit digit, 1 implies the highest place digit
  deb(i + 1);

  deb(digitNumber);
  val /= i + 1;
  val += leastDigits;
  val--; // adjusting limits
  deb(val);
  digit_at_n(digitNumber, val);
  return 0;
}

int digit_at_n(int digitNumber, ll val) {
  std::string str = std::to_string(val);
  if (digitNumber != 0)
    std::cout << str[digitNumber - 1] << "\n";
  else
    std::cout << str[str.size() - 1] << "\n";
  return 0;
}

int solveCorrect(int testcase) {
  ll n;
  std::cin >> n;
  int c = 1;
  for (ll p = 9;; n -= p, c++, p = 9 * pow(10, c - 1) * c) {
    if (n - p <= 0)
      break;
  }
  n--;
  ll x = n / c;
  int y = n % c;
  ll ans = pow(10, c - 1) + x;
  // cerr<<ans<<' '<<x<<' '<<y<<' '<<n<<' '<<c;

  std::string s = std::to_string(ans);
  std::cout << s[y] << std::endl;
}

int solve_brute(int testcase) {
  ll value;
  std::cin >> value;
  std::string needed_string = "";
  ll tmp = 1;
  while (1) {
    needed_string.append(std::to_string(tmp));
    if (needed_string.size() > value)
      break;
  }
  std::cout << needed_string[value - 1] << "\n";
}

/*
4
582
214
723
273

0
1
7
7
*/