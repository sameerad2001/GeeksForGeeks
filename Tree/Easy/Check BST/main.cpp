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

// VERY VERY VERY    W R O N G
bool isBST(Node *root)
{
    if (root == NULL)
        return true;

    int root_left_data = root->left ? root->left->data : INT_MAX;
    int root_right_data = root->right ? root->right->data : INT_MIN;

    if (root_left_data > root_right_data && root_left_data > root->data && root_right_data <= root->data)
    {
        return isBST(root->left) && isBST(root->right);
    }

    return false;
}

int main()
{
}