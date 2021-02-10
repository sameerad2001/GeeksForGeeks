#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *reverseList(Node *head)
{
    Node *curr, *next, *prev;
    curr = prev = NULL;
    next = head;

    while (next != NULL)
    {
        curr = next;
        next = next->next;
        curr->next = prev;
        prev = curr;
    }

    head = curr;

    return head;
}

int main()
{
}