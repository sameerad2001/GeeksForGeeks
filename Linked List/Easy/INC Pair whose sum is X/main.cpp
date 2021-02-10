#include <iostream>
#include <forward_list>

using namespace std;

// Requires MERGE SORT

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
}

// int countPairs(struct Node *head1, struct Node *head2, int x)
// {
//     Node *temp1 = head1, *temp2;
//     int count = 0;

//     while (temp1)
//     {
//         temp2 = head2;
//         while (temp2)
//         {
//             if (temp1->data + temp2->data == x)
//                 count++;

//             temp2 = temp2->next;
//         }

//         temp1 = temp1->next;
//     }

//     return count;
// }

int countPairs(struct Node *head1, struct Node *head2, int x)
{
}

int main()
{
}