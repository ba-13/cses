#include <ctime>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#define endl "\n"
#define fr(i, n) for (int i = 0; i < n; ++i)
#define ll long long
#define vi std::vector<int>

int main()
{
    int n;
    std::cin >> n;
    vi coins(n);
    fr(i, n) std::cin >> coins[i];
    std::sort(coins.begin(), coins.end());

    // suppose ans is the smallest missing found yet
    ll ans = 1;
    // we can form all numbers from 0 to ans-1
    for (int x : coins)
    {
        if (x > ans)
            break;
        // if x <= ans, we can form values from 0 to ans-1 and
        // x to ans+x-1, which combined is 0 to ans+x-1
        ans += x;
    }
    std::cout << ans;
    return 0;
}