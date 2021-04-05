#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *removeAllDuplicates(struct Node *head)
{

    Node *dum = new Node;
    dum->data = -1;
    dum->next = head;

    Node *prev, *curr;
    prev = dum;
    curr = head;

    while (curr)
    {
        while (prev->next->data == curr->next->data)
            curr = curr->next;

        // Unique
        if (prev->next == curr)
            prev = prev->next;

        // Dupe
        else
        {
            prev->next = curr->next;
        }

        curr = curr->next;
    }

    head = dum->next;

    delete dum;

    return head;
}

int main() {}