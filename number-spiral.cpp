#include <iostream>
// #include <bits/stdc++.h>
typedef long long ll;
#define deb(x) cout << #x << " " << x << "\n";
#define fr(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int solve();

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
    ll row, col;
    cin >> row >> col;
    if (row >= col)
    {
        if (row % 2 == 0)
            cout << row * row - col + 1 << "\n";
        else
            cout << (row - 1) * (row - 1) + col << "\n";
    }
    else
    {
        if (col % 2 == 1)
            cout << col * col - row + 1 << "\n";
        else
            cout << (col - 1) * (col - 1) + row << "\n";
    }
    return 0;
}