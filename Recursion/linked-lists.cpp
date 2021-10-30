#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <set>
#include <utility>

// #include <bits/stdc++.h>
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
#define debc(x, c) \
    if (debugging) \
        std::cout << #x << " : " << x << c;
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

struct Node *newNode(int val, struct Node *head)
{
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->val = val;
    tmp->next = head;
    head = tmp;
    return head;
}

void showNodes(struct Node *head)
{
    if (head == NULL)
        return;
    while (head != NULL)
    {
        std::cout << head->val << "->";
        head = head->next;
    }
}

int main()
{
    fastio;
    int tmp;
    struct Node *head = NULL;
    while (std::cin >> tmp && tmp != -1)
    {
        head = newNode(tmp, head);
    }
    showNodes(head);
    return 0;
}

/**
 * There are 2 ways to grow a linked list
 * head->append1->append2->append3... (go through the whole list to append at the end)
 * oldHead4<-oldHead3<-oldHead2<-oldHead<-head<-NULL
 */