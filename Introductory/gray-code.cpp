#include <iostream>
#include <vector>
#include <string>
// #include <bits/stdc++.h>
typedef long long ll;
typedef std::vector<int> vi;
const ll mod = 1000000007;
#define deb(x) cout << #x << " " << x << "\n";
#define fr(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back
using namespace std;

// This is a referred solution, not mine.

vector<string> generate(int);

int main()
{
    int n;
    cin >> n;
    vector<string> ans = generate(n);
    fr(i, ans.size())
            cout
        << ans[i] << "\n";
    return 0;
}

vector<string> generate(int n)
{
    if (n <= 0)
        return {"0"};
    else if (n == 1)
        return {"0", "1"};
    vector<string> tmp = generate(n - 1); // asked your subproblem his answer
    vector<string> mainAns;

    for (int i = 0; i < tmp.size(); i++)
    {
        string s = tmp[i];
        mainAns.pb("0" + s);
    }
    for (int i = tmp.size() - 1; i >= 0; i--)
    {
        string s = tmp[i];
        mainAns.pb("1" + s);
    }

    return mainAns;
}