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

void deleteNode(Node *node)
{
    Node *temp = node->next;

    node->data = node->next->data;
    node->next = node->next->next;
    // *(node) = *(node->next)

    delete temp;
}

int main()
{
}