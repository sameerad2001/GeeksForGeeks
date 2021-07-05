#include <iostream>
#include <unordered_map>

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

// Segment Fault ______________________________________________________________
// Root at i ==> Children at {2i, 2i + 1}
void convert(Node *head, TreeNode *&root)
{
    Node *temp = head;
    int n = 0;
    while (temp)
        n++, temp = temp->next;

    int *arr = new int(n + 1);

    arr[0] = 0;
    temp = head;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = temp->data;
        temp = temp->next;
    }

    if (n == 0)
        return;

    //_____________________________________Create Binary Tree
    unordered_map<int, TreeNode *> map;
    root->data = arr[1];

    if (n < 1)
        return;
    root->left = new TreeNode(arr[2]);

    if (n < 2)
        return;
    root->right = new TreeNode(arr[3]);

    map[2] = root->left;
    map[3] = root->right;

    int curr_index = 2;
    while (2 * curr_index < n + 1)
    {
        map[curr_index]->left = new TreeNode(arr[2 * curr_index]);
        map[2 * curr_index] = map[curr_index]->left;

        if (2 * curr_index + 1 >= n + 1)
            break;

        map[curr_index]->right = new TreeNode(arr[2 * curr_index + 1]);
        map[2 * curr_index + 1] = map[curr_index]->right;

        curr_index++;
    }
}

int main()
{
}