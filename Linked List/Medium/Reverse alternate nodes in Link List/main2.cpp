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

void rearrange(struct Node *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return;

    Node *oddHead = head;
    Node *evenHead = head->next;

    Node *odd_curr = oddHead;
    Node *even_curr = evenHead;

    while (even_curr != NULL && odd_curr != NULL)
    {
        odd_curr->next = odd_curr->next->next;
        even_curr->next = even_curr->next->next;

        even_curr = even_curr->next;
        odd_curr = odd_curr->next;
    }

    Node *prev = NULL;
    Node *curr = NULL;
    Node *next = evenHead;

    while (next != NULL)
    {
        prev = curr;
        curr = next;
        next = next->next;

        curr->next = prev;
    }

    evenHead = curr;

    odd_curr->next = evenHead;
}

int main()
{
}