#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;

    // Only ONE of the args is NULL not both because we have the above if statement to handle that case
    if (r1 == NULL || r2 == NULL)
        return false;

    if (r1->data == r2->data)
        return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);

    return false;
}

int main()
{
}