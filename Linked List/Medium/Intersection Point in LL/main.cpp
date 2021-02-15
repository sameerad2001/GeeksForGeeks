#include <iostream>
// #include <stack>

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

int getLength(Node *head)
{
    Node *temp = head;
    int count = 0;

    while (temp->next)
    {
        temp = temp->next,
        count++;
    }

    return count;
}

int intersectPoint(Node *head1, Node *head2)
{

    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int diff = abs(len1 - len2);

    Node *temp1 = len1 >= len2 ? head1 : head2;
    Node *temp2 = len1 < len2 && len1 != len2 ? head1 : head2;

    for (int i = 0; i < diff; i++)
    {
        temp1 = temp1->next;
    }

    while (temp1 && temp2)
    {
        if (temp1 == temp2)
            return temp1->data;

        temp1 = temp1->next, temp2 = temp2->next;
    }

    return -1;
}

// Time INEFFICIENT
// int intersectPoint(Node *head1, Node *head2)
// {
//     if (!head1 || !head2)
//         return -1;

//     Node *temp1 = head1, *temp2 = head2;

//     while (temp1 != temp2)
//     {
//         temp1 = temp1 ? temp1->next : head1;
//         temp2 = temp2 ? temp2->next : head2;
//     }

//     return temp1->data;
// }

// Only for POSITIVE numbers
// int intersectPoint(Node *head1, Node *head2)
// {
//     Node *temp1 = head1, *temp2 = head2;

//     while (temp1->next != NULL)
//     {
//         temp1->data *= -1;
//         temp1 = temp1->next;
//     }

//     while (temp2->next)
//     {
//         temp2->data *= -1;
//         temp2 = temp2->next;
//     }

//     temp1 = head1, temp2 = head2;

//     while (temp1 && temp2)
//     {
//         if (temp1 > 0)
//             return temp1->data;

//         if (temp2 > 0)
//             return temp2->data;

//         temp1 = temp1->next,
//         temp2 = temp2->next;
//     }

//     return -1;
// }

int main()
{
}