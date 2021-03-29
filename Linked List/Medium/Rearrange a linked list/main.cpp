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

Node *rearrangeEvenOdd(Node *head)
{
    if (!head || !head->next)
        return NULL;

    Node *odd = head;
    Node *even, *evenFirst;

    even = evenFirst = head->next;

    while (even && odd && odd->next)
    {
        odd->next = even->next;
        odd = even;
        even->next = odd->next;
        even = odd->next;
    }

    if (even)
        even->next = NULL;

    odd->next = evenFirst;

    return head;
}

int main()
{
}