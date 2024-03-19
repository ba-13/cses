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

char *permute(int, char *);
ll factorial(int i)
{
    if (i == 1)
        return 1;
    return i * factorial(i - 1);
}

int main()
{
    string gStr;
    int count[26] = {0};
    getline(cin, gStr);
    int nr = 0;
    int n = gStr.size();
    fr(i, n)
    {
        int tmp = (int)gStr[i] - (int)'a';
        count[tmp]++;
    }
    ll fact = factorial(n);
    // count contains the number of time each character is repeated
    fr(i, 26)
    {
        if (count[i] != 0)
        {
            fact /= factorial(count[i]);
        }
    }
    char str[n];
    int counterOfStr = 0;
    fr(i, 26)
    {
        while (count[i]--)
        {
            str[counterOfStr] = (char)(i + (int)'a');
            counterOfStr++;
        }
    }
    // now we have an arranged string in form of array
    // permute(n, str);
    std::cout << fact << "\n";
    do
    {
        fr(i, n)
                std::cout
            << str[i];
        std::cout << "\n";
    } while (std::next_permutation(str, str + n));
    return 0;
}
