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
    Node *head, *curr = NULL, *prev;

    while (p1 && p2)
    {
        int sum = 0;
        if (p1->pow > p2->pow)
            sum = p1->coeff, p1 = p1->next;
        else if (p1->pow < p2->pow)
            sum = p2->coeff, p2 = p2->next;
        else
            sum = p1->coeff + p2->coeff, p2 = p2->next, p1 = p1->next;

        if (curr == NULL)
            head = prev = curr = new Node(sum, p1->pow > p2->pow ? p1->pow : p2->pow);

        else
        {
            curr = new Node(sum, p1->pow > p2->pow ? p1->pow : p2->pow);
            prev->next = curr;
            prev = curr;
        }
    }

    while (p1)
    {
        curr = new Node(p1->coeff, p1->pow);
        prev->next = curr;
        prev = curr;
        p1 = p1->next;
    }

    while (p2)
    {
        curr = new Node(p2->coeff, p2->pow);
        prev->next = curr;
        prev = curr;
        p2 = p2->next;
    }

    return head;
}