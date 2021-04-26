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

Node *inPlace(Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
        return head;

    Node *slow, *fast;
    slow = fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *head1 = head;
    Node *head2 = slow->next;
    slow->next = NULL;

    Node *prev = NULL, *curr, *next = head2;

    while (next != NULL)
    {
        curr = next;
        next = next->next;

        curr->next = prev;

        prev = curr;
    }
    head2 = curr;

    head = head1;
    head1 = head1->next;
    curr = head;

    int count = 1;
    while (head1 != NULL && head2 != NULL)
    {
        if (count == 0)
        {
            curr->next = head1;
            head1 = head1->next;
            count++;
        }
        else
        {
            curr->next = head2;
            head2 = head2->next;
            count--;
        }
        curr = curr->next;
    }
    if (head1 == NULL)
        curr->next = head2;

    if (head2 == NULL)
        curr->next = head1;

    return head;
}

int main()
{
}