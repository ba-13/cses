#include <iostream>
// #include <bits/stdc++.h>
typedef long long ll;
const ll mod = 1000000007;
#define deb(x) cout << #x << " " << x << "\n";
#define fr(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

ll binary_exponentiation(ll);

int main()
{
    ll n;
    cin >> n;
    cout << binary_exponentiation(n);
    return 0;
}

ll binary_exponentiation(ll n)
{
    if (n == 1)
        return 2;
    else if (n == 0)
        return 1;
    else
    {
        return (2 * binary_exponentiation(n - 1)) % mod;
    }
}