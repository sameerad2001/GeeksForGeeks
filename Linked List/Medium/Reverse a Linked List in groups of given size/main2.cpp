#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }

} * head;

struct node *reverse(struct node *head, int k)
{
    node *prev = NULL;
    node *curr = head, *next;

    int count = 1;
    while (curr != NULL && count != k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL)
        head->next = reverse(next, k);

    return prev;
}

int main()
{
}