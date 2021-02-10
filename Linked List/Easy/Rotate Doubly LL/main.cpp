#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next, *prev;

    node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

struct node *update(struct node *start, int p)
{
    node *temp;
    node *last = start;

    while (last->next)
    {
        last = last->next;
    }

    while (p--)
    {
        temp = start;

        start = start->next;

        last->next = temp;
        last = temp;
        temp->prev = last;
        temp->next = NULL;
    }

    return start;
}

int main()
{
}