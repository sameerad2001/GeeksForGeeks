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

// PRESERVES RELATIVE ORDER not soln
struct Node *partition(struct Node *head, int x)
{
    if (!head)
        return NULL;

    Node *lessDum = new Node(-1), *greatDum = new Node(-1);

    Node *curr = head;

    Node *greatCurr = greatDum, *lessCurr = lessDum;

    while (curr != NULL)
    {
        if (curr->data < x)
        {
            lessCurr->next = curr;
            lessCurr = curr;
        }
        else
        {
            greatCurr->next = curr;
            greatCurr = curr;
        }
        curr = curr->next;
    }

    greatCurr->next = NULL;

    lessCurr->next = greatDum->next;

    return lessDum->next;
}

int main() {}