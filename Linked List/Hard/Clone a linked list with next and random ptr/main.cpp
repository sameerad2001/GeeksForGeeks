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
    Node *next;

    while (curr)
    {
        next = curr->next;

        Node *temp = new Node(curr->data);
        temp->next = next;
        curr->next = temp;

        curr = next;
    }

    curr = head;

    while (curr)
    {
        if (curr->arb)
            curr->next->arb = curr->arb->next;
        else
            curr->next->arb = NULL;

        curr = curr->next ? curr->next->next : curr->next;
    }

    curr = head;
    Node *copy = head->next;

    Node *newHead = copy;

    // while (curr->next->next)
    // {
    //     curr = curr->next->next;
    //     copy->next = curr->next;

    //     copy = copy->next;
    // }

    while (copy && curr)
    {
        curr->next = curr->next->next ? curr->next->next : curr->next;

        copy->next = copy->next ? copy->next->next : copy->next;

        curr = curr->next;
        copy = copy->next;
    }
    head = newHead;
    return head;
}

int main()
{
}