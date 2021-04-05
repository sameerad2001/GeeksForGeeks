#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *compute(Node *head)
{
    if (head == NULL)
        return head;

    //  Reverse LL

    Node *next = head;
    Node *prev = NULL, *curr;

    while (next != NULL)
    {
        curr = next;
        next = next->next;

        curr->next = prev;

        prev = curr;
    }
    head = curr;
    prev = NULL;

    int maxElement = -1;

    while (curr != NULL)
    {
        bool wasDeleted = false;
        if (curr->data > maxElement)
            maxElement = curr->data;

        else
        {
            if (prev == NULL)
                head = curr->next;

            else
                prev->next = curr->next;

            delete curr;
            wasDeleted = true;
        }

        if (!wasDeleted)
        {
            prev = curr;
        }

        curr = curr->next;
    }

    next = head;
    prev = NULL, curr;

    while (next != NULL)
    {
        curr = next;
        next = next->next;

        curr->next = prev;

        prev = curr;
    }
    head = curr;
    prev = NULL;

    return head;
}

int main()
{
}