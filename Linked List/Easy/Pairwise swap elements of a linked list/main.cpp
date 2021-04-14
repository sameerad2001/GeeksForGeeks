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

} * head;

Node *pairWiseSwap(struct Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
        return head;

    Node *curr = head;
    Node *prev;

    Node *temp = curr->next;
    curr->next = temp->next;
    temp->next = curr;
    head = temp;
    prev = curr;
    curr = curr->next;

    while (curr != NULL)
    {
        temp = curr->next;

        if (temp != NULL)
        {
            curr->next = temp->next;
            temp->next = curr;
            prev->next = temp;
            prev = curr;
        }

        curr = curr->next;
    }

    return head;
}

int main()
{
}