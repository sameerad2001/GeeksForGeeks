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

int isSumProperty(Node *root)
{
    // NULL Node or Leaf Node
    if (!root || (!root->left && !root->right))
        return 1;

    // One of the children does not follow parent = child_sum property
    if (!isSumProperty(root->left) || !isSumProperty(root->right))
        return 0;

    int sum_child = (root->left ? root->left->data : 0) + (root->right ? root->right->data : 0);
    return root->data == sum_child ? 1 : 0;
}

int main()
{
}