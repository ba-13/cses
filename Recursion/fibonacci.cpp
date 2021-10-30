#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <algorithm>
// #include <bits/stdc++.h>
typedef long long ll;
typedef std::vector<int> vi;
const ll mod = 1000000007;
#define deb(x) cout << #x << " " << x << "\n";
#define fr(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back
#define endl "\n"
using namespace std;

ll fibonacci(ll, ll *);

int main()
{
    ll n;
    cin >> n;
    ll result[n] = {0};
    fibonacci(n, result);
    fr(i, n)
            cout
        << result[i] << "\n";
    return 0;
}

// n numbers in the result
ll fibonacci(ll n, ll *result)
{
    if (n == 0 || n == 1)
    {
        result[n] = n;
        n--;
        return n + 1;
    }
    else
    {
        // I first imagined result storing the values of the subproblems, and then making the subproblems provide what the problem needs.
        // This is divide and conquer, cause multiple recursive calls
        // This is memoization, a class of DP

        ll a = 0, b = 0;
        if (result[n - 1] != 0)
            a = result[n - 1];
        else
            a = fibonacci(n - 1, result);
        if (result[n - 2] != 0)
            b = result[n - 2];
        else
            b = fibonacci(n - 2, result);

        result[n] = a + b;
        n--;
        return result[n + 1];
    }
}