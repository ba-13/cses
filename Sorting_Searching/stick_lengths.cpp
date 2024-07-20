#include <algorithm>
#include <ctime>
#include <iostream>
#include <numeric>
#include <random>
#include <stdlib.h>
#include <vector>
#define endl "\n"
#define fr(i, n) for (int i = 0; i < n; ++i)
#define ll long long
#define vi std::vector<int>

int main()
{
    int n;
    std::cin >> n;
    vi p(n);
    fr(i, n) std::cin >> p[i];
    std::sort(p.begin(), p.end());
    int median = n / 2;
    int median2 = n / 2 + 1;
    ll cost = 0;
    ll cost2 = 0;
    fr(i, n)
    {
        cost += std::abs(p[i] - p[median]);
        cost2 += std::abs(p[i] - p[median2]);
    }
    std::cout << std::min(cost, cost2);
    return 0;
}