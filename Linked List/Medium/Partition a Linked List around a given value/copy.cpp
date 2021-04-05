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

struct Node *partition(struct Node *head, int x)
{
    /* Let us initialize first and last nodes of
      three linked lists
        1) Linked list of values smaller than x.
        2) Linked list of values equal to x.
        3) Linked list of values greater than x.*/
    struct Node *smallerHead = NULL, *smallerLast = NULL;
    struct Node *greaterLast = NULL, *greaterHead = NULL;
    struct Node *equalHead = NULL, *equalLast = NULL;

    // Now iterate original list and connect nodes
    // of appropriate linked lists.
    while (head != NULL)
    {
        // If current node is equal to x, append it
        // to the list of x values
        if (head->data == x)
        {
            if (equalHead == NULL)
                equalHead = equalLast = head;
            else
            {
                equalLast->next = head;
                equalLast = equalLast->next;
            }
        }

        // If current node is less than X, append
        // it to the list of smaller values
        else if (head->data < x)
        {
            if (smallerHead == NULL)
                smallerLast = smallerHead = head;
            else
            {
                smallerLast->next = head;
                smallerLast = head;
            }
        }
        else // Append to the list of greater values
        {
            if (greaterHead == NULL)
                greaterLast = greaterHead = head;
            else
            {
                greaterLast->next = head;
                greaterLast = head;
            }
        }

        head = head->next;
    }

    // Fix end of greater linked list to NULL if this
    // list has some nodes
    if (greaterLast != NULL)
        greaterLast->next = NULL;

    // Connect three lists

    // If smaller list is empty
    if (smallerHead == NULL)
    {
        if (equalHead == NULL)
            return greaterHead;
        equalLast->next = greaterHead;
        return equalHead;
    }

    // If smaller list is not empty
    // and equal list is empty
    if (equalHead == NULL)
    {
        smallerLast->next = greaterHead;
        return smallerHead;
    }

    // If both smaller and equal list
    // are non-empty
    smallerLast->next = equalHead;
    equalLast->next = greaterHead;
    return smallerHead;
}

int main()
{
}