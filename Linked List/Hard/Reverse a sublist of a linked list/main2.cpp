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
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
        return head;

    if (m >= n)
        return head;

    //  Create Dummy ~ Prev Node
    Node *dum = new Node(-1);
    dum->next = head;
    Node *prev = dum;

    // Find Previous of the start  Node of the sublist
    for (int i = 1; i < m; i++)
    {
        prev = prev->next;
    }

    Node *curr = prev->next;
    Node *next;

    //        Reverse
    //         c    n
    // prev -> 1 -> 2 -> 3 -> NULL
    for (int i = 0; i < n - m; i++)
    {
        next = curr->next;
        curr->next = next->next; // prev -> 1 -> 3 -> NULL  |  2 -> 3 -> NULL
        next->next = prev->next; // prev -> 1 -> 3 -> NULL  |  2 -> 1 -> 3 -> NULL
        prev->next = next;       // prev -> 2 -> 1 -> 3 -> NULL

        // curr = curr->next; // Apparently Not needed
    }

    return dum->next;
}

int main()
{
}