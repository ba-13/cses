#include <iostream>
// #include <bits/stdc++.h>
typedef long long ll;
#define fr(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    ll n, tmp, result = 0;
    cin >> n;
    int gArr[n];
    fr(i, n)
    {
        cin >> gArr[i];
        if (i == 0)
            tmp = gArr[i];
        if (tmp >= gArr[i])
            result += tmp - gArr[i];
        else
            tmp = gArr[i];
    }
    cout << result;
    return 0;
}