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

string toBinary(int, string);

int main()
{
    ll n = 12;
    // cin >> n;
    string result = toBinary(n, "");
    // string result = "Hello";
    // result = (char)n + result;
    cout << result;
    return 0;
}

string toBinary(int decimal, string result)
{
    if (decimal == 0)
        return result;

    result = (char)((decimal % 2) + (int)'0') + result;
    deb(decimal);
    // such a return statement at the end means when we reach the base case, there won't be any change in the result while moving up the stack.
    return toBinary(decimal / 2, result);
}