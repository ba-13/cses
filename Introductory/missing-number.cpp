#include <iostream>
// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll sum = 0, tmp;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> tmp;
        sum += tmp;
    }
    cout << (n * (n + 1) / 2) - sum;
    return 0;
}
