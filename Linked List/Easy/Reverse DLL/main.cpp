#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *reverseDLL(Node *head)
{
    Node *curr = head;

    while (curr)
    {
        Node *temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;

        curr = curr->prev;

        if (curr && curr->next == NULL)
            head = curr;
    }

    return head;
}

int main()
{
}