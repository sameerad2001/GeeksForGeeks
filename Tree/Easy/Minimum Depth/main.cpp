#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int minDepth(Node *root)
{
    if (root == NULL)
        return 0;

    int left_min = minDepth(root->left);
    int right_min = minDepth(root->right);

    // if one of the "minimums" is 0 => null node => consider the result of the other node instead
    int res = (left_min != 0 && right_min != 0) ? min(right_min, left_min) : max(right_min, left_min);
    return res + 1;
}

int main()
{
}