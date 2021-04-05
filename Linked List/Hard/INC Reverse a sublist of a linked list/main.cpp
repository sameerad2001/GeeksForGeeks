#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *reverseBetween(Node *head, int m, int n)
{
    int count = 0;

    Node *curr = head;
    while (count != m - 1)
    {
        curr = curr->next;
        count++;
    }
    Node *start = curr;

    while (count != n + 1)
    {
        curr = curr->next;
        count++;
    }
    Node *end = curr;

    Node *prev = NULL, *next = start->next;
    curr = NULL;

    Node *temp = start->next;

    while (next != end)
    {
        prev = curr;
        curr = next;
        next = next->next;

        curr->next = prev;
    }
    temp->next = end;
    start->next = curr;

    return head;
}

int main()
{
}