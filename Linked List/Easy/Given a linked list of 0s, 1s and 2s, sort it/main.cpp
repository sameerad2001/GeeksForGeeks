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

Node *segregate(Node *head)
{
    Node *one_head = NULL, *two_head = NULL, *zero_head = NULL;
    Node *one_curr = NULL, *two_curr = NULL, *zero_curr = NULL;

    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            if (zero_head == NULL)
            {
                zero_head = zero_curr = curr;
            }
            else
            {
                zero_curr->next = curr;
                zero_curr = curr;
            }
        }

        if (curr->data == 1)
        {
            if (one_head == NULL)
            {
                one_head = one_curr = curr;
            }
            else
            {
                one_curr->next = curr;
                one_curr = curr;
            }
        }

        if (curr->data == 2)
        {
            if (two_head == NULL)
            {
                two_head = two_curr = curr;
            }
            else
            {
                two_curr->next = curr;
                two_curr = curr;
            }
        }

        curr = curr->next;
    }

    if (two_curr != NULL)
        two_curr->next = NULL;

    if (zero_curr == NULL)
    {
        if (one_curr == NULL)
            return two_head;
        else
        {
            one_curr->next = two_head;
            return one_head;
        }
    }

    if (one_curr == NULL)
    {
        zero_curr->next = two_head;
        return zero_head;
    }

    zero_curr->next = one_head;
    one_curr->next = two_head;

    return zero_head;
}

int main() {}