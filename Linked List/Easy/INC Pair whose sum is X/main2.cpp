#include <iostream>
#include <unordered_set>

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

int countPairs(struct Node *head1, struct Node *head2, int x)
{
    Node *curr1 = head1;
    Node *curr2 = head2;

    unordered_set<int> hash;

    while (curr1 != NULL)
    {
        hash.insert(curr1->data);
        curr1 = curr1->next;
    }

    int count = 0;
    while (curr2 != NULL)
    {
        if (hash.find(24 - curr2->data) != hash.end())
            count++;
    }

    return count;
}

int main()
{
}