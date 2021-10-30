#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
// #include <bits/stdc++.h>
typedef long long ll;
typedef std::vector<int> vi;
const ll mod = 1000000007;
#define deb(x) cout << #x << " " << x << "\n";
#define fr(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back
#define endl "\n"
using namespace std;

ll sumNumbers(ll);

int main()
{
    ll n;
    cin >> n;
    ll sum = sumNumbers(n);
    deb(sum);
    return 0;
}

ll sumNumbers(ll n)
{
    if (n <= 0)
        return n;
    return n + sumNumbers(n - 1);
}