#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
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

struct Node
{
    int val;
    struct Node *next;
};

struct Node *howSum(int targetSum, std::vector<int> &gArr, std::map<int, struct Node *> &memo);

ll fib(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    std::mt19937 mt(69);
    std::uniform_int_distribution<int> dist(10, 1000);
    clock_t start;
    double duration;
    start = clock();
    fastio;

    int targetSum;
    std::cin >> targetSum;
    int n;
    std::cin >> n;
    std::vector<int> gArr(n);
    // fr(i, n) gArr[i] = dist(mt);
    fr(i, n) std::cin >> gArr[i];
    // sort(all(gArr));
    fr(i, n) std::cout << gArr[i] << " ";

    std::cout << "\n";
    std::map<int, struct Node *> memo;

    struct Node *head = howSum(targetSum, gArr, memo);
    while (head != NULL)
    {
        std::cout << head->val << " => ";
        head = head->next;
    }
    // fib(40); // only to increase time taken

    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << std::setprecision(5);
    std::cout << "\nTime: " << duration << " s.\n";
    free(head);
    return 0;
}

struct Node *howSum(int targetSum, std::vector<int> &gArr, std::map<int, struct Node *> &memo)
{
    if (memo.find(targetSum) != memo.end())
        return memo[targetSum];
    if (targetSum == 0)
    {
        struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
        tmp->val = 0;
        tmp->next = NULL;
        return tmp;
    };
    if (targetSum < 0)
        return NULL;
    for (int i = 0; i < gArr.size(); i++)
    {
        int tmp = targetSum - gArr[i];
        struct Node *head = howSum(tmp, gArr, memo);
        if (head != NULL)
        {
            struct Node *tmpNode = (struct Node *)malloc(sizeof(struct Node));
            tmpNode->val = gArr[i];
            tmpNode->next = head;
            head = tmpNode;
            memo[targetSum] = head;
            return head;
        }
    }
    memo[targetSum] = NULL;
    return NULL;
}