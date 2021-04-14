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

int getNthFromLast(Node *head, int n)
{
    if (head == NULL)
        return -1;

    int count = 0;
    Node *curr = head;
    while (curr != NULL)
    {
        curr = curr->next;
        count++;
    }

    if (n > count)
        return -1;

    int i = 0;
    curr = head;
    while (i != count - n - 1)
    {
        curr = curr->next;
        i++;
    }

    return curr->data;
}

int main()
{
}