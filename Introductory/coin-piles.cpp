#include <iostream>
// #include <bits/stdc++.h>
typedef long long ll;
const ll mod = 1000000007;
#define deb(x) cout << #x << " " << x << "\n";
#define fr(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int solve();
int maxI(ll *, ll *);

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
        solve();
    return 0;
}

int solve()
{
    ll a, b;
    cin >> a >> b;
    maxI(&a, &b);
    if (a > 2 * b)
    {
        cout << "NO"
             << "\n";
        return 0;
    }
    else
    {
        ll k = a - b;
        b -= k;
        a -= 2 * k;
        if (b < 0)
        {
            cout << "NO"
                 << "\n";
            return 0;
        }
        if (b % 3 == 0)
            cout << "YES"
                 << "\n";
        else
            cout << "NO"
                 << "\n";
    }
    //TODO
}

int maxI(ll *a, ll *b)
{
    if (*a > *b)
        return 0;
    else
    {
        ll tmp;
        tmp = *a;
        *a = *b;
        *b = tmp;
        return 0;
    }
}