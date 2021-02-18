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

Node *deleteMid(Node *head)
{
    Node *slow = head, *prevSlow, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        prevSlow = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prevSlow->next = slow->next;
    delete slow;

    return head;
}

int main()
{
}