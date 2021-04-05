// WRONG APPROACH solution NOT accepted

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *arb;

    Node(int x)
    {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

Node *copyList(Node *head)
{
    Node *newHead = new Node(-1); // dummy head;
    *(newHead) = *(head);
    return newHead;
}

int main()
{
}