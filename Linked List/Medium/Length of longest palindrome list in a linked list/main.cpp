// Reference : https://www.youtube.com/watch?v=nLAnmS4n48I

// List1 -> List2
// reverse List1
// check for all common elements in List 1 and 2

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

int how_many_incommon(Node *head1, Node *head2)
{
    int common_elements = 0;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data != head2->data)
            break;

        common_elements++;

        head1 = head1->next;
        head2 = head2->next;
    }

    return common_elements;
}

int maxPalindrome(Node *head)
{
    if (head == NULL)
        return 0;

    if (head->next == NULL)
        return 1;

    Node *curr = head;
    Node *next, *prev = NULL;

    int res = 1;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        int common_elements = 2 * how_many_incommon(prev, next) + 1;
        res = res > common_elements ? res : common_elements;

        common_elements = 2 * how_many_incommon(curr, next);
        res = res > common_elements ? res : common_elements;

        prev = curr;
        curr = next;
    }

    return res;
}

int main()
{
}