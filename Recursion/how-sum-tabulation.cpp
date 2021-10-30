#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include "linked_list.hpp"
// #include <bits/stdc++.h>

using std::clock;
typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> ii;
typedef std::vector<int> vi;

const ll mod = 1000000007;
const bool debugging = true;

// non-categorized
#define fastio                    \
    std::ios::sync_with_stdio(0); \
    std::cin.tie(0);              \
    std::cout.tie(0);             \
    std::cin.exceptions(std::cin.failbit);

// shortening frequent phrases
#define pb push_back
#define mp make_pair

// shortening frequent expression
#define sz(a) int((a).size()) // converting from uint to int
#define all(x) x.begin(), x.end()
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all(c), x) != c.end())

// iteration shorthands
#define fr(i, n) for (int i = 0; i < n; i++)
#define tr(c, i) for (typeof c.begin() i = c.begin(); i != c.end(); i++)

// debugging macros
#define deb(x)     \
    if (debugging) \
        std::cout << #x << " : " << x << "\n";
#define deb2(x, y) \
    if (debugging) \
        std::cout << #x << " " << x << " :: " << #y << " " << y << "\n";
// typeof isn't defined everywhere, convert it manually
#define show(c)                                                 \
    if (debugging)                                              \
    {                                                           \
        std::cout << #c << " : ";                               \
        for (typeof c.begin() i = c.begin(); i != c.end(); i++) \
            std::cout << *i << " ";                             \
        std::cout << "\n";                                      \
    }

int main()
{
    std::mt19937 mt(69);
    std::uniform_int_distribution<int> dist(10, 1000);
    clock_t start;
    double duration;
    start = clock();
    fastio;

    int targetSum, tmp;
    std::cin >> targetSum;
    vi numArr;
    while (std::cin >> tmp && tmp != -1)
        numArr.push_back(tmp);
    show(numArr);
    std::vector<struct Node *> result(targetSum + 1, NULL);
    result[0] = createNode(0);

    fr(i, targetSum)
    {
        if (result[i] == NULL)
            continue;
        fr(j, numArr.size())
        {
            if (numArr[j] + i < targetSum + 1)
            {
                // now insert a LL if result[numArr[j] + i] is null
                // else insert a new LL by overwriting the existing LL
                // so we always have to dump the current filled

                if (result[numArr[j] + i] != NULL)
                    free(result[numArr[j] + i]);

                // now attach the current's LL with extra head, to result[numArr[j] + i], note that you have to create a new Copy of the LL before doing the same
                // You got an error here, by not declaring newHead as NULL, so encountered segmentation fault.
                // @l Always initialise a variable
                struct Node *newHead = NULL, *curr = NULL;
                curr = result[i]; // just used to traverse the existing LL
                while (curr != NULL)
                {
                    newHead = insertHead(curr->val, newHead);
                    curr = curr->next;
                }
                newHead = insertHead(numArr[j], newHead);
                result[numArr[j] + i] = newHead;
            }
        }
    }

    fr(i, result.size())
    {
        std::cout << i << " : ";
        displayLL(result[i]);
    }

    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "\nTime: " << duration << " s.\n";
    return 0;
}

/*
19
7 5 12 4 9 -1
*/