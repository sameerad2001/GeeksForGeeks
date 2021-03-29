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

// void reorderList(Node *head)
// {
//     Node *current = head, *last, *prevLast;

//     while (current->next != NULL)
//     {
//         last = head;
//         while (last->next != NULL)
//         {
//             prevLast = last;
//             last = last->next;
//         }
//         prevLast->next = NULL;
//         last->next = current->next;
//         current->next = last;

//         if (current->next->next == NULL)
//             break;

//         current = current->next->next;
//     }
// }

void reorderList(Node *head)
{
    // 1. Middle point in the link list
    Node *fast, *slow;
    fast = slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Split Linked Lists
    Node *head1 = head;
    Node *head2 = slow->next;
    slow->next = NULL;

    // 3. Reverse Second Linked List
    Node *previous = NULL, *current = NULL, *next = head2;

    while (next != NULL)
    {
        current = next;
        next = next->next;
        current->next = previous;
        previous = current;
    }

    head2 = current;

    // 4. Alternately Merge first and second linked lists

    head = new Node(0); //Dummy Node; Will be removed later

    current = head;

    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL)
        {
            current->next = head1;
            current = current->next;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            current->next = head2;
            current = current->next;
            head2 = head->next;
        }
    }

    Node *temp = head; //Remove Dummy Node
    head = head->next;
    delete temp;
}

int main()
{
}