#include <iostream>
#include <queue>

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
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Root at i ==> Children at {2i + 1, 2i + 2} INCLUDING the '0' index
void convert(Node *head, TreeNode *&root)
{
    queue<TreeNode *> q;
    root = new TreeNode(head->data);
    q.push(root);
    head = head->next;

    while (head)
    {
        TreeNode *temp = q.front();
        q.pop();

        temp->left = new TreeNode(head->data);
        q.push(temp->left);
        head = head->next;

        if (!head)
            break;

        temp->right = new TreeNode(head->data);
        q.push(temp->right);
        head = head->next;
    }
}

int main()
{
}