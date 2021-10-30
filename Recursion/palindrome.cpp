// evaluating if word is a palindrome
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

bool checkPalindrome(string);
bool checkPalindrome2(string);

int main()
{
    string input;
    getline(cin, input);
    cout << checkPalindrome2(input);
    return 0;
}

bool checkPalindrome(string in)
{
    if (in.size() == 1 || in.size() == 0)
        return true;
    else
    {
        int n = in.size();
        if (checkPalindrome(in.substr(1, n - 2)) && in[0] == in[n - 1])
            return true;
        else
        {
            cout << in << "\n";
            return false;
        }
    }
}

bool checkPalindrome2(string in)
{
    int len = in.size();
    if (len == 1 || len == 0)
        return true;

    if (in[0] == in[len - 1])
        return checkPalindrome2(in.substr(1, len - 2));

    // none of the above executes, so another base-case
    return false;
}