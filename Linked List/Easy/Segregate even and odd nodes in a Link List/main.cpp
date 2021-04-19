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

} * head;

Node *divide(int N, Node *head)
{
    if (head == NULL)
        return NULL;

    Node *curr = head;

    Node *even_head = NULL, *odd_head = NULL;
    Node *even_end = NULL, *odd_end = NULL;

    while (curr != NULL)
    {
        if (curr->data % 2 == 0)
        {
            if (even_head == NULL)
            {
                even_end = even_head = curr;
            }
            else
            {
                even_end->next = curr;
                even_end = curr;
            }
        }
        else
        {
            if (odd_head == NULL)
            {
                odd_end = odd_head = curr;
            }
            else
            {
                odd_end->next = curr;
                odd_end = curr;
            }
        }

        curr = curr->next;
    }

    if (odd_end != NULL)
        odd_end->next = NULL;

    if (even_head == NULL)
        return odd_head;

    even_end->next = odd_head;

    return even_head;
}

int main()
{
}