#include <iostream>
#include <vector>
#include <string>
#include <utility>
// #include <bits/stdc++.h>
typedef long long ll;
typedef std::vector<int> vi;
const ll mod = 1000000007;
#define deb(x) cout << #x << " " << x << "\n";
#define fr(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back
#define endl "\n"
using namespace std;

void hanoi(int, int, int, int);
vector<pair<int, int>> ans;

int main()
{
    int n;
    cin >> n;
    hanoi(n, 1, 2, 3);
    cout << ans.size() << "\n";
    fr(i, ans.size())
            cout
        << ans[i].first << " " << ans[i].second << endl;
    return 0;
}

void hanoi(int n, int from_, int aux, int to_)
{
    // top-down recursion works
    if (n == 1)
    {
        ans.pb(make_pair(from_, to_));
        return; // we're done.
    }
    else
    {
        hanoi(n - 1, from_, to_, aux); // move the n-1 top disks to aux
        ans.pb(make_pair(from_, to_)); // bottom-most from from_ to to_.
        hanoi(n - 1, aux, from_, to_); // now move the n-1 disks to to
    }
}
