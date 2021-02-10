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

int count(struct node *head, int search_for)
{

    node *temp = head;
    int count = 0;

    while (temp)
    {
        if (temp->data == search_for)
            count++;

        temp = temp->next;
    }

    return count;
}

int main()
{
}