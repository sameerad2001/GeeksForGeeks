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

Node *mergeKLists(Node *arr[], int n)
{
    Node *dum = new Node(-1);
    Node *curr = dum;
    bool is_completed = false;

    while (!is_completed)
    {
        int count = 0;
        Node *smallest = arr[0];

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == NULL)
            {
                count++;
                continue;
            }

            if (arr[i]->data < smallest->data)
            {
                smallest = arr[i];
                arr[i] = arr[i]->next;
            }
        }

        curr->next = smallest;
        curr = smallest;

        if (count >= n - 1)
        {
            is_completed = true;
        }
    }

    return dum->next;
}

int main()
{
}