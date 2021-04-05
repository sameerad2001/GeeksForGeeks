#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *arb;

    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

Node *copyList(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        Node *temp = new Node(curr->data);
        temp->next = curr->next;
        curr->next = temp;
        curr = curr->next->next;
    }
    curr = head;
    while (curr)
    {
        if (curr->arb)
            curr->next->arb = curr->arb->next;
        curr = curr->next->next;
    }
    curr = head;
    Node *head2 = curr->next;
    while (curr)
    {
        Node *temp = curr->next->next;
        if (curr->next->next)
            curr->next->next = temp->next;
        curr->next = temp;
        curr = temp;
    }
    return head2;
}