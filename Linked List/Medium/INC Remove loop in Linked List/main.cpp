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
    if (head == NULL || !head->next == NULL)
        return;

    Node *temp1, *temp2;

    temp1 = temp2 = head;

    // Find where both pointers meet
    while (temp2 != NULL && temp2->next->next != NULL && temp1 != temp2)
    {
        temp1 = temp1->next;

        temp2 = temp2->next->next;
    }

    // if NO LOOP return
    if (temp1 != temp2)
        return;

    // Find first Pointer in the Loop
    temp1 = head;
    while (temp1->next != temp2->next)
    {
        if (temp1 == temp2->next)
        {
            temp2->next = NULL;
            break;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    temp2->next = NULL;
}

int main()
{
}