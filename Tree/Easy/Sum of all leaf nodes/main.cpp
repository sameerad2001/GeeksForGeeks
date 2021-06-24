#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void sum_leaf_utl(Node *node, int &sum)
{
    if (node == NULL)
        return;

    // If leaf add the curr data to sum
    if (!node->left && !node->right)
        sum += node->data;

    sum_leaf_utl(node->left, sum);
    sum_leaf_utl(node->right, sum);
}

int sumLeaf(Node *root)
{
    int sum = 0;
    sum_leaf_utl(root, sum);
    return sum;
}

int main()
{
}