#include <iostream>
// #include <bits/stdc++.h>
typedef long long ll;
const ll mod = 1000000007;
#define deb(x) cout << #x << " " << x << "\n";
#define fr(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll output = 0;
    while (n / 5)
    {
        output += n / 5;
        n /= 5;
    }
    cout << output << endl;
    return 0;
}