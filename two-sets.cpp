#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
typedef long long ll;
#define deb(x) cout << #x << " " << x << "\n";
#define fr(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum % 2 != 0)
    {
        cout << "NO";
        return 0;
    }

    // Base case 3, 4 satisfy the condition. Only += 4 will do the same.
    cout << "YES"
         << "\n";
    vector<int> a, b;
    if (n % 4 == 3)
    {
        int r = 3;
        a.push_back(1);
        a.push_back(2);
        b.push_back(3);

        while (r != n)
        {
            a.push_back(r + 2);
            a.push_back(r + 3);
            b.push_back(r + 1);
            b.push_back(r + 4);
            r += 4;
        }
    }
    else if (n % 4 == 0)
    {
        int r = 4;
        a.push_back(1);
        a.push_back(4);
        b.push_back(2);
        b.push_back(3);
        while (r != n)
        {
            a.push_back(r + 2);
            a.push_back(r + 3);
            b.push_back(r + 1);
            b.push_back(r + 4);
            r += 4;
        }
    }
    cout << a.size() << "\n";
    for (unsigned int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n"
         << b.size() << "\n";
    for (unsigned int i = 0; i < b.size(); i++)
        cout << b[i] << " ";
    return 0;
}