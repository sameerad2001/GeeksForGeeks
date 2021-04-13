#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

Node *findIntersection(Node *head1, Node *head2)
{
    Node *curr1 = head1, *curr2 = head2;
    Node *dum = new Node(-1);
    Node *curr3 = dum;

    while (curr1 != NULL && curr2 != NULL)
    {
        if (curr1->data == curr2->data)
        {
            curr3->next = curr1;
            curr3 = curr1;

            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        else if (curr1->data < curr2->data)
            curr1 = curr1->next;

        else
            curr2 = curr2->next;
    }

    curr3->next = NULL;

    return dum->next;
}

int main()
{
}