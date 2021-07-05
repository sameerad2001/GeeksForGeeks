#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *random;

    Node(int data)
    {
        this->data = data;
        left = right = random = NULL;
    }
};

Node *build_tree(Node *original, unordered_map<Node *, Node *> &original_copy_map)
{
    if (original == NULL)
        return NULL;

    Node *copy = new Node(original->data);

    // MAP [Original] = copy
    original_copy_map[original] = copy;

    copy->left = build_tree(original->left, original_copy_map);
    copy->right = build_tree(original->right, original_copy_map);
}

void connect_randoms(Node *original, unordered_map<Node *, Node *> &original_copy_map)
{
    if (original == NULL)
        return;

    // MAP[original] gives copy
    // copy -> random = copy of [original's random]
    original_copy_map[original]->random = original_copy_map[original->random];

    connect_randoms(original->left, original_copy_map);
    connect_randoms(original->right, original_copy_map);
}

Node *cloneTree(Node *tree)
{
    if (tree == NULL)
        return NULL;

    // MAP       < original, copy >
    unordered_map<Node *, Node *> original_copy_map;
    // Build the binary tree without the random pointers
    Node *new_root = build_tree(tree, original_copy_map);
    // Connect the random pointers
    connect_randoms(tree, original_copy_map);

    return new_root;
}

int main()
{
}