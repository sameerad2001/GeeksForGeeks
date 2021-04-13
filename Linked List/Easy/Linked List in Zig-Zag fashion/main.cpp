#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *zigZag(Node *head)
{
    Node *curr = head;

    bool great = false;
    while (curr != NULL)
    {
        if (great)
        {
            if (curr->next != NULL && curr->data < curr->next->data)
            {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
            }
        }
        else
        {
            if (curr->next != NULL && curr->data > curr->next->data)
            {
                int temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
            }
        }

        great = !great;
        curr = curr->next;
    }

    return head;
}

int main()
{
}