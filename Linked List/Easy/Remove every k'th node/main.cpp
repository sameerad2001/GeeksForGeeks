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

Node *deleteK(Node *head, int K)
{
    int count = 1;

    if (head == NULL)
        return NULL;

    if (K == 0)
        return head;

    if (K == 1)
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        return NULL;
    }

    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {

        if ((count) % K == 0)
        {
            Node *temp = curr;
            if (prev != NULL)
                prev->next = curr->next;
            curr = curr->next;
            delete temp;

            ++count;
            continue;
        }

        ++count;
        prev = curr;
        curr = curr->next;
    }

    return head;
}

int main()
{
}