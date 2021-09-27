#include <iostream>
#include <string>
// #include <bits/stdc++.h>
typedef long long ll;
#define fr(i, n) \
    for (ll i = 0; i < (n); ++i)
using namespace std;

int main()
{
    string gDna;
    cin >> gDna;
    ll maxYet = 0, currMax = 0;
    char curr = gDna[0], maxChar = 'a';
    fr(i, gDna.length())
    {
        if (gDna[i] == curr && i != gDna.length() - 1)
        {
            currMax++;
        }
        else
        {
            if (i == gDna.length() - 1)
            {
                if (curr == gDna[i])
                    currMax++;
                // cout << "Reached the end with " << curr << " " << currMax << "\n";
            }
            if (currMax > maxYet)
            {
                // cout << curr << " " << currMax << "\n";
                maxYet = currMax;
                maxChar = curr;
            }
            curr = gDna[i];
            currMax = 1;
        }
    }
    cout << maxYet;
    return 0;
}