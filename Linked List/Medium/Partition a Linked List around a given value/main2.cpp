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
    Node *smallHead, *smallLast;
    Node *equalHead, *equalLast;
    Node *bigHead, *bigLast;

    smallHead = equalHead = bigHead = NULL;
    smallLast = equalLast = bigHead = NULL;

    while (head != NULL)
    {
        if (head->data < x)
        {
            if (smallHead == NULL)
                smallHead = smallLast = head;
            else
            {
                smallLast->next = head;
                smallLast = head;
            }
        }

        else if (head->data == x)
        {
            if (equalHead == NULL)
                equalHead = equalLast = head;
            else
            {
                equalLast->next = head;
                equalLast = head;
            }
        }

        else
        {
            if (bigHead == NULL)
                bigHead = bigLast = head;
            else
            {
                bigLast->next = head;
                bigLast = head;
            }
        }

        head = head->next;
    }

    if (bigLast != NULL)
        bigLast->next = NULL;

    if (smallHead == NULL)
    {
        if (equalHead == NULL)
            return bigHead;

        equalLast->next = bigHead;
        return equalHead;
    }

    if (equalHead == NULL)
    {
        smallLast->next = bigHead;
        return bigHead;
    }

    smallLast->next = equalHead;
    equalLast->next = bigHead;

    return smallHead;
}

int main()
{
}