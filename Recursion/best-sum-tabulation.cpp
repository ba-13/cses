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
    vi numArray;
    while (std::cin >> tmp && tmp != -1)
        numArray.push_back(tmp);
    show(numArray);
    /**
     * shortest path for x may not be the shortest path to y, y > x
     * For best sum, one needs to store all paths that leads to the particular target, as a vector of pointers to LLs
     * Each pointer of LLs now holds a possibility to create another route for upper targets, so need to iterate over them as well
     */
    // std::vector<std::vector<struct Node *>> result(targetSum + 1, std::vector<struct Node *>(1, NULL));
    std::vector<struct Node *> result(targetSum + 1, NULL);
    // std::vector<struct Node *> tmpMethods;
    // tmpMethods.push_back(createNode(0));
    // result[0] = tmpMethods;
    result[0] = createNode(0);
    fr(i, targetSum)
    {
        // if (result[i].size() <= 0)
        //     continue;
        if (result[i] == NULL)
            continue;
        fr(j, numArray.size())
        {
            if (numArray[j] + i > targetSum)
                continue;
            /*
            ! For all methods logic:
            // now push_back to target + numArray[j], for all paths in current target
            fr(k, result[i].size())
            {
                // std::cout << "Entered here with " << i << " " << numArray[j] << "\n";
                struct Node *newHead = NULL, *curr = result[i][k];
                while (curr != NULL)
                {
                    newHead = insertHead(curr->val, newHead);
                    curr = curr->next;
                }
                newHead = insertHead(numArray[j], newHead);
                result[i + numArray[j]].push_back(newHead);
            }
            */
            struct Node *maybeNewHead = NULL, *curr = result[i], *currOld = result[i + numArray[j]];
            int countNew = 0, countOld = 0;
            while (currOld != NULL)
            {
                currOld = currOld->next;
                countOld++;
            }
            while (curr != NULL)
            {
                maybeNewHead = insertHead(curr->val, maybeNewHead);
                curr = curr->next;
                countNew++;
            }
            maybeNewHead = insertHead(numArray[j], maybeNewHead);
            if (countOld == 0)
                result[i + numArray[j]] = maybeNewHead;
            else if (countOld > countNew)
            {
                result[i + numArray[j]] = maybeNewHead;
            }
        }
    }

    fr(i, result.size())
    {
        std::cout << i << " : \n";
        // fr(j, result[i].size())
        //     displayLL(result[i][j]);
        displayLL(result[i]);
        std::cout << "\n";
    }

    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "\nTime: " << duration << " s.\n";
    return 0;
}