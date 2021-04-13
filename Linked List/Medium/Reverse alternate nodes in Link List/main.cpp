#include <iostream>

using namespace std;

// NOT WORKING :
// forgot to reverse the even list
// reverse from count/2 + 2 till end

// main 2 is better, easier and more efficient

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

void rearrange(struct Node *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return;

    Node *curr, *end;
    curr = end = head;
    int count = 1;

    while (end->next != NULL)
        end = end->next, count++;

    count = count % 2 == 0 ? count / 2 : (count / 2) + 1;

    while (count--)
    {
        Node *temp = curr->next;

        end->next = temp;
        curr->next = temp->next;
        temp->next = NULL;

        end = end->next;
        curr = curr->next;
    }
}

int main()
{
}