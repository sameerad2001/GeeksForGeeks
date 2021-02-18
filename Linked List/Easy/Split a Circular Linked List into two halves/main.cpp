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

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *fast, *slow;
    slow = fast = head;

    while (fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *head1_ref = head;
    *head2_ref = slow->next;

    slow->next = head; // Split first half

    Node *temp = *head2_ref;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = *head2_ref;
}

int main()
{
}