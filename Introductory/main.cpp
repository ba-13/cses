#include <ctime>
#include <iostream>
#include <random>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#define deb(x) cout << #x << "=" << x << "." << endl
#define endl "\n"
#define fr(i, n) for (int i = 0; i < n; ++i)
#define ll long long
#define vi std::vector<int>

using namespace std;

int main() {
  ll s_;
  string s("9");
  std::stringstream s__(s);
  s__ >> s_;
  std::cout << s_ << " ";
  fr(i, 17) {
    s = s + "0";
    std::stringstream s__(s);
    s__ >> s_;
    std::cout << s_ << " ";
  }
  return 0;
}