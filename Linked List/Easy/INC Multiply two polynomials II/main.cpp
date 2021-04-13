#include <iostream>

using namespace std;

// No CPP compiler

struct Node
{
    int data, exp;
    Node *next;

    Node(int coeff, int exp)
    {
        this->exp = exp;
        data = coeff;
        next = NULL;
    }
};

struct Poly
{
    Node *head;

    Poly()
    {
        head = NULL;
    }
};

Poly *multiply(Poly *p1, Poly *p2)
{
    Node *curr = p1->head; // first element of first poly
    int count = 0;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }

    curr = p1->head;

    count = 0;

    while (curr != NULL)
    {

        Node *res_curr = res[count]->head;
        Node *p2_curr = p2->head;

        while (p2_curr != NULL)
        {

            p2_curr = p2_curr->next;
        }

        curr = curr->next;
        count++;
    }
}

int main()
{
    Poly *p1, *p2;

    p1 = new Poly();
    p2 = new Poly();

    p1->head = new Node(1, 0);
    p1->head->next = new Node(3, 2);
    p1->head->next->next = new Node(2, 3);

    p2->head = new Node(2, 0);
    p2->head->next = new Node(4, 2);

    Poly *res = multiply(p1, p2);
}