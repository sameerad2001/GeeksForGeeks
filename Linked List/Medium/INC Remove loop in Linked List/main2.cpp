#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void removeLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node *slow, *fast;
    slow = fast = head;

    while (slow != fast && fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast != slow)
        return;

    if (slow == head)
    {
        // fast = head;
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        fast->next = NULL;
        return;
    }

    slow = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = NULL;
    return;
}

int main()
{
}