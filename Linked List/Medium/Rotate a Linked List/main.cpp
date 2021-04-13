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

Node *rotate(Node *head, int k)
{
    Node *last = head;
    while (last->next != NULL)
        last = last->next;

    while (k--)
    {
        Node *temp = head;
        head = head->next;
        last->next = temp;
        temp->next = NULL;
        last = temp;
    }

    return head;
}

int main()
{
}