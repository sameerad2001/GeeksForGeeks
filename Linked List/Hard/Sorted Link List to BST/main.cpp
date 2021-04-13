// Explanation https://www.youtube.com/watch?v=-_1-0nDU5qc

#include <iostream>

using namespace std;

//Linked List
struct LNode
{
    int data;
    struct LNode *next;

    LNode(int x)
    {
        data = x;
        next = NULL;
    }
};

//Tree
struct TNode
{

    int data;
    struct TNode *left;
    struct TNode *right;
    TNode(int x)
    {
        data = x;
        left = right = NULL;
    }
};

LNode *find_mid(LNode *start, LNode *end)
{
    LNode *slow, *fast;
    slow = fast = start;

    while (fast != end && fast->next != end)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

TNode *balanced_bst(LNode *start, LNode *end)
{
    if (start == NULL || start == end)
        return NULL;

    LNode *mid = find_mid(start, end);

    TNode *curr = new TNode(mid->data);
    curr->left = balanced_bst(start, mid);
    curr->right = balanced_bst(mid->next, end);

    return curr;
}

TNode *sortedListToBST(LNode *head)
{
    if (head == NULL)
        return NULL;

    return balanced_bst(head, NULL);
}

int main()
{
}