#include <iostream>
// #include <bits/stdc++.h>
typedef long long ll;
#define deb(x) cout << #x << " " << x << "\n";
#define fr(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int solve(ll);

int main()
{
    ll n;
    cin >> n;
    solve(n);
    return 0;
}

int solve(ll i)
{
    for (ll n = 1; n <= i; n++)
    {
        cout << n * n * (n * n - 1) / 2 - 4 * (n - 1) * (n - 2) << "\n";
    }
    return 0;
}