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

Node *deleteNode(Node *head, int pos)
{
    int count = 1; // indexing from 1 onwards
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {

        if (count == pos)
        {
            // Node *temp;
            if (prev == NULL)
            {
                head = head->next;
                delete curr;
                break;
            }
            else
            {
                prev->next = curr->next;
                delete curr;
                break;
            }
        }

        prev = curr;
        curr = curr->next;
        count++;
    }

    return head;
}

int main()
{
}