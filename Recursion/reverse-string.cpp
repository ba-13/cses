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

string reverseString(string);

int main()
{
    string input;
    getline(cin, input);
    cout << reverseString(input);
    return 0;
}

string reverseString(string input)
{
    if (input == "")
        return "";
    else
        // This is literally so beautiful.
        return reverseString(input.substr(1)) + input[0];
}
