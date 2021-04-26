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
bool isPalindrome(Node *head)
{
    if (head == NULL)
        return false;

    if (head->next == NULL)
        return true;

    if (head->next->next == NULL)
    {
        if (head->data == head->next->data)
            return true;

        return false;
    }

    Node *fast, *slow;
    fast = slow = head;
    Node *prev_slow = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    Node *head1 = head;
    Node *head2 = prev_slow->next;
    prev_slow->next = NULL;

    Node *prev = NULL, *curr = NULL, *next = head2;

    while (next != NULL)
    {
        curr = next;
        next = next->next;
        curr->next = prev;
        prev = curr;
    }
    head2 = curr;

    bool is_palindrome = true;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data != head2->data)
            is_palindrome = false;

        head1 = head1->next;
        head2 = head2->next;
    }

    // if ((head1 == NULL && head2 != NULL) || (head1 != NULL && head2 == NULL))
    //     is_palindrome = false;

    return is_palindrome;
}