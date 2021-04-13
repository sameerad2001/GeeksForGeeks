#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Node *mergeResult(Node *head1, Node *head2)
{
    Node *curr = NULL;
    while (head1 && head2)
    {
        if (head1->data < head2->data)
        {
            Node *temp = head1;
            head1 = head1->next;
            temp->next = curr;
            curr = temp;
        }
        else
        {
            Node *temp = head2;
            head2 = head2->next;
            temp->next = curr;
            curr = temp;
        }
    }
    while (head1 != NULL)
    {
        Node *temp = head1;
        head1 = head1->next;
        temp->next = curr;
        curr = temp;
    }

    while (head2 != NULL)
    {
        Node *temp = head2;
        head2 = head2->next;
        temp->next = curr;
        curr = temp;
    }

    return curr;
}

int main() {}