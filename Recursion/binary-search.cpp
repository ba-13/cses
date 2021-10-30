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

int binarySearch(vi, int, int, int);

int main()
{
    // Enter till -1
    vi in;
    int tmp;
    cin >> tmp;
    while (tmp != -1)
    {
        in.pb(tmp);
        cin >> tmp;
    }
    sort(in.begin(), in.end());
    fr(i, in.size())
            cout
        << in[i] << " ";

    int find;
    cin >> find;
    cout << "\n"
         << binarySearch(in, 0, in.size() - 1, find);
    return 0;
}

int binarySearch(vi in, int left, int right, int find)
{
    if (left > right)
        return -1;
    int mid = (left + right) / 2;
    if (find == in[mid])
        return mid;
    else if (find > in[mid])
        return binarySearch(in, mid + 1, right, find);
    else
        return binarySearch(in, left, mid - 1, find);
}