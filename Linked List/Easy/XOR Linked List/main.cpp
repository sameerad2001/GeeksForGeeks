#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    struct Node *npx;

    Node(int x)
    {
        data = x;
        npx = NULL;
    }
};

struct Node *XOR(struct Node *a, struct Node *b)
{
    return (struct Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

struct Node *insert(struct Node *head, int data)
{
    Node *temp = new Node(data);
    temp->npx = XOR(NULL, head); // Begining

    if (head != NULL)
    {
        // old head's prev = NULL
        // head -> npx = next ^ prev
        // next = head->npx ^ prev
        // next = next ^ prev ^ prev
        Node *old_head_next = XOR(NULL, head->npx);
        head->npx = XOR(temp, old_head_next);
    }

    head = temp;
}

vector<int> printList(struct Node *head)
{
    vector<int> res;

    Node *curr = head, *prev = NULL, *next;

    while (curr != NULL)
    {
        res.push_back(curr->data);
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }

    return res;
}

int main() {}