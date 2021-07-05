#include <iostream>
#include <queue>

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
        return NULL;

    if (root->data == key)
        return NULL;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        bool key_found = false;
        // IMPORTANT : queue will grow so calc size only once PER LEVEL
        int starting_size = q.size();

        for (int i = 0; i < starting_size; i++)
        {
            Node *curr_node = q.front();

            if (curr_node->left)
            {
                // If key was found LAST Iteration or to it's LEFT
                // This is the right node : on the SAME LEVEL
                if (key_found)
                    return curr_node->left;

                if (curr_node->left->data == key)
                    key_found = true;

                q.push(curr_node->left);
            }
            if (curr_node->right)
            {
                // If key was found LAST Iteration or to it's LEFT
                // This is the right node : on the SAME LEVEL
                if (key_found)
                    return curr_node->right;

                if (curr_node->right->data == key)
                    key_found = true;

                q.push(curr_node->right);
            }

            q.pop();
        }

        // If key was found but had no right siblings
        if (key_found)
            return NULL;
    }

    return NULL;
}

int main()
{
}