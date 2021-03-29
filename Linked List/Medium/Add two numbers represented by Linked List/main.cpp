#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

Node *addSameSize(Node *head1, Node *head2, int *carry)
{

    if (head1->next == NULL && head2->next == NULL)
    {
        int sum = head1->data + head2->data + *carry;
        Node *temp = new Node(sum % 10);
        *carry = sum / 10;
        return temp;
    }

    Node *temp = addSameSize(head1->next, head2->next, carry);

    int sum = head1->data + head2->data + *carry;
    *carry = sum / 10;

    Node *head = new Node(sum % 10);
    head->next = temp;
    return head;
}

void addCarryToRemaining(Node *head1, Node *curr, int *carry, Node **result)
{

    if (head1 == curr)
        return;

    addCarryToRemaining(head1->next, curr, carry, result);

    int sum = head1->data + *carry;

    push(result, sum % 10);

    *carry = sum / 10;
}

int main()
{
}
