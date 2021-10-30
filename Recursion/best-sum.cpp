#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>
#include <random>
#include <set>
#include <string>
#include <utility>
#include <vector>
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

struct Node *createNode(int val)
{
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->val = val;
    tmp->next = NULL;
    return tmp;
}

void displayLL(struct Node *head)
{
    std::cout << "Linked List: ";
    while (head != NULL)
    {
        std::cout << head->val << " => ";
        head = head->next;
    }
}

int getLengthLL(struct Node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

//@param targetSum: 100, gArr: 1 2 5 25
//@err Segmentation Fault in bestSumSlow

struct Node *bestSumSlow(int targetSum, std::vector<int> &gArr);
struct Node *bestSum(int targetSum, std::vector<int> &gArr, std::map<int, struct Node *> &memo);

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
    fr(i, n) std::cin >> gArr[i];
    fr(i, n) std::cout << gArr[i] << " ";
    std::cout << "\n";
    std::map<int, struct Node *> memo;
    // struct Node *head = bestSumSlow(targetSum, gArr);
    struct Node *head = bestSum(targetSum, gArr, memo);
    displayLL(head);

    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    std::cout << "\nTime: " << duration << " s.\n";
    return 0;
}

struct Node *bestSumSlow(int targetSum, std::vector<int> &gArr)
{
    if (targetSum == 0)
    {
        return createNode(0);
    }
    if (targetSum < 0)
        return NULL;

    // storing the best pathway for a particular targetSum
    struct Node *shortestCombination = NULL;

    for (int i = 0; i < gArr.size(); i++)
    {
        int remainder = targetSum - gArr[i];
        struct Node *head = bestSumSlow(remainder, gArr);
        if (head != NULL)
        {
            struct Node *newHead = createNode(gArr[i]);
            newHead->next = head;
            head = newHead;

            // now check if this LL is shorter than the shortestCombination
            if (shortestCombination == NULL || getLengthLL(head) < getLengthLL(shortestCombination))
                shortestCombination = head;
        }
    }

    return shortestCombination;
}

struct Node *bestSum(int targetSum, std::vector<int> &gArr, std::map<int, struct Node *> &memo)
{
    if (memo.find(targetSum) != memo.end())
        return memo[targetSum];
    if (targetSum == 0)
        return createNode(0);
    if (targetSum < 0)
        return NULL;

    struct Node *shortestCombination = NULL;

    for (int i = 0; i < gArr.size(); i++)
    {
        int remainder = targetSum - gArr[i];
        struct Node *head = bestSum(remainder, gArr, memo);
        if (head != NULL)
        {
            struct Node *newHead = createNode(gArr[i]);
            newHead->next = head;
            head = newHead;

            if (shortestCombination == NULL || getLengthLL(head) < getLengthLL(shortestCombination))
                shortestCombination = head;
        }
    }

    memo[targetSum] = shortestCombination;
    return shortestCombination;
}