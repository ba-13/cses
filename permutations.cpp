#include <iostream>
// #include <bits/stdc++.h>
typedef long long ll;
#define fr(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    ll n, secondStart;
    cin >> n;
    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    if (n == 4)
    {
        cout << "2 4 1 3";
        return 0;
    }
    if (n % 2)
        secondStart = (n + 1) / 2 + 1;
    else
        secondStart = n / 2 + 1;
    fr(i, n)
    {
        if (i % 2)
            cout << secondStart + i / 2 << " ";
        else
            cout << 1 + i / 2 << " ";
    }
    return 0;
    // @l Another approach is by splitting even and odd half-half.
}