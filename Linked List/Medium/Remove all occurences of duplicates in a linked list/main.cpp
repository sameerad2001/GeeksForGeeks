#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *removeAllDuplicates(struct Node *head)
{

    Node *curr = head;
    Node *prev;

    while (curr)
    {
        prev = curr;

        curr = curr->next;

        int count = 0;
        while (curr->data == curr->next->data)
        {
            curr = curr->next;
            count++;
        }

        if (count != 0)
        {
            if (prev == head)
                head = curr->next;

            else
                prev->next = curr->next;

            curr = curr->next;
        }
    }

    return head;
}

int main()
{
}