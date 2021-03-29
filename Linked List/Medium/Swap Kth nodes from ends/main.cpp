#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *swapkthnode(Node *head, int num, int K)
{
    if (K > num)
        return head;

    if (2 * K == num + 1)
        return head;

    Node *firstPrev = head, *firstCurr = head;

    Node *secondPrev = head, *secondCurr = head;

    int i = 1;
    while (i != K)
    {
        firstPrev = firstCurr;
        firstCurr = firstCurr->next;
        i++;
    }

    i = 1;
    while (i != num - K + 1)
    {
        secondPrev = secondCurr;
        secondCurr = secondCurr->next;
        i++;
    }

    if (firstPrev)
    {
        firstPrev->next = secondCurr;
    }

    if (secondPrev)
        secondPrev->next = firstCurr;

    Node *temp = firstCurr->next;
    firstCurr->next = secondCurr->next;
    secondCurr->next = temp;

    if (K == 0)
        head = firstCurr;

    if (K == num)
        head = secondCurr;

    return head;
}

int main()
{
}