#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool isBST(Node *root, int minimum = INT_MIN, int maximum = INT_MAX)
{
    if (root == NULL)
        return true;

    if (root->data <= minimum || root->data >= maximum)
        return false;

    return isBST(root->right, minimum, root->data - 1) && isBST(root->left, root->data + 1, maximum);
}

int main()
{
}