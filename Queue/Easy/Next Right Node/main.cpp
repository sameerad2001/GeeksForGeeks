#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *nextRight(Node *root, int key)
{
    if (root == NULL)
    {
        return new Node(-1);
    }

    if (root->left && root->left->data == key)
        return root->right ? root->right : new Node(-1);

    Node *res_1 = nextRight(root->left, key);
    Node *res_2 = nextRight(root->right, key);

    return res_1->data == -1 ? res_2 : res_1;
}

int main()
{
}