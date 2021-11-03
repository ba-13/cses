#include <iostream>
#include <set>
#include <cstdio>
#include <vector>
// #include <bits/stdc++.h>
typedef long long ll;
const ll mod = 1000000007;
#define deb(x) cout << #x << " " << x << "\n";
#define fr(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    multiset<char> gSet;
    vector<char> output(n);
    multiset<char>::iterator itr;
    for (int i = 0; i < n; i++)
    {
        gSet.insert(s[i]);
    }
    int evenOrder = 0, moveOn = 0, foundOne = 0;
    int ptr = 0;   // For pointing to the current location to be filled in an array
    char ch = '1'; // initiation
    for (itr = gSet.begin(); itr != gSet.end(); itr++)
    {
        if (evenOrder)
        {
            if (ch != *itr && !foundOne)
            {
                // TODO: when n % 2 is 1, and there is one space for an odd numbered letter.
                foundOne = 1;
                itr--; // moving one step back to the last inserted odd numbered letter.
                output[n / 2 + 1 - 1] = *itr;
                evenOrder = 0;
                moveOn = 1;
                // ptr++ isn't performed
                // cause this step's original character will now be inserted by nonEvenOrder
                continue;
            }
            else if (ch != *itr && foundOne)
            {
                cout << "NO SOLUTION\n";
                return 0;
            }
            output[n - ptr - 1] = *itr;
            ptr++;
            evenOrder = 0;
            moveOn = 1;
        }
        else
        {
            output[ptr] = *itr;
            moveOn = 0;
            evenOrder = 1; // Now time to insert to the end.
            ch = *itr;     // the character to be inserted to the end.
        }
    }
    for (int i = 0; i < n / 2 + 1; i++)
    {
        if (output[i] != output[n - i - 1])
        {
            cout << "NO SOLUTION\n";
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << output[i];
    }
    return 0;
}

/**
        cout << *itr << "\n";
        int num = gSet.count(*itr);
        if (ch == *itr)
            continue;
        ch = *itr;
        if (num % 2 && foundOne)
        {
            cout << "NO SOLUTION"
                 << "\n";
            return 0;
        }
        else if (num % 2)
        {
            foundOne = 1;
            if (n % 2 == 0)
            {
                cout << "NO SOLUTION"
                     << "\n";
                return 0; // No midpt exists
            }
            // else midpt exists and put the character right there
            output[(n / 2 + 1) - 1] = ch;
            num--;
        }
        // Now you only have even cases:
        // which has to filled 0 -> n/2 - 1
        num = n / 2; // fill this much characters from ptr
        while (num--)
        {
            output[ptr] = ch;
            output[n - ptr - 1] = ch;
            ptr++;
        }
    */