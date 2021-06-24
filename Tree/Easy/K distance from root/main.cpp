#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void k_distance_utl(Node *root, int k, vector<int> &res, int distance)
{
    if (root == NULL)
        return;

    if (distance == k)
    {
        res.push_back(root->data);
        return;
    }

    k_distance_utl(root->left, k, res, distance + 1);
    k_distance_utl(root->right, k, res, distance + 1);
}

vector<int> Kdistance(struct Node *root, int k)
{
    vector<int> res;
    if (root == NULL)
        return res;

    k_distance_utl(root, k, res, 0);
    return res;
}

int main() {}