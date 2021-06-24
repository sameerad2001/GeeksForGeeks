#include <iostream>

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

class Solution
{
public:
    void height_utl(Node *node, int curr_height, int &max_height)
    {
        if (node == NULL)
        {
            max_height = max_height < curr_height ? curr_height : max_height;
            return;
        }

        height_utl(node->left, curr_height + 1, max_height);
        height_utl(node->right, curr_height + 1, max_height);
    }

    int height(struct Node *node)
    {
        int max_height = 0;
        height_utl(node, 0, max_height);

        return max_height;
    }
};

int main()
{
}