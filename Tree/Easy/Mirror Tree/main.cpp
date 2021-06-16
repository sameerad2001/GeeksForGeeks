#include <iostream>

using namespace std;

// Tree Node
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

void mirror(Node *node)
{
    if (node == NULL)
        return;

    mirror(node->left);
    mirror(node->right);

    Node *temp = node->right;
    node->left = node->right;
    node->right = temp;
}

int main() {}