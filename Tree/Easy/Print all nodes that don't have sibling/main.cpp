#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void no_sibling_utl(Node *node, vector<int> &res)
{
    if (node == NULL)
        return;

    if (node->left && !node->right)
    {
        res.push_back(node->left->data);
    }
    else if (!node->left && node->right)
    {
        res.push_back(node->right->data);
    }

    no_sibling_utl(node->left, res);
    no_sibling_utl(node->right, res);
}

vector<int> noSibling(Node *node)
{
    vector<int> res;
    no_sibling_utl(node, res);

    sort(res.begin(), res.end());

    if (res.empty())
        res.push_back(-1);

    return res;
}

int main()
{
}