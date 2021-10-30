#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <algorithm>
#include <stdlib.h>
// #include <bits/stdc++.h>
typedef long long ll;
typedef std::vector<int> vi;
const ll mod = 1000000007;
const bool debugging = true;
#define deb(x)     \
    if (debugging) \
        cout << #x << " " << x << "\n";
#define fr(i, n) for (int i = 0; i < (n); ++i)
#define pb push_back
#define endl "\n"
using namespace std;

// as a structure
typedef struct linkedList
{
    int val;
    linkedList *next;
} LL;

// as a class
class Node
{
private:
    int val;
    Node *next;

public:
    Node(int value)
    {
        val = value;
    }
    void setNext(Node *node)
    {
        next = node;
    }
    Node *getNext()
    {
        return next;
    }
    int getValue()
    {
        return val;
    }
    void printLinkedList();
};

int main()
{
    Node n1 = Node(1);
    Node n2 = Node(2);
    Node n3 = Node(3);
    Node n4 = Node(4);
    Node n5 = Node(5);
    Node n6 = Node(6);
    deb(n6.getValue());
    n1.setNext(&n2);
    n2.setNext(&n3);
    n3.setNext(&n4);
    n4.setNext(&n5);
    n5.setNext(&n6);

    n1.printLinkedList();
    return 0;
}

LL *make_node(int val)
{
    LL *tmp;
    tmp = (LL *)calloc(1, sizeof(LL));
    tmp->val = val;
    tmp->next = NULL;
}

void Node::printLinkedList()
{
    Node *tmp = next;
    while (tmp->next != NULL)
    {
        cout << tmp->val << "->";
        tmp = tmp->next;
    }
}