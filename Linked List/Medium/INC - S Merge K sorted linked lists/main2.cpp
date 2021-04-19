#include <iostream>
#include <algorithm>

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

Node *mergeKLists(Node *arr[], int K)
{
    int index = 0;
    int count = 0;

    for (int i = 0; i < K; i++)
    {
        Node *curr = arr[i];
        while (curr != NULL)
        {
            curr = curr->next;
            count++;
        }
    }

    Node *head;
    int *array = new int[count];
    // int array[count];

    int j = 0;
    for (int i = 0; i < K; i++)
    {
        Node *curr = head;
        while (curr != NULL)
        {
            array[j++] = curr->data;
            curr = curr->next;
        }
    }

    sort(array, array + count);

    Node *head = new Node(array[0]);
    Node *curr = head;
    for (int j = 1; j < count; j++)
    {
        curr->next = new Node(array[j]);
        curr = curr->next;
    }

    return head;
}

int main()
{
}