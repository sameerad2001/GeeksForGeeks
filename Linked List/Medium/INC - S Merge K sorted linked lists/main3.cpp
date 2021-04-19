#include <iostream>

using namespace std;
#include <algorithm>

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

Node *merge(Node *arr[], int start, int end)
{
    if (start == end)
        return arr[start];

    Node *head1 = merge(arr, start, start + (end - start) / 2);
    Node *head2 = merge(arr, start + (end - start) / 2 + 1, end);
    Node *head = NULL;

    if (head2 == NULL)
        return head1;

    Node *curr = head;

    while (head1 != NULL || head2 != NULL)
    {
        if (head1 == NULL)
        {
            curr->next = head2;
            while (head2->next != NULL)
                head2 = head2->next;
            curr = head2;
            head2 = head2->next;
        }
        if (head2 == NULL)
        {
            curr->next = head1;
            while (head1->next != NULL)
                head1 = head1->next;
            curr = head1;
            head1 = head1->next;
        }

        if (head1->data < head2->data)
        {
            curr->next = head1;
            head1 = head1->next;
        }
        else
        {
            curr->next = head2;
            head2 = head1->next;
        }
        curr = curr->next;
    }

    return head;
}

Node *mergeKLists(Node *arr[], int K)
{
    if (K == 0)
        return NULL;

    if (K == 1)
        return arr[0];

    Node *head, *head1, *head2;

    head1 = merge(arr, 0, K / 2);
    head2 = merge(arr, K / 2 + 1, K - 1);

    if (head2 == NULL)
        return head1;

    Node *curr = head;

    while (head1 != NULL || head2 != NULL)
    {
        if (head1 == NULL)
        {
            curr->next = head2;
            while (head2->next != NULL)
                head2 = head2->next;
            curr = head2;
            head2 = head2->next;
        }
        if (head2 == NULL)
        {
            curr->next = head1;
            while (head1->next != NULL)
                head1 = head1->next;
            curr = head1;
            head1 = head1->next;
        }

        if (head1->data < head2->data)
        {
            curr->next = head1;
            head1 = head1->next;
        }
        else
        {
            curr->next = head2;
            head2 = head1->next;
        }
        curr = curr->next;
    }

    return head;
}

int main()
{
}