#include <iostream>
#include <vector>

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

int countNodes(Node *head)
{
    int count = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void reorderList(Node *head)
{
    // vector<Node *> vec;
    int n = countNodes(head);
    int *array = (int *)malloc(sizeof(int));

    Node *curr = head;

    int index = 0;
    while (curr != NULL)
    {
        // vec.push_back(curr);
        array[index++] = curr->data;

        curr = curr->next;
    }

    curr = head;
    curr->data = array[0];
    curr = curr->next;

    for (int i = 1; i < n / 2; i++)
    {
        curr->data = array[i];
        curr = curr->next;
        curr->data = array[n - 1 - i];
        curr = curr->next;
    }

    curr->next = NULL;
    delete[] array;
}

int main()
{
}