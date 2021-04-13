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

// W R O N G
// remove nth node NOT node with data = n

Node *deleteNode(Node *head, int key)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {

        if (key == curr->data)
        {
            Node *temp;
            if (prev == NULL)
            {
                temp = curr;
                head = head->next;
                delete temp;
                break;
            }
            else
            {
                temp = curr;
                prev->next = curr->next;
                delete temp;
                break;
            }
        }

        prev = curr;
        curr = curr->next;
    }

    return head;
}

int main()
{
}