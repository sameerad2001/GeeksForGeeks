#include <iostream>

using namespace std;

struct Node
{
    int coeff;
    int pow;
    struct Node *next;

    Node(int c, int p)
    {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

Node *addPolynomial(Node *p1, Node *p2)
{
    Node *head, *curr = new Node(0, 0);
    head = curr;

    while (p1 && p2)
    {
        if (p1->pow == p2->pow)
        {
            p1->coeff += p2->coeff;
            curr->next = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow)
        {
            curr->next = p1;
            p1 = p1->next;
        }
        else
        {
            curr->next = p2;
            p2 = p2->next;
        }

        curr = curr->next;
    }

    if (p1)
    {
        curr->next = p1;
    }

    if (p2)
    {
        curr->next = p2;
    }

    return head->next;
}

int main()
{
}