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

void reorderList(Node *head)
{

    if (head == NULL || head->next == NULL)
        return;

    Node *slow, *fast;
    slow = fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *head1, *head2;
    head1 = head;
    head2 = slow->next;
    slow->next = NULL;

    Node *curr, *prev = NULL, *next = head2;
    while (next != NULL)
    {
        curr = next;
        next = next->next;
        curr->next = prev;
        prev = next;
    }
    head2 = curr;

    head = head1;
    curr = head;
    head1 = head1->next;

    bool alternate = false;
    while (head1 != NULL && head2 != NULL)
    {
        if (alternate)
        {
            curr->next = head1;
            head1 = head1->next;
            alternate = false;
        }
        else
        {
            curr->next = head2;
            head2 = head2->next;
            alternate = true;
        }
        curr = curr->next;
    }

    if (head1 != NULL)
    {
        curr->next = head1;
    }
    if (head2 != NULL)
    {
        curr->next = head2;
    }

    // return head;
}

int main()
{
}