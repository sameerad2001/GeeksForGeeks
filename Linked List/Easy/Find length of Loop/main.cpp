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

int countNodesinLoop(struct Node *head)
{
    Node *fast, *slow;

    if (!head)
        return 0;

    fast = slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;

        fast = fast->next->next;

        if (fast == slow)
            break;
    }

    if (fast == NULL || fast->next == NULL)
        return 0;

    int count = 0;
    do
    {
        fast = fast->next;
        count++;
    } while (fast != slow);

    return count;
}

int main() {}