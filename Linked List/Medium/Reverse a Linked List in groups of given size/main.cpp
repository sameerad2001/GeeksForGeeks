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

// WRONG
struct node *reverse(struct node *head, int k)
{
    int count = 1;
    node *curr_head = head, *prev_end = NULL;
    node *curr = head;

    while (curr != NULL)
    {
        if (count == k)
        {
            node *current = NULL, *next = curr_head, *prev = NULL;

            while (next != curr->next)
            {
                prev = current;
                current = next;
                next = next->next;

                current->next = prev;
            }

            count = 1;

            if (prev_end != NULL)
                prev_end->next = curr;

            else
                head = current;

            prev_end = current;
            curr_head = curr->next;
        }

        count++;
        curr = curr->next;
    }

    return head;
}

int main()
{
}