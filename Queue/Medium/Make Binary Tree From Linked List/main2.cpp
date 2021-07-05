#include <iostream>
#include <vector>

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
    vector<TreeNode *> vec;

    while (head)
    {
        vec.push_back(new TreeNode(head->data));
        head = head->next;
    }
    root = vec[0];

    int n = vec.size();
    int curr_index = 0;
    while (curr_index < n / 2)
    {
        if (curr_index * 2 + 1 < n)
            vec[curr_index]->left = vec[curr_index * 2 + 1];

        if (curr_index * 2 + 2 < n)
            vec[curr_index]->right = vec[curr_index * 2 + 2];

        curr_index++;
    }
}

int main()
{
}