#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void get_level_utl(Node *node, int target, int &target_level, int curr_level)
{
    if (node == NULL)
        return;

    if (node->data == target)
    {
        target_level = curr_level;
        return;
    }

    get_level_utl(node->left, target, target_level, curr_level + 1);
    get_level_utl(node->right, target, target_level, curr_level + 1);
}

int getLevel(Node *node, int target)
{
    int target_level = 0;

    get_level_utl(node, target, target_level, 1);

    return target_level;
}

int main()
{
}