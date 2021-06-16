#include <iostream>
#include <vector>

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

void left_view_utl(Node *root, int &max_level, int curr_level, vector<int> &res)
{
    // Base Case
    // ALSO If left is NULL then the max level is not set and the right Node is pushed into res
    if (root == NULL)
        return;

    if (max_level < curr_level)
    {
        max_level = curr_level;
        res.push_back(root->data);
    }

    // First Left then Right
    left_view_utl(root->left, max_level, curr_level + 1, res);
    left_view_utl(root->right, max_level, curr_level + 1, res);
}

vector<int> leftView(Node *root)
{
    vector<int> res;
    int max_level = 0;  // Before Root
    int curr_level = 1; // Root is at level 1

    left_view_utl(root, max_level, curr_level, res);

    return res;
}

int main()
{
}