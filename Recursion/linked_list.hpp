#pragma once

#include <iostream>

struct Node
{
    int val;
    struct Node *next;
};

struct Node *createNode(int val)
{
    struct Node *tmp = (struct Node *)malloc(sizeof(struct Node));
    tmp->val = val;
    tmp->next = nullptr;
    return tmp;
}

// @return new head of the linked list
struct Node *insertHead(int val, struct Node *head)
{
    struct Node *tmp = createNode(val);
    if (val > 1e5)
    {
        std::cout << "here ";
        exit(0);
    }
    tmp->next = head;
    return tmp;
}

// @return null with LL containing new node at position pos
void insertAt(int val, struct Node *head, int pos)
{
    struct Node *tmp = head;
    for (int i = 0; i < pos; i++)
        tmp = tmp->next;
    struct Node *newNode = createNode(val);
    newNode = tmp->next;
    tmp->next = newNode;
}

void displayLL(struct Node *head)
{
    if (head == NULL)
        std::cout << "Empty List!";
    while (head != NULL)
    {
        std::cout << head->val << "->";
        head = head->next;
    }
    std::cout << "\n";
}

// @TODO
/*
class LLNode
{
public:
    int val;
    LLNode *next;
    LLNode()
    {
        next = NULL;
    }
};

class LL
{
    LLNode *head;

public:
    void insert_at_beginning(int v);
    void insert_at_end(int v);
    void insert_at_position(int v, int p);
    void delete_at_beginning();
    void delete_at_end();
    void delete_at_position(int p);
    void showLL();
};

void LL::insert_at_beginning(int val)
{
    LLNode *tmp = new LLNode();
    tmp->val = val;
    tmp->next = head;
    head = tmp;
}

class LinkedList
{
    LLNode *head;
};

template <typename T>
class DLLNode
{
private:
    T val;
    struct DLLNode *next;
    struct DLLNode *prev;

public:
    DLLNode()
    {
        this.val = (auto)NULL;
        this.next = nullptr;
        this.prev = nullptr;
    }
    DLLNode(T val, DLLNode *next, DLLNode *prev)
    {
        this.val = val;
        this.prev = prev;
        this.next = next;
    }
    T getValue()
    {
        return this.val;
    }
    void setValue(T val)
    {
        this.val = val;
    }
    DLLNode *getNext()
    {
        return this.next;
    }
    DLLNode *getPrev()
    {
        return this.prev;
    }
    void setNext(DLLNode *next)
    {
        this.next = next;
    }
    void setPrev(DLLNode *prev)
    {
        this.prev = prev;
    }
};
*/